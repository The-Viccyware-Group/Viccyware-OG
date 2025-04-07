import matplotlib.pyplot as plt
from math import *

# Constants
CENTER = [34.7, -12.9]
RADIUS = 40.0
CLIFF = [20.4, 15.33]
CLIFF_THETA = -1.33 + pi

# Set up the plot
fig, ax = plt.subplots(figsize=(8, 8), subplot_kw={'aspect': 'equal'})
ax.set_xlim([-100.0, 100.0])
ax.set_ylim([-100.0, 100.0])

def plot_circle(center, radius, color='g'):
    """Plot a circle at the given center with the specified radius and color."""
    ax.plot(center[0], center[1], f'{color}+')
    circle = plt.Circle(center, radius, color=color, fill=False)
    ax.add_artist(circle)

def plot_cliff(cliff, cliff_theta):
    """Plot an arrow representing the cliff direction."""
    arrow_length = 5.0
    ax.arrow(cliff[0], cliff[1],
             arrow_length * cos(cliff_theta), arrow_length * sin(cliff_theta),
             head_width=2.0, head_length=2.0, color='b')

def plot_new_safe(center, radius, cliff, cliff_theta):
    """Calculate and plot the new safe position based on the cliff."""
    dx = center[0] - cliff[0]
    dy = center[1] - cliff[1]
    
    # Rotate coordinates
    rot_x = dx * cos(cliff_theta) - dy * sin(cliff_theta)
    rot_y = dx * sin(cliff_theta) + dy * cos(cliff_theta)
    
    # Calculate the operand for the quadratic formula
    operand = rot_y**2 - (rot_x**2 + rot_y**2 - radius**2)
    
    if operand < 0:
        print("ERROR: negative operand", operand)
        return
    
    sr = sqrt(operand)
    
    # Calculate potential shifts
    ans1 = -rot_y + sr
    ans2 = -rot_y - sr
    
    # Determine the positive shift distance
    shift_d = None
    if ans1 > 0 and ans2 > 0:
        shift_d = min(ans1, ans2)
    elif ans1 > 0:
        shift_d = ans1
    elif ans2 > 0:
        shift_d = ans2
    
    if shift_d is None:
        print("ERROR: no positive shift!", ans1, ans2)
        return

    print(shift_d)
    
    # Calculate new center
    new_center_x = center[0] - shift_d * cos(cliff_theta)
    new_center_y = center[1] - shift_d * sin(cliff_theta)

    plot_circle([new_center_x, new_center_y], radius, 'r')

# Plot the original circle and cliff
plot_circle(CENTER, RADIUS, 'g')
plot_cliff(CLIFF, CLIFF_THETA)

# Calculate and plot the new safe position
plot_new_safe(CENTER, RADIUS, CLIFF, CLIFF_THETA)

# Show the plot
plt.show()

# P-munchi
