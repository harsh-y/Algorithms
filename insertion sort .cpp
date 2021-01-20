#include<iostream>
using namespace std;
int main()
{
    int arr[10];
    int i,j,n,temp,C=0;
    cout<<"Enter size of Array : ";
    cin>>n;
    cout<<"\nEnter elements of Array\n";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=1;i<n;i++)
        {
            j=i;
            C++;
            while((j>0) && (arr[j-1]>arr[j]))
                {
                    if(arr[j-1]>arr[j])
                    {
                        C++;
                    }
                    temp=arr[j - 1];
                    arr[j-1]=arr[j];
                    arr[j]=temp;
                    j--;
                }
        }
      cout<<"\nNo. of comparisons = "<<C;
      cout<<"\nSorted Array\n";
      for (i = 0; i < n; i++)
          cout<<"\n"<<arr[i];
      return 0;
}
