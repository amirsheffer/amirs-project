import numpy as np
import matplotlib.pyplot as plt

# Generate x values from 0 to 2π
x = np.linspace(0, 2 * np.pi, 100)
# Compute the sine of x
y = np.sin(x)

# Create the plot
plt.figure(figsize=(10, 5))
plt.plot(x, y, label='Sine Wave', color='blue')

# Adding title and labels
plt.title('Sine Wave')
plt.xlabel('X (radians)')
plt.ylabel('sin(X)')
plt.axhline(0, color='black',linewidth=0.5, ls='--')
plt.axvline(0, color='black',linewidth=0.5, ls='--')
plt.grid()
plt.legend()

# Show the plot
plt.show()




print("hello world")
