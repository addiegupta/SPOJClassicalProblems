/*

SPOJ:2123:CANDY - Candy I

Link to problem: http://www.spoj.com/problems/CANDY/

Divide candies in packets having equal candies

Example:

Input file:
5
1
1
1
1
6
2
3
4
-1

Output file:
4
-1

*/

#include<iostream>

using namespace std;

int a[10000];
int dist(int,int);

int main(){
	int t;
	cin>>t;
	while(t!=-1){
		int sum = 0;
		for(int i=0;i<t;i++){
			cin>>a[i];
			sum+= a[i];
		}
		cout<<dist(t,sum)<<endl;
		cin>>t;
	}
	return 0;
}

int dist(int t,int sum){
	
	// Cannot be divided equally
	if (sum%t!=0)
		return -1;
	
	// Number of candies supposed to be in each packet
	int c = sum/t;
	int b =0;
	for(int i=0;i<t;i++){
		if(a[i]>c)
			// Number of candies to be transferred
			b+= a[i]-c;
	}
	return b;
}



