#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

string reverseCharacter(stack<char>& word){
	string tmp = "";
	while(!word.empty()){
		tmp += word.top();
		word.pop();
	}
	//tmp += " ";
	return tmp;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str, ans = "";
	stack<char> curr_word;
	getline(cin, str);
	for(int i = 0; i < str.size(); i++){
		if(str[i] == '<'){
			ans += reverseCharacter(curr_word);
			if(ans.back() == ' ') ans.pop_back();
			ans += '<';
			i++;
			while(str[i] != '>'){
				ans += str[i++];
			}
			ans += '>';
		}
		else if(str[i] == ' '){
			ans += reverseCharacter(curr_word);
			ans += ' ';
		}
		else curr_word.push(str[i]);
	}
	ans += reverseCharacter(curr_word);
	cout << ans;
}
