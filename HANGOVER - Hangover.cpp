/*
SPOJ:902:HANGOVER - Hangover

Link to problem: http://www.spoj.com/problems/HANGOVER/

For a given float value, calculate minimum value of n for which the sum of series 1/2 + 1/3 + 1/4 + .... + 1/n+1
is equal to at least the given f value. 
Test cases are given until 0.00 occurs


*/

#include<iostream>

using namespace std;

float h(float);

int main(){
	float f;
	cin>>f;
	while(f){
		cout<<h(f)<<" card(s)"<<endl;
		cin>>f;
	}
	return 0;
}

float h(float f){
	float c=0;
	float i=1.0;
	// Summing of series and comparing with the input float value
	while(c<f){
		c+= (1/++i);
	}
	return i-1;
}
