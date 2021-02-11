#include <iostream>
#include <cstring>
using namespace std;

const int M = 1e3 + 10;
const int MO = 1e4 + 7;
int n;
int cache[M];

int f(int v){
	if(v < 0) return 0;
	if(v == 0) return 1;
	int &c = cache[v];
	if(c != -1) return c;
	c = 0;
	return c = (f(v - 1) + f(v - 2) + f(v - 2)) % MO;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(cache, -1, sizeof(cache));
	cin >> n;
	cout << f(n);
	
}
