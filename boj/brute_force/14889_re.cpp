#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 25;
int n, a[MAX][MAX], an = MAX * 100;
bool v[MAX];

void f(int b, int id){
	if(id >= n) return;
	if(b == n / 2){
		int s1 = 0, s2 = 0;
		for(int i = 0; i < n; i++){
			for(int k = 0; k < n; k++){
				if(v[i] && v[k]) s1 += a[i][k];
				else if(!v[i] && !v[k]) s2 += a[i][k];
			}
		}
		int ab = abs(s1 - s2);
		an = min(ab, an);
	}
	v[id] = true;
	f(b + 1, id + 1);
	v[id] = false;
	f(b, id + 1);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int k = 0; k < n; k++) cin >> a[i][k];
	}
	f(0, 0);	
	cout << an;
}