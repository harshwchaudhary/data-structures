#include<iostream>
using namespace std;
int main()
{
  int A[10] = {3,6,8,8,10,12,15,15,15,20};
  int n=10;
  int i;
  int lastdupli = 0;
  for(i =0 ;i < n;i++){
    if(A[i]==A[i+1] && A[i]!=lastdupli){
      cout<<"Duplicates are : \n"<<A[i];
      lastdupli=A[i];
    }
  }
  return 0;
}
