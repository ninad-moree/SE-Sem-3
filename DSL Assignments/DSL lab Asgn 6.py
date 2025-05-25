class Sorting:
    def Array():
        global array,n
        array = []
        n = int(input("Enter length of array:"))
        for i in range(n):
            m = int(input("Enter elements of the array:"))
            array.append(m)
        return n

    def Quick_Sort(array,low,high):
        if(low<high):
            m=sort.Partition(array,low,high)
            sort.Quick_Sort(array,low,m-1)
            sort.Quick_Sort(array,m+1,high)
    
    def Partition(array,low,high):
        pivot = array[low]
        i=low+1
        j=high
        flag = False
        while(not flag):
            while (i<=j and array[i]<=pivot):
                i=i+1
            while (i<=j and array[j]>=pivot):
                j=j-1
            
            if(j<i):
                flag=True
            else:
                temp = array[i]
                array[i] = array[j]
                array[j] = temp
                
        temp=array[low]
        array[low]=array[j]
        array[j]=temp
        return j
    
sort=Sorting

sort.Array()
print("Array before sorting is:",array,"",n)
sort.Quick_Sort(array,0,n-1)
print("Array after using quick sort is:",array)
print("Top five scores are:")
print({array[-1]},{array[-2]},{array[-3]},{array[-4]},{array[-5]})