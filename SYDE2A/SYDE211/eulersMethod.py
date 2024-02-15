import plotext as plt
import math

# change this function accordingly
def function(x, y):
    return 12- 6*math.cos(math.pi*x)-(y/(5*x+90))

def eulersMethod(steps, stepSize, y, x, significantDigits):
    cur = 0

    x_points = []
    y_points = []
    
    # Initial Condition
    print(f'k: 0  x: {x:.{significantDigits}f}  y: {y:.{significantDigits}f}')
    
    for step in range(steps):
        cur = y + stepSize * function(x, y)
        y = cur
        x += stepSize

        x_points.append(float(f'{x}'))
        y_points.append(float(f'{y}'))
        
        # y_k+1
        print(f'k: {step+1}  x: {x:.{significantDigits}f}  y: {y:.{significantDigits}f}')
 
    # plt.doc.scatter()
    # plt.scatter(x_points, y_points)
    # plt.show()
    return cur

def main():
    steps = int(input('Steps: '))
    stepSize = float(input('Step size: '))
    initialY = float(input('Initial Condition Y: '))
    initialX = float(input('Initial Condition X: '))
    significantDigits = int(input('Significant Digits: '))
    
    estimate = eulersMethod(steps, stepSize, initialY, initialX, significantDigits)
    print(f'{estimate:.{significantDigits}f}')
if __name__ == "__main__":
    main()
