#!/usr/bin/env python
def mergeSort(arr):
    if len(arr) == 1:
        return arr
    else:
        #list slicing
        #  >>> nums = [10, 20, 30, 40, 50, 60, 70, 80, 90]
        # >>> nums[:5]    
        # [10, 20, 30, 40, 50]

        a = arr[:len(arr)//2]
        b = arr[len(arr) // 2 :]
        a = mergeSort(a)
        b = mergeSort(b)
        c = []
        
        i = 0
        j = 0
    #  simple merge procedure 
        while i < len(a) and j < len(b):
            if (a[i] < b[j]):
                c.append(a[i])
                i = i + 1

            else:
                c.append(b[j])
                j = j + 1
        c += a[i:]
        c += b[j:]
    return c

if __name__ == "__main__":
    a = [100, 1000, 14, 20, 50131312]
    print(mergeSort(a))
