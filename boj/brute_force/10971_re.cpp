#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 15;
int ns, arr[MAX][MAX], an = 1e7 + 100;
bool v[MAX];

void f(const int &st, int cur, int s, int cnt){
	if(cnt == ns - 1){
		if(arr[cur][st]) an = min(an, s + arr[cur][st]);
		return;
	}
	v[cur] = true;
	for(int i = 0; i < ns; i++){
		int ne = arr[cur][i];
		if(v[i] || !ne) continue;
		f(st, i, s + ne, cnt + 1);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> ns;
	for(int i = 0; i < ns; i++){
		for(int k = 0; k < ns; k++) cin >> arr[i][k];
	}
	for(int i = 0; i < ns; i++){
		memset(v, false, sizeof(v));
		f(i, i, 0, 0);
	}
	cout << an;
}
