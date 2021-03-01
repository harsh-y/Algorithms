#include<iostream>
#include <cstdlib>

using namespace std;

int comp=0;

int partition (int arr[], int low, int high)
{
    int pivot = arr[high], temp;
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            comp++;
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int size;
    cout<<"Enter size of Array : ";
    cin>>size;
    int arr[size];
    for (int i=0;i<size;i++)
    {
        arr[i] = rand() % 100;
    }
    cout<<"\nArray : ";
    for(int i = 0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    quickSort(arr, 0, size-1);
    cout<<"\nNo. of comparisons = "<<comp;
    cout<<"\nSorted Array \n";
    for(int i = 0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    return(0);
}
