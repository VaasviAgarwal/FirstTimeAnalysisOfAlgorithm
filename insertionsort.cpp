#include <iostream>
using namespace std;

void InsertionSort(int a[], int n)
{
    int current;
    int j;
    int comp=0,shift=0,pass=0;
    for(int i =1; i<n;i++)
    {
        current = a[i];
        j = i-1;
	pass++;
	for(j=i-1;j>=0;j--)
	{
		comp++;
		if(a[j]>current)
		{
			a[j+1] = a[j];
			shift++;
			
		}
		else
		{
			break;
		}	
	}
	a[j+1]=current;
    }
    cout<<"Number of passes : "<<pass<<endl;
    cout<<"Number of shifts : "<<shift<<endl;
    cout<<"Number of comparisons : "<<comp<<endl;
}
int main()
{
    int n;
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    cout<<"Enter the elements of the array :"<<endl;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    InsertionSort(arr, n);
    cout<<"Sorted array : ";
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    return 0;
}
