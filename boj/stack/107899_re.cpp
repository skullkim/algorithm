#include <iostream>
#include <stack>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	stack<char> st;
	int an = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '(') st.push(s[i]);
		else{
			st.pop();
			s[i - 1] == '(' ? an += st.size() : an++;
		}
	}
	cout << an;
}