/*
Given an array of N distinct elements, the task is to find all elements in array except two greatest elements.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two lines. The first line of input contains an integer N denoting the size of the array. Then in the next line are N space separated array elements.

Output:
For each test case in a new line print the space separated sorted values denoting the elements in array which have at-least two greater elements than themselves.

Constraints:
1<=T<=100
3<=N<=100
1<=A[]<=100
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ar[n];
		for(int i=0;i<n;i++){
			cin>>ar[i];
		 }
		 sort(ar,ar+n);
		 cout<<"Final Array:"<<endl;
		 for(int j=0;j<n-2;j++){
			 cout<<ar[j]<<" ";
		 }
		cout<<endl;
	 }
}
