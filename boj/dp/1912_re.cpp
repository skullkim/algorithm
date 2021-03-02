#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int M = 1e5 + 100;
int n, arr[M], c[M], an = INT_MAX * -1;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	c[0] = arr[0];
	for(int i= 0; i < n; i++){
		c[i] = max(arr[i], c[i - 1] + arr[i]);
		an = max(an, c[i]);
	}
	cout << an;
}