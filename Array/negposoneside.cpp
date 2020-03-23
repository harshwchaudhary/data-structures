#include<iostream>
using namespace std;

struct Array {
  int A[10];
  int size;
  int length;
};
void OneSide(struct Array *arr){
  int i=0; // i is for +ve and j is for -veq
  int temp;
  int j = arr->length-1;
  while(i<j){
    while(arr->A[i]<0){
      i++;
    }
    while(arr->A[j]>=0){
      j--;
    }
    if(i<j){
      temp = arr->A[i];
      arr->A[i] = arr->A[j];
      arr->A[j] = temp;
    }
  }
}




void Display(struct Array arr){
  cout<<"Elements are :\n ";
  for(int i=0;i<arr.length;i++)
  cout<<arr.A[i]<<"\t";
}
int main(){
  struct Array arr = {{-4,6,-7,9,-11,13},10,6};
  OneSide(&arr);
  Display(arr);
}
