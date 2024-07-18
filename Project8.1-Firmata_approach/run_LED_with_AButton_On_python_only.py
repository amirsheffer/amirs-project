import time
from pymata4 import pymata4
import threading
import PySimpleGUI as sg




LED_PIN = 4
Button_pin=2
timerTime = 0.1 # time in sec
CB_VALUE = 2
led_state = False
button_state = False


board = pymata4.Pymata4(com_port = "COM4")

def LED_OFF():
    global led_state
    board.digital_write(LED_PIN, 0)  # Turn LED off
    led_state = False



def LED_ON(data):
    global timerTime, led_state, button_state
    button_state = data[CB_VALUE] == 1  # Update button state

    if button_state:  # Button is pressed
        print("Button pressed!")
        board.digital_write(LED_PIN, 1)  # Turn LED on
        led_state = True
        timer = threading.Timer(timerTime, LED_OFF)
        timer.start()



def update_state():
    global led_state, button_state
    while True:
        if led_state and button_state:
            print('2')  # Both LED and button are on
        elif led_state:
            print('1')  # Only LED is on
        elif button_state:
            print('0')  # Button is pressed but LED is off
        else:
            print('0')  # Both are off
        time.sleep(1)  # Print state every 1 second



def set_timer_time():
    global timerTime
    layout = [
        [sg.Text("Enter Timer Duration (in seconds):")],
        [sg.InputText(default_text=str(timerTime))],
        [sg.Button("Submit"), sg.Button("Cancel")]
    ]

    window = sg.Window("Set Timer Duration", layout)

    while True:
        event, values = window.read()
        if event == sg.WINDOW_CLOSED or event == "Cancel":
            break
        if event == "Submit":
            try:
                timerTime = float(values[0])
                sg.popup(f"Timer set to {timerTime} seconds.")
            except ValueError:
                sg.popup("Please enter a valid number.")
    
    window.close()


    
# Start the state update thread
state_thread = threading.Thread(target=update_state, daemon=True)
state_thread.start()




board.set_pin_mode_digital_output(LED_PIN)
board.set_pin_mode_digital_input(Button_pin,callback=LED_ON)

set_timer_time()

