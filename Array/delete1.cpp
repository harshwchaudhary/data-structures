#include<iostream>
#include<stdio.h>
using namespace std;

struct Array{
  int A[20];
  int size;
  int length;
};

int Delete(struct Array *arr, int index){
  int i,x=0;
  if(index >=0 && index < arr->length){
    x= arr->A[index];
    for(i=index ; i < arr->length;i++)
    arr->A[i] = arr->A[i+1];
    arr->length--;
  }
  return x;
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
  cout<<"Enter the index to be deleted : \n";
  int indx;
  cin>>indx;

  struct Array arr;
  for(int i=0;i<leng;i++)
  arr.A[i]=A[i];
  arr.size = n;
  arr.length = leng;
  Delete(&arr,indx);
  Display(arr);
  return 0;
}
