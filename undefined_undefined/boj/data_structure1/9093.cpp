#include <iostream>
#include <stack>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_cases;
	cin >> test_cases;
	string buffer;
	getline(cin, buffer);
	while(test_cases--){
		string str;
		getline(cin, str);
		stack<char> reverse_ch;
		int str_len = str.size();
		string ans = "";
		for(int i = 0; i < str_len; i++){
			if(str[i] != ' ') reverse_ch.push(str[i]);
			else{
				while(!reverse_ch.empty()){
					ans += reverse_ch.top();
					reverse_ch.pop();
				}
				ans += ' ';
			}
		}
		while(!reverse_ch.empty()){
			ans += reverse_ch.top();
			reverse_ch.pop();
		}
		cout << ans << "\n";
	}
}
