#include <iostream>
using namespace std;

const int M = 15;
int arr[M], n, cs;

void f(const int cur, int s){
	if(s > cur) return;
	if(s == cur){
		cs++;
		return;
	}
	for(int i = 1; i <= 3; i++){
		f(cur, s + i);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i =0 ; i < n; i++){
		cs = 0;
		f(arr[i], 0);
		cout << cs << "\n";
	}
}
