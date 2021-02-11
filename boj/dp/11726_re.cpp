#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1e3 + 10;
const int MOD = 1e4 + 7;
int n;
int cache[MAX];

int f(int v){
	if(v == 0) return 1;
	if(v < 0) return 0;
	int &c = cache[v];
	if(c != -1) return c;
	c = 0;
	c = (f(v - 1) + f(v - 2)); 
	return c;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << f(n);
}
