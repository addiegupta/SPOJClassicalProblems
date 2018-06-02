/*

SPOJ:3410:SAMER08F - Feynman

Link to problem:http://www.spoj.com/problems/SAMER08F/

How many different squares are there in a grid of N × N squares? Output this number

References: https://www.freemathhelp.com/forum/archive/index.php/t-59905.html
*/

#include<iostream>

using namespace std;

int squares(int n);

int main(){

	int n;
	cin>>n;
	while(n){
		cout<<squares(n)<<endl;
		cin>>n;
	}
	return 0;
}
/*
Example of calculation for 6x6 grid


			1 2 3 4 5 6
			2 2 3 4 5 6
			3 3 3 4 5 6 
			4 4 4 4 5 6
			5 5 5 5 5 6
			6 6 6 6 6 6

Number |    Size of grid
of 	   |	
squares| 	The number in the columns represents the
in     |	number of new additions as size of grid
grid   |     is increased from 1x1 to 6x6

		   1x1     2x2     3x3     4x4   5x5   6x6

1x1 		1		3		5		7	    9   	11  => 1 + 3 + 5 + 7 + 9 + 11 = 36 = 6^2
2x2 		0		1		3		5       7   	9   => 1 + 3 + 5 + 7 + 9 	  = 25 = 5^2
3x3 		0		0		1		3     	5   	7	=> 1 + 3 + 5 + 7 		  = 16 = 4^2
4x4 		0		0		0		1     	3   	5	=> 1 + 3 + 5 			  = 9  = 3^2  => 1^2 + 2^2 + 3^2 + 4^2 + 5^2 + 6^2 = (6*(6+1)*((2*6)+1))/6 = 91
5x5 		0		0		0		0     	1   	3	=> 1 + 3  				  = 4  = 2^2
6x6			0		0		0		0		0		1	=> 1 					  = 1  = 1^2
*/
int squares(int n){

	// Formula for sum of squares upto n
	return (n*(n+1)*((2*n)+1))/6;
}