#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = 510;
int n, arr[M][M], c[M][M];

int func(int y, int x){
	if(arr[y][x] == -1) return 0;
	int &tmp = c[y][x];
	if(tmp != -1) return tmp;
	return tmp = max(func(y + 1, x), func(y + 1, x + 1)) + arr[y][x];
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	memset(arr, -1, sizeof(arr));
	for(int i = 0;  i < n; i++){
		for(int k = 0; k <= i; k++) cin >> arr[i][k];
	}
	memset(c, -1, sizeof(c));
	cout << func(0, 0);
}
