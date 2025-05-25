class String_Implementation:
    def length(str):
        count = 0
        for i in str:
            count = count + 1
        return count
    
    def split1(str):
        lista=[]
        temp=''
        for i in str:
            if(i == " "):
                lista.append(temp)
                temp=''
            else:
                temp=temp+i
        if(temp):
            lista.append(temp)
        return lista
    
    def longestword(str):
        longestword=""
        for i in str:
            if(st.length(i)>=st.length(longestword)):
                longestword = i
        return longestword
    
    def frequency_char(str,char):
        letters=0
        for i in str:
            if i==char:
                letters=letters+1
        return letters
    
    def palindrome(str):
        len2 = st.length(str)
        j=len2-1
        t=0
        for i in range(int(len2/2+1)):
            if str[i]==str[j]:
                t=1
            else:
                break
            j=j-1
        if t==1:
            r='Palindrome'
        else:
            r='Not Palindrome'
        return r
    
    def substring(str,substr):
        x=st.length(str)
        y=st.length(substr)
        if y==1:
            for i in range(x):
                if str[i] == substr:
                    return i
                return -1
        for i in range(x-y+1):
            for j in range(y):
                if str[i+j]!=substr[j]:
                    break
            if j+1 == y:
                return i
        return -1
    
    def freqWord(str):
        str2=st.split1(str)
        str1=[]
        for i in str2:
            if i not in str1:
                str1.append(i)
        print("Occurence of each word is:")
        for i in range(st.length(str1)):
            print("Freq of ", str1[i]," is ",str.count(str1[i]))
              
st = String_Implementation

while(True):
    print('MENU')
    print("1. Longest Word")
    print("2. Frequency of character")
    print("3. Palinrome")
    print("4. Index of substring")
    print("5. Frequncy of word")
    print("6. Exit")
    
    choice=int(input("Enter your choice:"))
    
    if choice == 1:
        str1=input("Enter your string:")
        str2=st.split1(str1)
        s=st.longestword(str2)
        print("Longest word in string is:",s)
        
    elif choice == 2:
        str1=input("Enter your string:")
        char=input("Enter any character:")
        s=st.frequency_char(str1,char)
        print("The character ",char," occurred",s," times")
        
    elif choice == 3:
        str1=input("Enter your string:")
        s=st.palindrome(str1)
        print(s)
        
    elif choice == 4:
        str1=input("Enter your string:")
        substr=input("Enter substring:")
        s=st.substring(str1,substr)
        print("Index of substring is:",s)
    
    elif choice == 5:
        str1=input("Enter your string:")
        s= st.freqWord(str1)
        print(s)
        
    elif choice == 6:
        print("Exitting the code")
        break
    
    else:
        print("Invalid input")