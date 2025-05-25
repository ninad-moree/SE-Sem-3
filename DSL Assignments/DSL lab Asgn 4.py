class Searches:
    def enter_students():
        global students_rollno,length,find_rollno
        students_rollno = []
        n = int(input("Enter how many students attended training program:"))
        for i in range(n):
            m = int(input("Enter roll no of students who attended training program:"))
            students_rollno.append(m)
        print(students_rollno)

        length = len(students_rollno)
        find_rollno = int(input("Enter any students roll number:"))
        students_rollno.append(find_rollno)

    def results(result):
        if result == -1:
            print("Student did not attend training program:")
        else:
            print("Student attended training program:")

# 1. Linear Search
    def Linear_Search(students, length, roll_no):
        countlinear=0
        for i in range(length):
            countlinear= countlinear+1
            if students[i] == roll_no:
                print("Students roll no found at index:",i)
                print("Number of comparisons done are:",countlinear)
                return roll_no
        return -1

# 2. Sentinal Search
    def Sentinel_Search(students, length, roll_no):
        end = students[length-1]
        students[length-1] = roll_no
        count=0
        countsentinal = 0

        while roll_no != students[count]:
            count += 1

        students[length - 1] = end

        if count < length - 1 or end == roll_no:
            print("Number of comparisons done are:",count+1)
            print("Students roll no found at index:",count)
            return countsentinal + 1
        else:
            return -1

# 3. Binary Search
    def Binary_Search(students, roll_no, start, end, countbinary):
        if start <= end:
            mid = int((start + end) / 2)
            if students[mid] == roll_no:
                countbinary=countbinary+1
                print("Students roll no found at index:",mid)
                print("Number of comparisons done are:",countbinary)
                return roll_no
            elif students[mid] > roll_no: 
                countbinary=countbinary+1
                return search.Binary_Search(students, roll_no, start, mid - 1, countbinary)
            else:
                countbinary=countbinary+1
                return search.Binary_Search(students, roll_no, mid+1, end, countbinary)
        else:
            return -1

# 4. Fibonacii Search
    def Fibonacii_Search(students, length, roll_no, countfibonacii):
        offset = -1
        f1 = 0
        f2 = 1
        f3 = f1 + f2
        while f3 < length:
            f1 = f2
            f2 = f3
            f3 = f1 + f2
        i = min((offset + f1),length-1)
        while f3 != 1:
            i = min((offset + f1),length-1)
            if students[i] == roll_no:
                countfibonacii+=1
                print("Number of comparisons done are:",countfibonacii)
                print("Roll number", roll_no, "found at index", i)
                return
            elif students[i] < roll_no:
                f3 = f2
                f2 = f1
                f1 = f3 - f2
                offset = i
                countfibonacii+=1

            else:
                f3 = f3 - f2
                f2 = f2 - f1
                f1 = f3 - f2
                countfibonacii+=1

        if roll_no == students[0]:
            countfibonacii+=1
            print("Number of comparisons done are:",countfibonacii)
            print("Roll number", roll_no, "found at index", 0)
            return
        if roll_no == students[length - 1]:
            countfibonacii+=1
            print("Number of comparisons done are:",countfibonacii)
            print("Roll number", roll_no, "found at index", length - 1)
            return    
            
        print("Roll number", roll_no , "did not attend the training program")
        return

search = Searches

while (True):
    print("Menu")
    print("1. Linear Search")
    print("2. Sentinel Search")
    print("3. Binary Search")
    print("4. Fibonacii Search")
    print("5. Exit")

    choice = int(input("Enter your choice:"))

    if choice == 1:
        search.enter_students()
        result = search.Linear_Search(students_rollno, length, find_rollno)
        search.results(result)
        print("# ======================================================================================================================")

    elif choice == 2:
        search.enter_students()
        result = search.Sentinel_Search(students_rollno, length, find_rollno)
        search.results(result)
        print("# ======================================================================================================================")


    elif choice == 3:
        print("Enter roll number of students in increasing order:")
        search.enter_students()
        result = search.Binary_Search(students_rollno, find_rollno, 0, len(students_rollno) - 1, countbinary=0)
        search.results(result)
        print("# ======================================================================================================================")

    elif choice == 4:
        print("Enter roll number of students in increasing order:")
        search.enter_students()
        search.Fibonacii_Search(students_rollno, length, find_rollno, countfibonacii=0)
        print("# ======================================================================================================================")

    elif choice == 5:
        print("Exiting the code.......")
        break

    else:
        print("Invalid Input")