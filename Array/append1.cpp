#include<iostream>
#include<stdio.h>
using namespace std;

struct Array{
  int A[20];
  int size;
  int length;
};

void Append(struct Array *arr,int x){
  if(arr->length < arr->size)
  arr->A[arr->length++]= x;
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
  cout<<"Enter the number you wanna append : ";
  int appnd;
  cin>>appnd;

  struct Array arr;
  for(int i=0;i<leng;i++)
  arr.A[i]=A[i];
  arr.size = n;
  arr.length = leng;
  Append(&arr,appnd);
  Display(arr);
  return 0;
}
