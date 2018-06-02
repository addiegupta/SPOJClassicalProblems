/*

SPOJ:7974:ACPC10A - What’s Next

Link to problem: http://www.spoj.com/problems/ACPC10A/

According to Wikipedia, an arithmetic progression (AP) is a 
sequence of numbers such that the difference of any two successive members of the sequence is a constant. 
For instance, the sequence 3, 5, 7, 9, 11, 13, . . . is an arithmetic progression with common difference 2.
For this problem, we will limit ourselves to arithmetic progression whose common difference is a non-zero integer.

On the other hand, a geometric progression (GP) is a sequence of numbers where each term after the first is
found by multiplying the previous one by a fixed non-zero number called the common ratio.
For example, the sequence 2, 6, 18, 54, . . . is a geometric progression with common ratio 3. 
For this problem, we will limit ourselves to geometric progression whose common ratio is a non-zero integer.
Given three successive members of a sequence, you need to determine the type of the progression 
and the next successive member.

Example:

Input:
4 7 10
2 6 18
0 0 0

Output:
AP 13
GP 54

*/

#include <iostream>

using namespace std;

void apgp(int a1,int a2, int a3);

int main(){

	int a1,a2,a3;
	cin>>a1>>a2>>a3;
	
	while(!(a1==a2 && a2==a3 && a3==0))
	{	
		apgp(a1,a2,a3);
		cin>>a1>>a2>>a3;
	}
	
	return 0;
}

void apgp(int a1, int a2, int a3){
	int d;
	d = a2 - a1;
	
	// Is an AP
	if (d == (a3-a2))
		cout<<"AP "<<a3+d;//Next term
	// Is a GP
	else{
		d = a2/a1;
		cout<<"GP "<<a3*d;//Next term
	}
	cout<<endl;
}