/*
SPOJ:1030:EIGHTS - Triple Fat Ladies

Link to problem:http://www.spoj.com/problems/EIGHTS/

For t test cases,
For input k, find the kth number whose cube ends in the digits 888

Example:

Input:
1
1

Output:
192

*/

#include<iostream>
#include<math.h>
#define ll long long int

using namespace std;

// A pattern is observed in the problem. The first number is 192, the second one 442, third is 692 and so on
// (At a difference of 250 each). Hence the solution is as given below
int main(){

	int t;
	cin>>t;
	while(t--){
		ll k;
		cin>>k;
		ll n = 192;
		n += 250*(k-1);
		cout<<n<<endl;
	}
	return 0;
}
