#include <iostream>
#include <cstdlib>
using namespace std;


int getMax(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
        {
            max = array[i];
        }
    return max;
}

void countingSort(int array[], int n, int place)
{
    const int max = 10;
    int output[n];
    int count[max];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[(array[i] / place) % 10]++;

    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    for (int i=n-1;i>=0;i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i<n; i++)
        array[i] = output[i];
}


void radixsort(int array[], int n)
{
    int max = getMax(array,n);

    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array,n, place);
}


int main()
{
    int size;
    cout<<" Enter size of the Array : ";
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++)
    {
        array[i]=rand() % 100;
    }
    cout<<"\nArray : ";
    for(int i = 0; i<size; i++)
    {
        cout<<array[i]<<" ";
    }

    radixsort(array, size);

    cout<<"\nSorted Array \n";
    for(int i = 0; i<size; i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
    }
