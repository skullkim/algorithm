#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e3 + 10;
int ns, es;
vector<vector<int>> n(MAX);
bool v[MAX];

void dfs(int curr){
	if(curr > ns) return;
	v[curr] = true;
	for(int i = 0; i < n[curr].size(); i++){
		int ne = n[curr][i];
		if(v[ne]) continue;
		dfs(ne);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> ns >> es;
	int n1, n2;
	for(int i = 0; i < es; i++){
		cin >> n1 >> n2;
		n[n1].push_back(n2);
		n[n2].push_back(n1);
	}
	int an = 0;
	for(int i = 1; i <= ns; i++){
		if(!v[i]){
			an++;
			dfs(i);
		}
	}
	cout << an;
}
