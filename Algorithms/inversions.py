#Counting inversions using merge sort
# https://medium.com/@ssbothwell/counting-inversions-with-merge-sort-4d9910dc95f0
#!/usr/bin/env python
import os, sys
   # if there is a larger number in list a
   # than list b[j] . then that contributes to count of inversions
   # a = [1,3,5]
   
   # b = [2,4,6] here, (3,2), (5,2) contribute to inversions.
   # 
def mergeSortInversions(arr):
    if len(arr) == 1:
        return arr, 0
    else:
        a = arr[:len(arr)//2]
        b = arr[len(arr)//2:]
        a, ai = mergeSortInversions(a)
        b, bi = mergeSortInversions(b)
        c = []
        i = 0
        j = 0
        inversions = 0 + ai + bi
  
    while i < len(a) and j < len(b):
        if a[i] <= b[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1
            inversions += (len(a) - i)
            
            
    c += a[i:]
    c += b[j:]
    return c, inversions
if __name__ == "__main__":
    arr = [9, 8, 7, 4, 2, 1]
    print(mergeSortInversions(arr))
    arr = [3, 2, 1]
    print(mergeSortInversions(arr))
    
