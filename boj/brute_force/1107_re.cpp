#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const int MAX = 1e7;
const int cs = 5e6 + 5;
int t, es, an;
bool b[12];

int f(int a){
	if(a == 0) return b[a] ? 0 : 1;
	int cnt = 0;
	while(a > 0){
		if(b[a % 10]) return 0;
		a /= 10;
		cnt++;
	}
	return cnt;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	cin >> es;
	int tp;
	for(int i = 0; i < es; i++){
		cin >> tp;
		b[tp] = true;	
	}
	an = abs(t - 100);
	for(int i = 0; i < MAX; i++){
		tp = f(i);
		if(tp > 0){
			int p = abs(i - t);
			an = min(an, tp + p);
		}
	}
	cout << an;
}