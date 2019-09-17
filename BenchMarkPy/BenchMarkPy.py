import random
import pandas as pd
import numpy as np
import time
from datetime import datetime

def MatrixMultiplication(size):
    
    matrix = pd.DataFrame(np.random.randint(0,9,size=(size, size)))
    resultantMatrix = pd.DataFrame(np.random.randint(0,9,size=(size, size)))
    rangeSize = range(size);

    start = datetime.now()
    for i in rangeSize:
        for j in rangeSize:
            for k in rangeSize:
                resultantMatrix[i][j] += matrix[i][k] * matrix[k][j]
    end = datetime.now()
    print("Time for matrix of int of size " + str(size) + ", nested loop method:  " + str((end - start)) + " ms")

def MatrixMultiplicationNumpy(size):
    matrix = pd.DataFrame(np.random.randint(0,9,size=(size, size)))
    resultantMatrix = pd.DataFrame(np.random.randint(0,9,size=(size, size)))

    start = datetime.now()
    resultantMatrix = np.matmul(matrix, matrix)
    end = datetime.now()
    print("Time for matrix of int of size " + str(size) + ", numpy method:  " + str((end - start)))

def main():
    maxSize = 350
    for size in range(50, maxSize + 10, 50):
        MatrixMultiplicationNumpy(size)

    for size in range(50, maxSize + 10, 50):
        MatrixMultiplication(size)

if __name__ == "__main__":
    main()
