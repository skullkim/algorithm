#include <iostream>
using namespace std;

int n, s, arr[25], an = 0;
bool b[25];

void f(int sum, int idx, int sz){
	if(idx > n) return;
	if(sz >= 1 && sum == s){
		an++;
		return;
	}
	for(int i = idx; i < n; i++){
		if(b[i]) continue;
		b[i] = true;
		f(sum + arr[i], i + 1, sz + 1);
		b[i] = false;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	for(int i = 0; i < n; i++) cin >> arr[i];
	f(0, 0, 0);
	cout << an;
}