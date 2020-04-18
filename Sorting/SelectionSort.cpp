#include<iostream>
using namespace std;

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SelectionSort(int A[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(A[j] < A[k])
                k = j;
        }
        swap(&A[i],&A[k]);
    }
}

int main()
{
    int A[] = {11,13,7,2,6,9,4,5,10,3},n=10,i;
    SelectionSort(A,n);
    for(int i = 0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<"\n";
    return 0;
}