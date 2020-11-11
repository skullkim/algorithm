#include <iostream>
using namespace std;

int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_cases;
	cin >> test_cases;
	while(test_cases--){
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++) cin >> arr[i];
		long long ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				ans += gcd(arr[i], arr[j]);
			}
		}
		cout << ans << "\n";
	}
}
