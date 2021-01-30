#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	stack<char> st;
	string a = "";
	getline(cin, s);
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '<' || s[i] == ' '){
			while(!st.empty()){
				a += st.top();
				st.pop();
			}
			if(s[i] == ' ') a += ' ';
			if(s[i] == '<'){
				while(s[i] != '>'){
					a += s[i++];
				}
				a += s[i];
			}
		}
		else{
			st.push(s[i]);
		}
	}
	while(!st.empty()){
		a += st.top();
		st.pop();
	}
	cout << a;
}
