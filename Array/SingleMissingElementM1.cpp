#include<iostream>
using namespace std;

int main()
{
  int A[] = {1,2,3,4,5,6,8,9,10,11,12};
  int n=12;
  int Sum = (n*(n+1))/2;
  int s = 0;
  for(int i=0;i<11;i++){
    s = s + A[i];
  }
  cout<<"Missing elements is :\n"<<Sum-s;
  return 0;
}
