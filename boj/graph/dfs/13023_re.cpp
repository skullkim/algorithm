#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 2e3 + 10;
int ns, es;
vector<vector<int>> fs(MAX);
bool v[MAX];
bool an = false;

void fu(int cun, int dp){
	if(dp == 4){
		an = true;
		return;
	}
	v[cun] = true;
	for(int i = 0; i < fs[cun].size(); i++){
		int ne = fs[cun][i];
		if(v[ne]) continue;
		fu(ne, dp + 1);
		if(an) return;
	}
	v[cun] = false;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> ns >> es;
	int n1, n2;
	for(int i = 0; i < es; i++){
		cin >> n1 >> n2;
		fs[n1].push_back(n2);
		fs[n2].push_back(n1);
	}
	for(int i = 0; i < ns; i++){
		memset(v, false, sizeof(v));
		fu(i, 0);
		if(an){
			cout << 1;
			return 0;
		}
	}
	cout << 0;
}
