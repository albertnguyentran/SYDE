# change this function accordingly
def function(x, y):
    return 2*x - 1

def eulersMethod(steps, stepSize, y, x, significantDigits):
    cur = 0

    # Initial Condition
    print(f'k: 0  x: {x:{significantDigits}f}  y: {y:{significantDigits}f}')
    
    for step in range(steps):
        cur = y + stepSize * function(x, y)
        y = cur
        x += stepSize

        # y_k+1
        print(f'k: {step+1}  x: {x:{significantDigits}f}  y: {y:{significantDigits}f}')

    return cur

def main():
    steps = int(input('Steps: '))
    stepSize = float(input('Step size: '))
    initialY = int(input('Initial Condition Y: '))
    initialX = int(input('Initial Condition X: '))
    significantDigits = int(input('Significant Digits: '))
    
    estimate = eulersMethod(steps, stepSize, initialY, initialX, significantDigits)
    print(f'{estimate:.{significantDigits}f}')
if __name__ == "__main__":
    main()
