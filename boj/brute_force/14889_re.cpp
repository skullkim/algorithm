#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int M = 25;
int n, an = M * 100 * M;
int arr[M][M];
bool v[M];

void f(int a, int idx){
	if(idx >= n) return;
	if(a == n / 2){
		int t1 = 0, t2 =0; 
		for(int i= 0 ; i < n; i++){
			for(int k = 0; k < n; k++){
				if(v[i] && v[k]) t1 += arr[i][k];
				else if(!v[i] && !v[k]) t2 += arr[i][k];
			}
		}	
		an = min(an, abs(t1 - t2));
		return;
	}
	v[idx] = true;
	f(a + 1, idx + 1);
	v[idx] = false;
	f(a, idx + 1);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int k = 0; k < n; k++){
			cin >> arr[i][k];	
		}
	}
	f(0, 0);
	cout << an;
}