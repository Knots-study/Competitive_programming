#素数判定　
#include <bits/stdc++.h>
using namespace std;

bool prime(int n){
  int n_root = sqrt(n);
  if(n==1)return false;
  else if(n==2)return true;
  else if (n%2==0)return false;
  for(int i=3;i<n_root+1;i+=2){
    if(n%i==0)return false;
  }
  return true;
}

