#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

const int MAX = 15;
int n, arr[MAX], m = -1;
bool v[MAX];

void f(int cur, int s){
	if(cur >= n) return;
	m = max(m, s);
	for(int i = 1; i < n - 1; i++){
		if(v[i]) continue;
		int l = i - 1, r = i + 1;
		while(l >= 0 && v[l]) l--;
		while(r < n && v[r]) r++;
		v[i] = true;
		f(cur + 1, s + (arr[l] * arr[r]));
		v[i] = false;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int tmp;
	for(int i = 0; i < n; i++) cin >> arr[i];
	f(0, 0);
	cout << m;
}
