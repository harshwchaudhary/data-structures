#include<iostream>
using namespace std;

int main()
{
  int A[] = {6,3,8,10,16,7,5,2,9,14};
  int i,j;
  int k;
  int n=10;
  cout<<"Enter k :\n";
  cin>>k;
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(A[i]+A[j]==k)
      cout<<A[i]<<" & "<<A[j]<<" equals "<<k<<endl;
    }
  }
  return 0;
}
