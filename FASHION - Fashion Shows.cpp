/*
SPOJ:1025:FASHION - Fashion Shows

Link to problem:http://www.spoj.com/problems/FASHION/

2 sets of N integers has been given. Every integer from set 1 is multiplied with an integer
from set 2 such that the sum of these products is maximum. Find this maximum number for t test cases

*/

#include<iostream>

using namespace std;

void merge(int[],int,int,int);
void mergeSort(int[],int,int);
void solve(int x[],int y[], int n);

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int x[1000],y[1000];
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		for(int i=0;i<n;i++){
			cin>>y[i];
		}
		// Sort both arrays using merge sort
		mergeSort(x,0,n-1);
		mergeSort(y,0,n-1);
		solve(x,y,n);
	}
}

// Sorts the arrays in increasing order recursively
void mergeSort(int arr[],int l, int r){
	if (l<r)
	{
		int m = (l+r-1)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

void merge(int arr[],int l,int m,int r){

	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	int L[1000],R[1000];

	for(i=0;i<n1;i++)
		L[i] = arr[l+i];

	for(j=0;j<n2;j++)
		R[j] = arr[m+1+j];

	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}

	while(i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k] = R[j];
		j++;
		k++;
	}
}

// Solves the problem
void solve(int x[],int y[], int n){

	int sum=0;
	for(int i=0;i<n;i++){
		// Max product 
		sum += (x[i]*y[i]);
	}	
	cout<<sum<<endl;
}
