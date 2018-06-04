/*

SPOJ:4300:AE00 - Rectangles

Link to problem:http://www.spoj.com/problems/AE00/

How many different rectangles can be formed using N squares of dimensions 1x1

Two rectangles are considered different if none of them can be rotated and 
moved to obtain the second one. During rectangle construction,
the squares cannot be deformed nor any squares put upon any other ones.

Input is the number of squares to be used

Example:

Input
6

Output:
8

Explanation:

[]	[][]	[][][]		[][][][]	[][][][][]		[][][][][][]
1	 2		  3				4			5				6

[][]	[][][]
[][]	[][][]
 7		  8	

*/

#include<iostream>

using namespace std;

int rect(int);

int main(){
	int t;
	cin>>t;
	cout<<rect(t);
	return 0;
}

int rect(int t){

	int c=0;
	int n,m;
	//Counts the total number of possible rectangles
	for(n=1;n*m<=t;n++){
		
		for(m=n;n*m<=t;m++){
			c++;
		}
		m=n+1;
	}
	return c;
}