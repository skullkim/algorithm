#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool v[9], b = false;
vector<int> a(9), an;

void f(int id, int s){
	if(id > 9 || s > 100) return;
	if(id == 9){
		if(s == 100) b = true;
		return;
	}
	for(int i = 0; i < 9; i++){
		if(v[i]) continue;
		v[i] = true;
		an.push_back(a[i]);
		f(i + 1, s + a[i]);
		if(b) return;
		an.pop_back();
		v[i] = false;
	}
	
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 0; i < 9; i++) cin >> a[i];
	f(0, 0);
	sort(an.begin(), an.end());
	for(int i = 0; i < 7; i++) cout << an[i] << "\n";
}
