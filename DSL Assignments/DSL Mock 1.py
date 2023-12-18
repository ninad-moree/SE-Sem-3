''' 
    Name -    Ninad More
    Roll no - 21253
    Title -   A2 String Operations
'''

class stringoperations:
    def length(self,x):
        length=0
        for i in x:
            length=length+1
        return length
    
    def splittedstring(self,y):
        lista = []
        temp = ''
        for i in y:
            if i == " ":
                lista.append(temp)
                temp = ''
            else:
                temp = temp + i
        if temp:
            lista.append(temp)  
        return lista

    def longestlengthword(self,x):
        s=self.splittedstring(x)
        max1=str1.length(s[0])
        temp=x[0]
        for i in s:
            if str1.length(i)>max1:
                max1=str1.length(i)
                temp=i
        return temp

    def frequncey_char(self,str1):
        char =input("Enter the character:")
        counter=0
        for i in range(len(str1)):
            if char==str1[i]:
                counter=counter+1
        return counter

    def palindrome(self,str2):
        lenstr2=str1.length(str2)
        j=lenstr2-1
        t=0
        for i in range(int(lenstr2/2+1)):
            if str2[i]==str2[j]:
                t=1
            else:
                break
            j=j-1
        if t==1:
            r="It is palindrome"
        else:
            r="It is not in palindrome"
        return r

    def substring_index(self,str1):
        sub1=input("Enter the substring:")
        #sublen=str1.length(sub1)
        sublen=len(sub1)
        index=0
        j=0
        for i in range(len(str1)):
            if sub1[j]==str1[i]:
                j=j+1
                if j==sublen:
                    index=i-(sublen-1)
                    break
            else:
                j=0
        return index

    def word_occurence(self,listr):
        list0=self.splittedstring(listr)
        list1=set(list0)
        list2=list(list1)
        list3=[]
        list4=[]
        counter=0
        for i in range(str1.length(list2)):
            counter=0
            for j in range(str1.length(list0)):
                if list2[i]==list0[j]:
                    counter=counter+1
            list3=list2[i],counter
            list4.append(list3)
        return list4

str1 = stringoperations()

while(True):
    print("Menu")
    print("1. Longest Word")
    print("2. Occurence of a character")
    print("3. Palindrome")
    print("4. Index of substring")
    print("5. Occurence of words")
    print("6. Exit")

    choice=int(input("Enter your choice:"))

    if choice==1:
        string1=input("Enter your string:")
        print("Longest length word is:",str1.longestlengthword(string1))

    elif choice==2:
        string1=input("Enter your string:")
        print("Checking occurence of character:",str1.frequncey_char(string1))

    elif choice==3:
        string1=input("Enter your string:")
        print("Checking for palindrome:",str1.palindrome(string1))

    elif choice==4:
        string1=input("Enter your string:")
        print("Index of substring:",str1.substring_index(string1))

    elif choice==5:
        string1=input("Enter your string:")
        print("Ocurrence of each word:",str1.word_occurence(string1))

    elif choice==6:
        print("Exitting the code.....")
        break
    
    else:
        print("Invalid Choice")

'''
Output:
    String=this is ninad more is more
    1 . Longest word = ninad
    2 . Occurence of char = i occured 3 times
    3 . Palindrome = not a palindrome
    4 . Substring = substring 'ina' occured at index 9
    5 . Occurence of word = (this,1) (is,2) (ninad,1) (more,2)
'''