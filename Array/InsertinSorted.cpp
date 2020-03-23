#include<iostream>
using namespace std;

struct Array {
  int A[10];
  int size;
  int length;
};
void InsertSorted(struct Array *arr,int value){
  int i = arr->length-1;
  while(arr->A[i] > value){
    arr->A[i+1] = arr->A[i];
    i--;
  }
  arr->A[i+1] = value;
  arr->length++;
}



void Display(struct Array arr){
  cout<<"Elements are :\n ";
  for(int i=0;i<arr.length;i++)
  cout<<arr.A[i]<<"\t";
}
int main(){
  struct Array arr = {{4,6,7,9,11,13},10,6};
  int val;
  cout<<"Enter value to insert : \n";
  cin>>val;
  InsertSorted(&arr,val);
  Display(arr);
  return 0;
}
