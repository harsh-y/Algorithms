#include <iostream>
#include <cstdlib>

using namespace std;

int C = 0;

void heapify(int arr[], int n, int i)
{
    int largest=i;
    int left =2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]>arr[largest])
    {
        C++;
        largest=left;
    }

    if(right<n && arr[right]>arr[largest])
    {
        C++;
        largest=right;
    }

    if(largest!=i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr, n, i);
    }

    for (int i=n-1;i>=0;i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int size;
    cout<<"Enter size of Array : ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        arr[i]=rand() % 100;
    }
    cout<<"\nArray : ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    heapSort(arr, size);
    cout<<"\nNo. of comparisons = "<<C;
    cout<<"\nSorted Array \n";
    for (int i=0; i< size; i++)
    {
        cout<<arr[i]<<" " ;
    }

}
