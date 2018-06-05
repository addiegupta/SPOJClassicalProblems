/*
SPOJ:9948:WILLITST - Will it ever stop

Link to problem: http://www.spoj.com/problems/WILLITST/

A number n is input and then this code is run

while n > 1
  if n mod 2 = 0 then
    n:=n/2
  else
    n:=3*n+3

Find out if the code will ever stop or not. If yes, output "TAK" else "NIE"

Explanation: 
This code can only stop if the else statement is never executed
Hencce , the code will stop only if the number n is of the form 2^i where i is an integer

*/
#include<iostream>
#define ll long long int

using namespace std;

void pow2(ll);

int main(){
	ll n;
	cin>>n;
	pow2(n);

	return 0;
}

void pow2(ll n){
	while(n%2==0 && n!=1){
		n/=2;
	}
	if(n==1){
		cout<<"TAK";
	}
	else{
		cout<<"NIE";
	}

}