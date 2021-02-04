#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	const int MAX = 1e6 + 10;
	bool b[MAX];
	memset(b, false, sizeof(b));
	b[1] = true;
	cin >> n >> m;
	for(int i = 2; i <= m; i++){
		if(!b[i]){
			for(int k = i + i; k <= m; k += i){
				if(!b[k]) b[k] = true; 
			}
		}
	}
	for(int i = n; i <= m; i++){
		if(!b[i]) cout << i << "\n";
	}
}