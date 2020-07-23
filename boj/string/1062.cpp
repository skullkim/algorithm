#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;


const map<char, bool> must_teach = {
	{'a', true}, {'n', true}, {'t', true}, {'i', true}, {'c', true}
};
const int MAX_CHAR = 27;
map<char, bool> teached;
vector<string> words;
vector<char> should_teach;
int can_read;
bool alphabets[MAX_CHAR];

void teachMaxWords(int rest_chances, int curr_idx){
	if(curr_idx >= MAX_CHAR) return;
	if(rest_chances == 0){
		int readable = 0;
		for(int w = 0; w < words.size(); w++){
			bool can_read = true;
			for(int i = 4; i < words[w].size() - 4; i++){
				if(!alphabets[words[w][i] - 'a']){
					can_read = false;
					break;
				}
			}
//			if(can_read){
//				for(int i = 0; i < MAX_CHAR; i++) if(alphabets[i])cout << static_cast<char>(i + 'a') << " ";
//				cout << endl;
//				cout << words[w] << endl;
//			}
			if(can_read) readable++;
		}
		can_read = max(can_read, readable);
//		cout << endl;
		return;
	}
	for(int i = curr_idx; i < MAX_CHAR; i++){
		if(alphabets[i]) continue;
		alphabets[i] = true;
		teachMaxWords(rest_chances - 1, curr_idx + 1);
		alphabets[i] = false;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MIN_WORDS = 5;
	const int TEACH_ALL = 26;
	int all_wrods, can_teach;
	string str;
	cin >> all_wrods >> can_teach;
	if(can_teach < MIN_WORDS){
		cout << 0;
		return 0;
	}
	else if(can_teach == TEACH_ALL){
		cout << can_teach;
		return 0;
	}
	for(int s = 0; s < all_wrods; s++){
		cin >> str;
		words.push_back(str);
	}
	alphabets['a' - 'a'] = true; alphabets['n' - 'a'] = true;
	alphabets['t' - 'a'] = true; alphabets['i' - 'a'] = true;
	alphabets['c' - 'a'] = true;
	teachMaxWords(can_teach - MIN_WORDS, 0);
	cout << can_read;
}
