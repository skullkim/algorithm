#include <iostream>
#include <vector>
using namespace std;

int n, ns;
vector<int> ve;
bool v[10];

void f(int cur, int cnt){
	if(cnt == ns){
		for(int i = 0; i < ns; i++) cout << ve[i] << " ";
		cout << "\n";
		return;
	}
	if(cur > n + 1) return;
	for(int i = cur; i <= n; i++){
		if(v[i]) continue;
		v[i] = true;
		ve.push_back(i);
		f(i + 1, cnt + 1);
		ve.pop_back();
		v[i] = false;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> ns;
	f(1, 0);
}