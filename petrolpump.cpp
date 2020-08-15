#include<iostream>
#include<string.h>
#include<string>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
//the program
int recur(int state,int sum,int n,vector<int>v,set<int> &se)
{
  if(state==n)
  {
    se.insert(sum);
  }
  else
  {
    sum=sum;
    recur(state+1,sum,n,v,se);
    sum=sum+v[state];
    recur(state+1,sum,n,v,se);
  }
  return 0;
  
}
int main()
{
  vector<int> v;
  int temp,tot=0;
  while(cin>>temp)
  {
    v.push_back(temp);
    tot=tot+temp;
  }
  int n=v.size(),i;
  set<int> se;
  set<int> sr;
  recur(0,0,n/2,v,se);
  recur((n/2),0,n,v,sr);
  auto f=se.begin();
  int half=tot/2;
  int min=100000000;
  for(f=se.begin();f!=se.end();f++)
  {
   // cout<<*f<<" ";
    int te=half-*f;
    auto it=sr.lower_bound(te);
    if(it!=sr.end()){
    //cout<<*f+*it<<" ";
    if(min>(*f+*it))
    {
      min=*f+*it;
    }}
    
  }
  cout<<max(min,tot-min);
  
  
  
  
}