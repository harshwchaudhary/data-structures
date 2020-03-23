#include<iostream>
using namespace std;
int main()
{
  char A[] = "decimal";
  char B[] = "medical";
  int i;
  int H[26]={0};
  for(i=0;A[i]!='\0';i++)
  H[A[i]-97]++;
  for(i=0;B[i]!='\0';i++){
    H[A[i]-97]--;
    if(H[A[i]-97]<0){
      cout<<"Not anagrams\n";
      break;
    }
  }
  if(B[i]=='\0')
  cout<<"anagrams\n";
  return 0;
}
