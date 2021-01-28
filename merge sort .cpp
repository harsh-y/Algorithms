#include<iostream>
#include <cstdlib>

using namespace std;

int  C=0;

int merge(int A [ ], int left, int mid, int right)
{
    int i=left;
    int j=mid+1;
    int k=left;
    int temp[right+1];
    while(i<=mid && j<=right)
    {
        if (A[i]<= A[j])
        {
            temp[k]=A[i];
            i++;
        }
        else
        {
            temp[k]=A[j];
            j++;
        }
        k++;
        C++;
    }
    while(i<=mid)
    {
        temp[k]=A[i];
        i++;
        k++;
    }
    while(j<=right)
    {
        temp[k]=A[j];
        j++;
        k++;
    }
    for(int l=left;l<=right;l++)
    {
        A[l]=temp[l];
    }
    return C;
}


int mergesort(int A[ ],int left,int right)
{
    int count;
    if(left<right)
    {
        int mid = (left+right)/2;
        mergesort(A,left,mid);
        mergesort(A,mid+1,right);
        count = merge(A,left,mid,right);
    }
    return count;
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
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    int comp=mergesort(arr, 0, size-1);
    cout<<"\nNo. of comparisons = "<< comp;
    cout<<"\nSorted Array \n";
    for (int i=0; i< size; i++)
    {
        cout<<arr[i]<<" " ;
    }
    return 0;
}
