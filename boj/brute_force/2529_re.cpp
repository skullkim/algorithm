#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int M = 15;
int tcl;
string tc, min_a="9876543211", max_a = "0", tmp = "";
bool v[M];

void f(int cur){
	if(cur == tcl){
		//cout << tmp << endl;
		//if(tmp.size() == tcl + 1){
			if(stoll(tmp) > stoll(max_a)) max_a = tmp;
			if(stoll(tmp) < stoll(min_a)) min_a = tmp;
		//}
		return;
	}
	for(int i = 0; i <= 9; i++){
		if(v[i]) continue;
		v[i] = true;
		if(tc[cur] == '>' && (tmp.back() - '0') > i){
			tmp += (i + '0');
			f(cur + 1);
			tmp.pop_back();
		}
		else if(tc[cur] == '<' && (tmp.back() - '0') < i){
			tmp += (i + '0');
			f(cur + 1);
			tmp.pop_back();
		}
		v[i] = false;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> tcl;
	char ch;
	for(int i = 0; i < tcl; i++){
		cin >> ch;
		tc += ch;
	}
	for(int i = 0; i <= 9; i++){
		memset(v, false, sizeof(v));
		tmp = "";
		tmp += i + '0';
		v[i] = true;
		f(0);
		v[i] = false;
		tmp.pop_back();
	}
	cout << max_a << "\n" << min_a;
}