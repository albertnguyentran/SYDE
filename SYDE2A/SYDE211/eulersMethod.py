# change this function accordingly
def function(x, y):
    return x ** 2 + y

def eulersMethod(steps, stepSize, y, x):
    cur = 0
    
    for step in range(steps):
        cur = y + stepSize * function(x, y)
        y = cur
        x += stepSize

    return cur

def main():
    steps = int(input('Steps: '))
    stepSize = float(input('Step size: '))
    initialY = int(input('Initial Condition Y: '))
    initialX = int(input('Initial Condition X: '))
    significantDigits = int(input('Significant Digits: '))
    
    estimate = eulersMethod(steps, stepSize, initialY, initialX)
    print(f'{estimate:.{significantDigits}f}')
if __name__ == "__main__":
    main()
