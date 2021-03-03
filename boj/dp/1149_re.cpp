#include <iostream>
#include <algorithm>
using namespace std;

const int M = 1010;
int n, arr[M][3], c[M][3];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int k = 0; k < 3; k++) cin >> arr[i][k];
	}
	c[0][0] = arr[0][0]; c[0][1] = arr[0][1]; c[0][2] = arr[0][2];
	for(int i = 1; i < n; i++){
		c[i][0] = min(c[i - 1][1], c[i - 1][2]) + arr[i][0];
		c[i][1] = min(c[i - 1][0], c[i - 1][2]) + arr[i][1];
		c[i][2] = min(c[i - 1][1], c[i - 1][0]) + arr[i][2];
	}
	cout << min(c[n - 1][0], min(c[n - 1][1], c[n - 1][2]));
}

