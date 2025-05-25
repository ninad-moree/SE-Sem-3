class Matrix_Operations:
    global matrix1st, matrix2nd, results

# First matrix
    def matrix1st():
        global  R1, C1, matrix1
        print("For 1st matrix:-")
        R1 = int(input("Enter number of rows of 1st matrix:"))
        C1 = int(input("Enter number of columns of 1st matrix:"))
        matrix1 = []

        print("Enter your entries row wise:")
        for i in range(R1):  # A for loop for row entries
            a = []
            for j in range(C1):  # A for loop for column entries
                a.append(int(input()))
            matrix1.append(a)

        print("First Matrix is:")
        for i in range(R1):
            for j in range(C1):
                print(matrix1[i][j], end="  ")
            print()
        print("=================================================")

# Second Matrix
    def matrix2nd():
        global R2, C2, matrix2
        print("For 2nd matrix:-")
        R2 = int(input("Enter number of rows of 2nd matrix:"))
        C2 = int(input("Enter number of columns of 2nd matrix:"))
        matrix2 = []

        print("Enter your entries row wise:")
        for i in range(R2):  # A for loop for row entries
            a = []
            for j in range(C2):  # A for loop for column entries
                a.append(int(input()))
            matrix2.append(a)

        print("Second Matrix is:")
        for i in range(R2):
            for j in range(C2):
                print(matrix2[i][j], end="  ")
            print()
        print("=================================================")

# Result matrix
    def results():
        global result
        print("For result matrix:-")
        R = int(input("Enter number of rows of result matrix:"))
        C = int(input("Enter number of columns of result matrix:"))
        result = []

        for i in range(R):
            a = []
            for j in range(C):
                a.append(0)
            result.append(a)

        print("result matrix is:")
        for i in range(R):
            for j in range(C):
                print(result[i][j], end="  ")
            print()
        print("=================================================")

# 1. Addition 
    def addition():
        matrix1st()
        matrix2nd()
        results()
        if R1 == R2 and C1 == C2:
            print("Addition is possible:")
            for i in range(len(matrix1)):
                for j in range(len(matrix1[0])):
                    result[i][j] = matrix1[i][j] + matrix2[i][j]

            print("Addition of matrices is:")
            for r in result:
                print(r)
        else:
            print("Matrices cannot be added")

# 2. Subtraction
    def subtraction():
        matrix1st()
        matrix2nd()
        results()
        if R1 == R2 and C1 == C2:
            print("Subtraction is possible:")
            for i in range(len(matrix1)):
                for j in range(len(matrix1[0])):
                    result[i][j] = matrix1[i][j] - matrix2[i][j]

            print("Subtraction of matrices is:")
            for r in result:
                print(r)
        else:
            print("Matrices cannot be subtracted")

# 3. Multiplication
    def multiplication():
        matrix1st()
        matrix2nd()
        results()
        if R1 == C2:
            print("Multiplication can be done:")
            for i in range(R1):
                for j in range(C2):
                    for k in range(C1):
                        result[i][j] += matrix1[i][k] * matrix2[k][j]

            print("Multiplication of matrices is:")
            for r in result:
                print(r)

        else:
            print('Matrices cannot be multiplied')

# 4. Transpose
    def transpose():
        print("For finding transpose:-")
        matrix1st()
        results()
        for i in range(len(matrix1)):
            for j in range(len(matrix1[0])):
                result[j][i] = matrix1[i][j]
        for r in result:
            print(r)

matrixobj = Matrix_Operations

while (True):
    print("Menu")
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Transpose")
    print("5. Exit")

    choice = int(input("Enter your choice:"))

    if choice == 1:
        matrixobj.addition()
        print("==========================================================================")

    elif choice == 2:
        matrixobj.subtraction()
        print("==========================================================================")

    elif choice == 3:
        matrixobj.multiplication()
        print("==========================================================================")

    elif choice == 4:
        matrixobj.transpose()
        print("==========================================================================")

    elif choice == 5:
        print("Exiting the code......")
        break

    else:
        print("Invalid Input")
        print("==========================================================================")