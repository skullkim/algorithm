#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int M = 3e3 + 10;
int n;
vector<vector<int>> ve(M);
bool v[M], cs[M], is_c = false;

void dfs(const int &fir, int cur, int dp){
	v[cur] = true;
	for(int i = 0; i < ve[cur].size(); i++){
		int ne = ve[cur][i];
		if(!v[ne]) dfs(fir, ne, dp + 1);
		else{
			if(ne == fir && dp >= 2){
				is_c = true;
				return;
			}
		}
		if(is_c) return;
	}
}

int bfs(int cur){
	queue<pair<int, int>> q;
	pair<int, int> pa = make_pair(cur, 0);
	q.push(pa);
	//v[cur] = true;
	while(!q.empty()){
		pair<int, int> ne = q.front();
		q.pop();
		if(cs[ne.first]){
			return ne.second;
		}
		v[ne.first] = true;
		for(int i = 0; i < ve[ne.first].size(); i++){
			pair<int, int> no = make_pair(ve[ne.first][i], ne.second + 1);
			if(v[no.first]) continue;
//			v[no.first] = true;
			q.push(no);
		}
	}
	return -1;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int n1, n2;
	for(int i = 0; i < n; i++){
		cin >> n1 >> n2;
		ve[n1].push_back(n2);
		ve[n2].push_back(n1);
	}
	for(int i = 1; i <= n; i++){
		memset(v, false, sizeof(v));
		is_c = false;
		dfs(i, i, 0);
		if(is_c) cs[i] = true;
	}
	for(int i = 1; i <= n; i++) cout << v[i] << " ";
	cout << endl;
	for(int i = 1; i <= n; i++){
		memset(v, false, sizeof(v));
		cs[i] ? cout << 0 << " " : cout << bfs(i) << " ";
	}
}