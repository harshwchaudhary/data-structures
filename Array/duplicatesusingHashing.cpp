#include<iostream>
using namespace std;

int main()
{
  int A[] = {3,6,8,8,10,12,15,15,15,20};
  int H[21] = {0};
  int i;
  int n=10;
  for(i=0;i<n;i++){
    H[A[i]]++;
  }
  for(i=0;i<=20;i++){
    if(H[i]>1)
    cout<<"Element "<<i<<" came : "<<H[i]<<" times"<<endl;
  }
  return 0;
}
