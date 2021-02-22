#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int D[3] = {-1, 1, 2};
const int M = 1e5 + 10;
int st, ed, c[M];
bool vi[M];
vector<vector<int>> v(M);
vector<int> v2;

void bfs(void){
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i = 0; i < 3; i++){
			int ne = i != 2 ? now + D[i] : now * D[i];
			if(0 > ne || ne > ed * 2 + 10 || c[ne] != -1) continue;
			c[ne] = c[now] + 1;
			v[ne].push_back(now);
			v[now].push_back(ne);
			q.push(ne);
			if(ne == ed) return;
		}
	}
}

bool bo = false;
void dfs(int cur){
	vi[cur] = true;
	v2.push_back(cur);
	if(cur == st){
		bo = true;
		return;
	}
	for(int i = 0; i < v[cur].size(); i++){
		int ne = v[cur][i];
		if(vi[ne]) continue;
		dfs(ne);
		if(bo) return;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> st >> ed;
	memset(c, -1, sizeof(c));
	c[st] = 0;
	bfs();
	dfs(ed);
	cout << c[ed] << "\n";
	for(int i = v2.size() - 1; i >= 0; i--) cout << v2[i] << " ";
}