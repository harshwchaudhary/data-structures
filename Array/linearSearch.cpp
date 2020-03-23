#include<iostream>
#include<stdio.h>
using namespace std;

struct Array {
  int A[20];
  int size;
  int length;
};

void Display(struct Array arr){
  cout<<"Elements are : \n";
  for(int i=0;i<arr.length;i++)
  cout<<arr.A[i]<<"\t";
}
int Linear(struct Array *arr,int key){
  int i;
  for(i=0 ; i< arr->length;i++){
    if(key== arr->A[i]){
      swap(arr->A[i],arr->A[0]);
      return i;
    }
  }
  return -1;
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

  cout<<"Enter element to be searched : \n";
  int key;
  cin>>key;

  struct Array arr;
  for(int i=0;i<leng;i++)
  arr.A[i] = A[i];
  arr.size = n;
  arr.length = leng;

  Display(arr);
  cout<<"Element is at index : \n"<<Linear(&arr,key);
  return 0;
}
