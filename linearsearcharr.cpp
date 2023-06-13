#include <iostream>
using namespace std;

int linearsearch(int a[], int n, int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(x==a[i])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n,i;
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    cout<<"Enter the elements of the array :"<<endl;
    int a[n];
    for(i = 0; i<n; i++)
    {
        cin>>a[i];
    }
    int x;
    cout<<"Enter the element to be searched : ";
    cin>>x;
    i = linearsearch(a,n,x);
    if(i==-1)
    {
        cout<<"Element not present in the array"<<endl;
        return 0;
    }
    else
    {
        cout<<"Element is present at position "<<i+1<<endl;
    }
}