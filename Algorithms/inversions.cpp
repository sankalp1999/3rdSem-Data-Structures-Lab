#include <iostream>
using namespace std;

int temp[100000];

long int join(int s[], int left, int mid, int right)
{
    long int shift=0;
    int i=left, j=mid, k=left;
    while(i<mid && j<=right)
    {
        if(s[i] <= s[j]){
            temp[k]=s[i];
            k++, i++;
        }
        else{
            temp[k]=s[j];
            k++, j++;
            shift += mid-i;
        }
    }
    while(i<mid){
        temp[k] = s[i];
        k++, i++;
    }
    
    while(j<=right){
        temp[k] = s[j];
        k++, j++;
    }
    
    while(left<=right){
        s[left] = temp[left];
        left++;
    }
    return shift;
}

long int mergeSort(int s[], int left, int right)
{
    long int shift = 0;
    if(left < right)
    {
        int mid = left + (right-left)/2;
        shift += mergeSort(s, left, mid);
        shift += mergeSort(s, mid+1, right);
        shift += join(s, left, mid+1, right);
    }
    return shift;
}

int main()
{
    int n, t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int s[n];
        for(int i=0; i<n; i++)
            cin >> s[i];
         
        long int shift = mergeSort(s, 0, n-1);
        
        cout << shift << endl;
    }
    return 0;
}
