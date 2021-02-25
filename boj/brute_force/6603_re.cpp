#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int k;
vector<int> s(13), an;
bool v[13];

void f(int cur){
	if(an.size() == 6){
		for(int i = 0; i < 6; i++) cout << an[i] << " ";
		cout << "\n";
		return;
	}
	if(cur >= k) return;;
	for(int i = cur; i < k; i++){
		if(v[i]) continue;
		v[i] = true;
		an.push_back(s[i]);
		f(i + 1);
		an.pop_back();
		v[i] = false;	
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		k = 0;
		s.clear();
		an.clear();
		memset(v, false, sizeof(v));		
		cin >> k;
		if(!k) return 0;
		for(int i = 0; i < k; i++) cin >> s[i];
		f(0);
		cout << "\n";
	}
}