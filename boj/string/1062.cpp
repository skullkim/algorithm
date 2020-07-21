#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;


const map<char, bool> must_teach = {
	{'a', true}, {'n', true}, {'t', true}, {'i', true}, {'c', true}
};
map<char, bool> teached;
vector<string> words;
vector<char> should_teach;
int can_read;

void teachMaxWords(int rest_chances, int curr_idx){
	if(curr_idx >= should_teach.size()) return;
	if(rest_chances == 0){
		int readable = 0;
		for(int w = 0; w < words.size(); w++){
			bool can_read = true;
			for(int i = 4; i < words[w].size() - 4; i++){
				if(!must_teach.count(words[w][i]) && !teached.count(words[w][i])){
					can_read = false;
					break;
				}
			}
			if(can_read) readable++;
		}
		can_read = max(can_read, readable);
		return;
	}
	if(!must_teach.count(should_teach[curr_idx]) && !teached.count(should_teach[curr_idx])){
		teached[should_teach[curr_idx]] = true;
		teachMaxWords(rest_chances - 1, curr_idx + 1);
		teached.erase(should_teach[curr_idx]);
	}
	teachMaxWords(rest_chances, curr_idx + 1);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MIN_WORDS = 5;
	int all_wrods, can_teach;
	string str;
	cin >> all_wrods >> can_teach;
	if(can_teach < MIN_WORDS){
		cout << 0;
		return 0;
	}
	for(int s = 0; s < all_wrods; s++){
		cin >> str;
		for(int i = 4; i < str.size() - 4; i++){
			if(!must_teach.count(str[i])) should_teach.push_back(str[i]);
		}
		words.push_back(str);
	}
//	for(int i = 0; i < should_teach.size(); i++) cout << should_teach[i] << ' ';
//	cout << endl;
	vector<char>::iterator it = unique(should_teach.begin(), should_teach.end());
	should_teach.resize(distance(should_teach.begin(), it));
//	for(int i = 0; i < should_teach.size(); i++) cout << should_teach[i] << ' ';
//	cout << endl;
	teachMaxWords(can_teach - MIN_WORDS, 0);
	cout << can_read;
}
