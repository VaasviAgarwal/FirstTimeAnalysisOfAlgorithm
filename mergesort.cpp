#include <iostream>
using namespace std;

int count = 0;
void Merge(int *a, int l, int r, int mid)
{
    int i, j, k, temp[r-l+1];

    i = l;
    k = 0;
    j = mid + 1;
    while(i<=mid && j<=r)
    {
	count++;
        if(a[i]<a[j])
        {
            temp[k]  = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    while(j<=r)
    {
        temp[k] = a[j];
        k++;
        j++;
    }
    for(i = l; i<=r; i++)
    {
        a[i] = temp[i-l];
    }
}

void MergeSort(int *a, int l, int r)
{
    int mid = (l+r)/2;
    if (l < r)
    {
        MergeSort(a, l, mid);
        MergeSort(a, mid+1, r);
        Merge(a,l,r,mid);
    }
}
int main()
{
    int n, i;
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements : "<<endl;
    for(i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    MergeSort(arr, 0, n-1);
    cout<<"Sorted Array : ";
    for (i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    cout<<"Number of comparisons : "<<count<<endl;
    return 0;
}
