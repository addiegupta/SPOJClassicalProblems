/*

SPOJ:1112:NSTEPS - Number Steps

LINK to problem: http://www.spoj.com/problems/NSTEPS/

Starting from point (0,0) on a plane, we have written all non-negative integers 0, 1, 2,...
as shown in the figure. For example, 1, 2, and 3 has been written
at points (1,1), (2,0), and (3, 1) respectively and this pattern has continued.

y	6
	5           9
	4         8   10
	3       5   7
	2     4   6
	1   1   3 
	0 0	  2
 	  0 1 2 3 4 5 6 

 	  			  x

Read the coordinates of a point (x, y), and write the number (if any) 
that has been written at that point. (x, y) coordinates in the input are in the range 0...10000.
*/

#include<iostream>
 
using namespace std;

void num(int,int);

int main(){

	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		num(x,y);
	}
	return 0;
}

void num(int x,int y){
	//Even x coordinate
	if (x%2==0)
	{
		if (x==y)
			cout<<x*2;
		else if(y==(x-2))
			cout<<(x*2)-2;
		else
			cout<<"No Number";
	}

	//Odd coordinate
	else{
		if(x==y)
			cout<<(x*2)-1;
		else if(y==(x-2))
			cout<<(x*2)-3;
		else
			cout<<"No Number";
	}
	cout<<endl;
}