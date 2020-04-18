#include<iostream>
using namespace std;

void Insertion(int arr[],int n)
{
    int i,j,x;
    for(i=1;i<n;i++)
    {
        j = i-1;
        x = arr[i];
        while(j>-1 && arr[j] > x)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}

int main()
{
    int A[] = {11,13,7,2,6,9,4,5,10,3};
    int n = 10,i;

    Insertion(A,n);

    for(i = 0;i<n;i++){
        cout<<A[i]<<" ";
    }

    return 0;
}