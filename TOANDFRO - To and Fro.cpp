/*

SPOJ:400:TOANDFRO - To and Fro 

Link to problem: http://www.spoj.com/problems/TOANDFRO/

Mo and Larry have devised a way of encrypting messages. They first decide secretly on the number of columns 
and write the message (letters only) down the columns, 
padding with extra random letters so as to make a rectangular array of letters. 
For example, if the message is “There’s no place like home on a snowy night” and there are five columns,
Mo would write down

t o i o y
h p k n n
e l e a i
r a h s g
e c o n h
s e m o t
n l e w x

Mo includes only letters and writes them all in lower case.
In this example, Mo used the character ‘x’ to pad the message out to make a rectangle,
although he could have used any letter. Mo then sends the message to Larry by writing the letters in each row,
alternating left-to-right and right-to-left. So, the above would be encrypted as

toioynnkpheleaigshareconhtomesnlewx

Recover for Larry the original message (along with any extra padding letters) from the encrypted one.

Example

Input:

5
toioynnkpheleaigshareconhtomesnlewx
3
ttyohhieneesiaabss
0

Output:

theresnoplacelikehomeonasnowynightx
thisistheeasyoneab

*/
#include<iostream>
#include<string>
using namespace std;

string decode(string,int);

int main(){

	int n;
	cin>>n;
	while(n){
		string s;
		cin>>s;
		cout<<decode(s,n)<<endl;
		cin>>n;
	}

	return 0;
}

string decode(string s,int n){
	char a[20][20];

	// Number of rows in 2D Array
	int m = s.length()/n;

	// Iterator for string
	int k=0;

	// Decode the string to store in array
	for(int i=0;i<m;i++){
		if (i%2==0)
		{
			for(int j=0;j<n;j++){
				a[i][j] = s.at(k);
				k++;
			}
		}
		else{
			for (int j = n-1; j >= 0; --j)
			{
				a[i][j] = s.at(k);
				k++;
			}
		}
	}

	// Recovery of actual string from the array
	string f;
	for(int j= 0;j<n;j++){
		for(int i=0; i<m; i++){
			f.append(1,a[i][j]);
		}
	}
	return f;
}