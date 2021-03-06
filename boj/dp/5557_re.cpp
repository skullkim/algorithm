#include <iostream>
#include <cstring>
using namespace std;

const int M = 1e3 + 10;
long long n, arr[M], c[M][21], re;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	c[0][arr[0]] = 1;
	for(int i = 1; i < n - 1; i++){
		for(int k = 0; k <= 20; k++){
			if(0 <= k + arr[i] && k + arr[i] <= 20){
				c[i][k] += c[i - 1][k + arr[i]];
			}
			if(0 <= k - arr[i] && k - arr[i] <= 20){
				c[i][k] += c[i - 1][k - arr[i]];
			}
		}
	}
	cout << c[n - 2][arr[n - 1]];
}
