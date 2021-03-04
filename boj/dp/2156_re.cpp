#include <iostream>
#include <algorithm>
using namespace std;

const int M = 1e4 + 10;
int n, arr[M], c[M];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	c[0] = arr[0]; c[1] = arr[0] + arr[1];
	for(int i = 2; i < n; i++){
		c[i] = max(c[i - 3] + arr[i - 1], c[i - 2]) + arr[i];
		c[i] = max(c[i], c[i - 1]);
	}
	cout << c[n - 1];
}
