#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int M = 18;
int c[M], ds;
pair<int, int> arr[M];

int f(int cur){
	if(cur == ds + 1) return 0;
	if(cur > ds + 1) return -987654321;
	int &t = c[cur];
	if(c[cur] != -1) return;
	return t = max(f(cur + 1), f(cur + arr[cur].first) + arr[cur].second);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> ds;
	memset(c, -1, sizeof(c));
	for(int i = 1, a, b; i <= ds; i++){
		cin >> a >> b;
		arr[i] = make_pair(a, b);
	}
	cout << f(1);
}