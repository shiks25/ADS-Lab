//In the given range [L, R], print all numbers having unique digits. e.g. In range 10 to 20 should print all numbers except 11.

#include<bits/stdc++.h> 
using namespace std;

void uniqueNum(int l,int r)
{
   for(int i=l;i<=r;i++){
	   int n=i;
	   bool v[10]={false};
       while(n)
       {
           if(v[n%10]) break;
           
           v[n%10]=true;
           
           n=n/10;
        }
	if(n==0){
    	   cout<<i<<" ";
	}
    }
  cout<<endl;
}

int main()
{
    int l,r;
	cout<<"L = ";
	cin>>l;
	cout<<"R = ";
	cin>>r;
    uniqueNum(l, r); 
    return 0; 
}