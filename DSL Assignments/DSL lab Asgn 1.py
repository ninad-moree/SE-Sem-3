# removing duplictes
def discard_Dup(lis):
    lis1 = []
    for x in lis:
        if x not in lis1:
            lis1.append(x)
    return lis1    

# intersection of lists
def intersection(list1,list2):
    list3 = []
    for i in range(len(list1)):
        for j in range(len(list2)):
            if list1[i] == list2[j]:
                list3.append(list1[i])
                break
            else:
                j=j+1
    return list3

# union of lists
def union(list1,list2):
    list3 = list1.copy()
    for x in list2:
        if x not in list3:
            list3.append(x)
    return list3

# difference of lists
def diff(list1,list2):
    list3 = []
    for x in list1:
        if x not in list2:
            list3.append(x)
    return list3

# symmetric diffference
def symdiff(list1,list2):
    list3 = []
    d1 = diff(list1,list2)
    d2 = diff(list2,list1)
    list3 = union(d1,d2)
    return list3
   
# Students who play both cricket and badminton
def CnB(list1,list2):
    list3 = intersection(list1,list2)
    print(list3)

# Students who play cricket and badminton but not both
def eCeB(list1,list2):
    list3 = symdiff(list1,list2)
    print(list3)
   
# Students who play neither cricket nor badmniotn are
def nCnB(list1,list2,list3):
    list4  = diff(list1,union(list2,list3))
    print(list4)
   
# Students who play cricket and football but not badminton
def CFnB(list1,list2,list3):
    list4 = diff(intersection(list1,list2),list3)
    print(list4)
   
class1 = [1,2,3,4,5,6,7,8,9,10]
print("Total students of the class are")
print(class1)

print("=========================================")

# Students playing cricket
listcricket = []
n=int(input("Enter how many students play cricket:"))
for i in range(n):
    m=int(input("Enter students playing cricket:"))
    listcricket.append(m)

print("==================")

print("Students playing cricket are:")
listcricket = discard_Dup(listcricket)
print(listcricket)

print("=========================================")

# Students playing football
listfootball = []
n=int(input("Enter how many students play football:"))
for i in range(n):
    m=int(input("Enter students playing football:"))
    listfootball.append(m)
   
print("==================")

print("Students playing football are:")
listfootball =discard_Dup(listfootball)
print(listfootball)

print("=========================================")

# Students playing badminton
listbadminton = []
n=int(input("Enter how many students play badminton:"))
for i in range(n):
    m=int(input("Enter students playing badminton:"))
    listbadminton.append(m)
   
print("==================")

print("Students playing badminton are:")
listbadminton = discard_Dup(listbadminton)
print(listbadminton)

print("=========================================")

while True:
    print("MENU")
    print("1.List of students who play both cricket and badminton")
    print("2.List of students who play either cricket or badminton but not both")
    print("3.List of students who play neither cricket nor badminotn")
    print("4.List of students who play cricket and football but not badminton")
    print("5.Exit")
   
    choice = int(input("Enter your choice:"))
   
    if choice == 1:
        print("students who play both cricket and badminton are:")
        CnB(listcricket,listbadminton)
       
    elif choice == 2:
        print("students who play either cricket or badminton but not both are:")
        eCeB(listcricket,listbadminton)
       
    elif choice == 3:
        print("students who play neither cricket nor badminotn are:")
        nCnB(class1,listcricket,listbadminton)
       
    elif choice == 4:
        print("students who play cricket and football but not badminton are:")
        CFnB(listcricket,listfootball,listbadminton)
       
    elif choice == 5:
        print("Exit the code")
        break