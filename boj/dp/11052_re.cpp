#include <iostream>
#include <algorithm>
using namespace std;

const int M = 1e3 + 10;
int cs, arr[M], c[M];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	 cin >> cs;
	for(int i = 1; i <= cs; i++) cin >> arr[i];
	for(int i = 1; i <= cs; i++){
		for(int k = 1; k <= i; k++){
			c[i] = max(c[i], c[i - k] + arr[k]);
		}
	}
	cout << c[cs];
}