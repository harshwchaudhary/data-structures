#include<iostream>
#include<stdio.h>
using namespace std;

struct Array{
  int A[20];
  int size;
  int length;
};

void Insert(struct Array *arr,int index,int value){
  int i;
  if(index>=0 && index<=arr->length){
    for(i=arr->length;i>index;i--)
    arr->A[i] = arr->A[i-1];
    arr->A[index] = value;
  }
  arr->length++;
}
void Display( struct Array arr){
  cout<<"Elements entered are : ";
  for(int i=0;i<arr.length;i++)
  cout<<arr.A[i]<<"\t";
}


int main(){
  int n;
  cout<<"Enter the size of array : \n";
  cin>>n;
  int A[n];
  cout<<"Enter length of array : \n";
  int leng;
  cin>>leng;
  printf("Enter %d elements : \n",leng);
  for(int i=0;i<leng;i++)
  cin>>A[i];
  cout<<"Enter the value and its index : ";
  int value,index;
  cin>>index>>value;

  struct Array arr;
  for(int i=0;i<leng;i++)
  arr.A[i]=A[i];
  arr.size = n;
  arr.length = leng;
  Insert(&arr,index ,value);
  Display(arr);
  return 0;
}
