#include <iostream>
#include <vector>
using namespace std;

int n, ns;
vector<int> ve;
bool v[10];

void f(int cnt){
	if(cnt == ns){
		for(int i = 0; i < ns; i++) cout << ve[i] << " ";
		cout << "\n";
		return;
	}
	//if(cur > n) return;
	for(int i = 1; i <= n; i++){
		if(v[i]) continue;
		v[i] = true;
		ve.push_back(i);
		f(cnt + 1);
		v[i] = false;
		ve.pop_back();
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> ns;
	f(0);
}