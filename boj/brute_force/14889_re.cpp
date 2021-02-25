#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int M = 25;
int n, an = M * 100 * M;
int arr[M][M];
vector<int> t1, t2;
bool v[M];

void f(void){
	if(t1.size() + t2.size() == n && t1.size() == t2.size()){
		int a = 0, b = 0;
		for(int i = 0; i < n / 2; i++){
			for(int k = 0; k < n / 2; k++){
				if(i == k) continue;
				a += arr[t1[i]][t1[k]];
			}
		}
		for(int i = 0; i < n / 2; i++){
			for(int k = 0; k < n / 2; k++){
				if(i == k) continue;
				b += arr[t2[i]][t2[k]];
			}
		}
		an = min(an, abs(a - b));
		return;
	}
	for(int i = 0; i < n; i++){
		if(v[i]) continue;
		v[i] = true;
		t1.push_back(i);
		f();
		t1.pop_back();
		t2.push_back(i);
		f();
		t2.pop_back();
		v[i] = false;
	}
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
	f();
	cout << an;
}