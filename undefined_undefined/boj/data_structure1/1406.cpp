#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	list<char> str;
	string tmp_str;
	int commands;
	char ch;
	cin >> tmp_str >> commands;
	for(int i = 0; i < tmp_str.size(); i++) str.push_back(tmp_str[i]);
	auto cursor = str.end();
	while(commands--){
		cin >> ch;
		if(ch == 'L' && cursor != str.begin()) cursor--;
		else if(ch == 'D' && cursor != str.end()) cursor++;
		else if(ch == 'B' && cursor != str.begin()){
			auto tmp = cursor;
			cursor = str.erase(--tmp);
		}
		else if(ch == 'P'){
			cin >> ch;
			str.insert(cursor, ch);
		}
	}
	for(auto i : str) cout << i; 
}
