#include<iostream>
using namespace std;

int main()
{
  int A[] = {6,7,8,9,10,11,13,14,15,16,17};
  int n = 12;
  int low = 6;
  int high = 17;
  int diff = low - 0;
  for(int i=0 ; i<n; i++){
    if(A[i]-i != diff){
      cout<<"Missing elements is : \n"<<i+diff;
      break;
    }
  }
  return 0 ;
}
