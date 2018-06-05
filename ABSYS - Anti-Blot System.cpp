/*

SPOJ:2157:ABSYS - Anti-Blot System

Link to problem: http://www.spoj.com/problems/ABSYS/

A simple 2 operand math expression is given having a portion of one operand 
omitted with the word "machula" e.g 51 + 4 = 55 might be given as 5machula + 4 = 55.

Find out and output the actual expression 

Input specification
The first line of the input file contains an integer T specifying the number of test cases.
Each test case is preceded by a blank line.

Output specification
For each test case, the output shall contain one line of the form "number + number = number". 
The line must represent the equation from that test case with all missing digits filled in.

Example
Input:

3

23 + 47 = machula

3247 + 5machula2 = 3749

machula13 + 75425 = 77038

Output:
23 + 47 = 70
3247 + 502 = 3749
1613 + 75425 = 77038

*/
#include<iostream>
#include<string>
#include<math.h>

using namespace std;

void m(string,string,string);

int main(){

	int t;
	cin>>t;
	while(t--){
		string l1,p,l2,e,r;
		//Take input first operand,operator(+),second operand, equals to(=),resultant
		cin>>l1>>p>>l2>>e>>r;
		m(l1,l2,r);
	}
	return 0;
}

void m(string l1, string l2, string r){
	int L1,L2,R;
	//First operand contains ink blot
	if (l1.find("machula")!=string::npos)
	{
		L2 = stoi(l2);
		R = stoi(r);
		L1 = R-L2;
	}

	//Second operand contains ink blot
	else if(l2.find("machula")!=string::npos){
		L1 = stoi(l1);
		R = stoi(r);
		L2 = R-L1;
		
	}

	//Result contains ink blot
	else if(r.find("machula")!=string::npos){
		L1 = stoi(l1);
		L2 = stoi(l2);
		R = L1+L2;
	}

	cout<<L1<<" + "<<L2<<" = "<<R<<endl;
}