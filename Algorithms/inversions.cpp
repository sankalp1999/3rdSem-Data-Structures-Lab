#include<iostream>
#include<cstdio>

using namespace std;

long long ans=0;
void mergei(int a[],int i,int j)
{
    int mid=((i+j)/2)+1,high=j+1;
    int s=i;
    int * arr = new int [j-i+1];
    j=mid;
    int k=0;
    while(i<mid && j<high)
    {
        if(a[i]<=a[j])
        {
            arr[k]=a[i];
            i++;
        }
        else
        {
            arr[k]=a[j];
            ans+=(mid-i);
            j++;
        }
        k++;
    }
    for(;i<mid;i++,k++)
        arr[k]=a[i];
    for(;j<high;j++,k++)
        arr[k]=a[j];
    for(k=0;s<high;s++,k++)
        a[s]=arr[k];
    delete [] arr;
}

void m_sort(int a[],int i,int j)
{
    if(i<j)
    {
        m_sort(a,i,(i+j)/2);
        m_sort(a,((i+j)/2)+1,j);
        mergei(a,i,j);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        ans=0;
        scanf("%d",&n);
        int * a = new int[n];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        m_sort(a,0,n-1);
        cout<<ans<<endl;
    }
    return 0;
}
