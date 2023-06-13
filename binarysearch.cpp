#include <iostream>
using namespace std;

int binarysearch(int a[], int s, int val)
{
    int l = 0;
    int h = s-1;
    int mid;
    int i;
    while(l<h)
    {
        mid = (h+l)/2;
        if(a[mid]<val)
        {
            l = mid+1;
        }
        else
        {
            h = mid;
        }
	if(a[mid]==val)
	{
	    return mid;
    	}
    }
    return -1;
}
int main()
{
    cout<<"Enter the number of elements in the array : ";
    int s;
    cin>>s;
    cout<<"Enter elements of the array in a sorted format :"<<endl;
    int a[s];
    int i;
    for(i=0;i<s;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the element to be searched : ";
    int x;
    cin>>x;
    int ans = binarysearch(a,s,x);
    if (ans==-1)
    {
        cout<<"Element not found in the array"<<endl;
    }
    else
    {
        cout<<"Element found at position "<<ans+1<<endl;
    }
    return 0;
}
