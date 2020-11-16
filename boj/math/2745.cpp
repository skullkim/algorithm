#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<char, int> numer_sys;
	for(int i = 0; i < 10; i++){
		numer_sys[(char)(i + '0')] = i;
	}
	for(int i = 0, k = 10; i < 26; i++){
		numer_sys[(char)(i + 'A')] = k++;
	}
	string target;
	int num;
	cin >> target >> num;
	if(num == 10){
		cout << target;
		return 0;
	}
	int ans = 0;
	for(int i = 0; i < target.size(); i++){
		ans += (numer_sys[target[i]] * (int)pow(num, target.size() - i - 1));
	}
	cout << ans;
}
