/*

SPOJ:4:ONP - Transform the Expression

Transform the algebraic expression with brackets into RPN form (Reverse Polish Notation).
Two-argument operators: +, -, *, /, ^ (priority from the lowest to the highest), brackets ( ).
Operands: only letters: a,b,...,z. Assume that there is only one RPN form (no expressions like a*b*c).

(Convert infix expression to postfix expression)

Example:
Input:
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

Output:
abc*+
ab+zx+*
at+bac++cd+^*

References: http://examradar.com/algebraic-expressions/
			http://www-stone.ch.cam.ac.uk/documentation/rrf/rpn.html
*/

#include<iostream>
#include<string>
#include<stack>

using namespace std;

string rpn(string);

int main(){
	int t;
	cin>>t;
	while(t--){
		string infix;
		cin>>infix;
		cout<<rpn(infix)<<endl;
	}

	return 0;
}

string rpn(string in){
	
	// Mainting 3 stacks, 1 each for alphabets,operators,brackets.
	stack<char> alpha,oper,bracket;
	string out;

	for(int i=0;i<in.length();i++){
		char c = in[i];
		if (c=='(')
		{
			bracket.push(c);
		}
		else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'){
			oper.push(c);
		}
		else if(isalpha(c)){
			alpha.push(c);
		}
		// Closing ) appeared, pop a opening ( and transfer topmost operator to alphabet stack
		else if(c==')'){
			bracket.pop();
			char temp = oper.top();
			oper.pop();
			alpha.push(temp);
		}
	}
	// Alphabet stack contains final required expression but will be popped in reverse order
	// Hence being added to operator stack to reverse it
	while(!alpha.empty()){
		char temp = alpha.top();
		alpha.pop();
		oper.push(temp);
	}
	// Final expression popped in correct order
	while(!oper.empty()){
		char temp = oper.top();
		oper.pop();
		out.append(1,temp);
	}
	return out;
}