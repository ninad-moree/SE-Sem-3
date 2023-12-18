''' Write a Python program to store second year percentage of students in array. Write
    function for sorting array of floating point numbers in ascending order using
    a) Insertion sort
    b) Shell Sort and display top five scores '''
    
class Sort:
    def Array():
        global array
        array = []
        n = int(input("Enter length of array:"))
        for i in range(n):
            m = int(input("Enter elements of the array:"))
            array.append(m)

    # 1. Insertion Sort
    def Insertion_Sort(array):
        for i in range(1, len(array)):
            key = array[i]
            j = i - 1
            while (j >= 0 and key < array[j]):
                array[j + 1] = array[j]
                j = j - 1
            array[j + 1] = key

    # 2. Shell Sort
    def Shell_Sort(array, length):
        gap = length // 2
        while gap > 0:
            j = gap
            while j < length:
                i = j - gap  # so gap value is maintained
                while i >= 0:
                    if array[i + gap] > array[i]:  # rhs > lhs
                        break
                    else:
                        array[i + gap], array[i] = array[i], array[i + gap]  # swapping of elements
                    i = i - gap
                j += 1
            gap = gap // 2


    # 3. Shell sort using insertion sort
    def shell_w_insertion(array, length):
        gap = length//2
        while gap > 0:
            for i in range(length -gap):
                j=0
                while (j+gap < length):
                    if (array[j]> array[j+gap]):
                        sort.Insertion_Sort(array)
                    j=j+1
                gap = gap // 2

sort = Sort  # object of the class

while (True):
    print("Menu:")
    print("1. Insertion Sort")
    print("2. Shell Sort")
    print("3. Shell using insertion sort")
    print("4. Exit")

    choice = int(input("Enter your choice:"))

    if choice == 1:
        sort.Array()
        print("Array before sorting is:", array)
        sort.Insertion_Sort(array)
        print("Sorted array using insertion sort is:", array)
        print("# ======================================================================================================================")

    elif choice == 2:
        sort.Array()
        print("Array before sorting is:", array)
        size = len(array)
        sort.Shell_Sort(array, size)
        print("Sorted array using shell sort is:", array)
        print("# ======================================================================================================================")

    elif choice == 3:
        sort.Array()
        print("Array before sorting is:", array)
        size = len(array)
        sort.shell_w_insertion(array,size)
        print("Sorted array using shell+insertion sort is:", array)

    elif choice == 4:
        # cowsay.pig("Exitting the code......")
        print("Exiting the code......")
        break

    else:
        # cowsay.beavis("Enter different choice")
        print("Invalid input")