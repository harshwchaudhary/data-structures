#include<iostream>
using namespace std;
struct Array{
  int A[10];
  int size;
  int length;
};

void Display(struct Array arr){
  cout<<"Elements are :\n";
  for(int i=0;i<arr.length;i++)
  cout<<arr.A[i]<<"\t";
}
int BinarySearch(int a[],int l,int h,int key){
  int mid;
  if(l<=h){
    mid = (l+h)/2;
    if(key == a[mid])
    return mid;
    else if(key < a[mid])
    return BinarySearch(a,l,mid-1,key);
    else
    return BinarySearch(a,mid+1,h,key);
  }
  return -1;
}
int main()
{
  struct Array arr = {{2,3,4,5,6},10,5};
  Display(arr);
  int key;
  cout<<"Enter key : \n";
  cin>>key;
  cout<<"Element is at \n"<<BinarySearch(arr.A,0,arr.length,key);
  return 0;
}
