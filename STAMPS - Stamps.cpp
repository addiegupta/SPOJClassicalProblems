/*

SPOJ:3375:STAMPS - Stamps

Link to problem:http://www.spoj.com/problems/STAMPS/

Given 2 numbers n and f followed by f integers, 
find minimum number of integers required so that their sum is greater than or equal to n.
If not possible, output "impossible"

Example

Input:
3  //test cases
100 6 // n=100 f=6
13 17 42 9 23 57 // f integers
99 6
13 17 42 9 23 57
1000 3
314 159 265


Output:
Scenario #1:
3

Scenario #2:
2

Scenario #3:
impossible

References:https://www.geeksforgeeks.org/merge-sort/

*/
#include<iostream>
#define ll long long int

using namespace std;

int s[1000];
int stamp(ll,int);
// This merge sort sorts the array in decreasing order 
void mergesort(int[],int,int);
void merge(int[],int,int,int);

int main(){
	int t;
	cin>>t;
	int tn =1;
	while(t--){
		ll n;
		int f;
		cin>>n>>f;
		ll sum=0;
		for(int i=0;i<f;i++){
			cin>>s[i];
			sum+=s[i];
			}
		cout<<"Scenario #"<<tn<<":"<<endl;
		// Sum cannot exceed n
		if(sum<n){
			cout<<"impossible"<<endl<<endl;
		}
		else{
			cout<<stamp(n,f)<<endl<<endl;
		}
		// Keeps count of scenarios
		tn++;
	}
	return 0;
}


int stamp(ll n,int f){
	// Reverse sorts the array i.e. decreasing order
	mergesort(s,0,f-1);
	int sum=0;
	for(int i=0;i<f;i++){
		sum+=s[i];
		if(sum>=n){
			return i+1;
		}
	}
}
void mergesort(int s[],int l,int r){
	if(l<r){
		int m =(l+r-1)/2;
		mergesort(s,l,m);
		mergesort(s,m+1,r);
		merge(s,l,m,r);
	}
}
void merge(int s[] ,int l ,int m, int r){
	int i,j,k;
	i=0;
	j=0;
	k=0;
	int n1 = m-l+1;
	int n2 = r-m;

	int L[1000],R[1000];
	for(i=0;i<n1;i++)
		L[i]=s[l+i];
	for(j=0;j<n2;j++)
		R[j]=s[m+1+j];
	
	i=0;
	j=0;
	k=l;

	while(i<n1 && j<n2){
		if(L[i]>=R[j]){
			s[k]=L[i];
			i++;
		}
		else if(L[i]<R[j]){
			s[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		s[k]=L[i];
		k++;
		i++;
	}
	while(j<n2){
		s[k]=R[j];
		k++;
		j++;
	}
}
