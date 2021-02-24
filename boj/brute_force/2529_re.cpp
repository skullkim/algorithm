#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int M = 15;
int tcl;
string tc, min_a="1000000000000", max_a = "0", tmp = "";
bool v[M];

void f(int cur){
	if(cur == tcl){
		if(tmp > max_a) max_a = tmp;
		if(tmp < min_a) min_a = tmp;
		return;
	}
	//cout << cur << endl;
		//cout << tmp.back();
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
	cin >> tc;
	//(int i =0 ; i < tc.size(); i++) cout << tc[i];
	for(int i = 0; i <= 9; i++){
		tmp += i + '0';
		v[i] = true;
		f(0);
		v[i] = false;
		tmp.pop_back();
	}
	cout << max_a << "\n" << min_a;
}