#here we use GUI to operate a ino code to light a LED at will with a specific timeframe


import PySimpleGUI as sg
import serial
import time

serial_port = 'COM4'  # Adjust this for your setup
ser = serial.Serial(serial_port, 9600, timeout=1)
time.sleep(2)  # Wait for the connection to establish

layout = [
    [sg.Text('How much time do you want the LED to light after you press the button? (use msec)'), sg.InputText()],
    [sg.Button('Ok'), sg.Button('Cancel')],
    [sg.Text('Arduino Status:'), sg.Text('', size=(15, 1), key='-STATUS-')]
]

window = sg.Window('LED Timer', layout)

while True:
    event, values = window.read(timeout=100)  # Add a timeout for periodic reading
    if event == sg.WIN_CLOSED or event == 'Cancel':
        break
    if event == 'Ok':
        try:
            timer_duration = int(values[0])
            ser.write(f"{timer_duration}\n".encode())
            print(f'Sent: {timer_duration}')
        except ValueError:
            sg.popup("Please enter a valid integer.")

    if ser.in_waiting > 0:
        status = ser.readline().decode('utf-8').strip()
        print(f'Received: {status}')
        window['-STATUS-'].update(status)  # Update GUI with received status

window.close()
ser.close()  # Close the serial port
