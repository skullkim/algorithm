#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c;
	cin >> c;
	while(c--){
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++) cin >> v[i];
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int k = i + 1; k < n; k++){
				ans += gcd(v[i], v[k]);
			}
		}
		cout << ans << "\n";
	}
}