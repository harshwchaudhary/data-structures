#include<iostream>
using namespace std;
int main()
{
  int A[] = {1,3,4,5,6,8,9,10,12,14};
  int sm;
  int n = 10;
  int i=0,j=n-1;
  cout<<"Enter sum value : \n";
  cin>>sm;
  while(i<j){
    if(A[i]+A[j]==sm){
      cout<<A[i]<<" + "<<A[j]<<" = "<<sm<<endl;
      i+=1;
      j-=1;
    }
    else if (A[i]+A[j]<sm)
    i+=1;
    else
    j-=1;
  }
  return 0;
}
