#include <iostream>
using namespace std;

int pass = 0;
int shift = 0;
int comp = 0;
void SelectionSort(int a[], int n)
{

    int i,j,x,temp;
    for(i=0;i<n-1;i++)
    {
	pass++;
        x = i;
        for(j=i+1;j<n;j++)
        {
	    comp++;
            if(a[x]>a[j])
            {
		shift++;
                x = j;
            }
        }
        temp = a[x];
        a[x] = a[i];
        a[i] = temp;
    }
    
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
    SelectionSort(arr, n);
    cout<<"Sorted array : ";
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

    cout<<"Number of Passes : "<<pass<<endl;
    cout<<"Number of Shifts : "<<shift<<endl;
    cout<<"Number of Comparisons : "<<comp<<endl;
    return 0;
}
