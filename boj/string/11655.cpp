#include <iostream>
#include <string>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	getline(cin, str);
	for(int i = 0; i < str.size(); i++){
		int alph_num;
		bool upper_lower;
		if(str[i] == ' ' || ('0' <= str[i] && str[i] <= '9')) cout << str[i];
		else{
			if('A' <= str[i] && str[i] <= 'Z'){
				alph_num = str[i] - 'A';
				upper_lower = true;
			}
			else{
				alph_num = str[i] - 'a';
				upper_lower = false;
			}
			alph_num += 13;
			if(alph_num >= 26) alph_num -= 26;
			upper_lower ? cout << (char)(alph_num + 'A') : cout << (char)(alph_num + 'a');
		}
	}
}
