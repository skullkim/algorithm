#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k, an = -1;
vector<string> ve(55);
vector<char> ch;
bool alp[30];

void f(int cur, int idx){
	if(cur + 5 >= k + 1) return;
	if(cur + 5 == k || idx == ch.size()){
		int can = 0;
		for(int i = 0; i < n; i++){
			string st = ve[i];
			bool r = true;
			for(int k = 3; k < st.size() - 4; k++){
				if(!alp[st[k] - 'a']){
					r = false;
					break;
				}
			}
			if(r) can++;
		}
		an = max(an, can);
		return;
	}
	if(idx >= ch.size()) return;
	for(int i = idx; i < ch.size(); i++){
		if(alp[ch[i] - 'a']) continue;
		alp[ch[i] - 'a'] = true;
		f(cur + 1, i + 1);
		alp[ch[i] - 'a'] = false;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	if(k < 5){
		cout << 0;
		return 0;
	}
	else if(k == 26){
		cout << n;
		return 0;
	}
	alp['a' - 'a'] = true; alp['n' - 'a'] = true;
	alp['t' - 'a'] = true; alp['i' - 'a'] = true;
	alp['c' - 'a'] = true;
	for(int i = 0; i < n; i++){
		cin >> ve[i];
		for(int k = 3; k < ve[i].size() - 4; k++){
			if(alp[ve[i][k] - 'a']) continue;
			alp[ve[i][k] - 'a'] = true;
			ch.push_back(ve[i][k]);
		}
	}
	memset(alp, false, sizeof(alp));
	alp['a' - 'a'] = true; alp['n' - 'a'] = true;
	alp['t' - 'a'] = true; alp['i' - 'a'] = true;
	alp['c' - 'a'] = true;
	f(0, 0);
	cout << an;
}