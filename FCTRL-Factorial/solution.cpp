
// Find Z(N), the number of zeros at the end of 
// the decimal form of number N!

#include<iostream>
#include<math.h>
#define ll long long int

using namespace std;

ll z(ll n);

int main(){
	
	ll t,n;
	cin>>t;
	while(t--){

		cin>>n;
		ll o = z(n);
		cout<<o<<endl;
	}
	return 0;
}

ll z(ll b){

	// No zeroes for factorial of number less than 5
	if (b<5)
	{
		return 0;
	}

	ll i=1,c=0;
	
	// Find out highest power of 5 smaller than the given number
	while(pow(5,i)<=b){
		i++;
	}

	//Find number of trailing zeroes in factorial
	for(ll j=1;j<=i;j++){
		c+= b/pow(5,j);
	}

	return c;
}