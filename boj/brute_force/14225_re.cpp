#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2e6 + 10;
int n;
vector<int> v;
bool visited[MAX];

void f(int curr, int s){
	if(curr > n) return;
	if(!visited[s]){
		visited[s] = true;
	//cout << s << " " << visited[s] << endl;
	}
	for(int i = curr; i < n; i++){
		f(i + 1, s + v[i]);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
		visited[v[i]] = true;
	}
	f(0, 0);
	for(int i = 1; i < MAX; i++){
		if(!visited[i]){
			cout << i;
			return 0;
		}
	}
}