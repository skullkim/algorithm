#include <iostream>
#include <string>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a = 0;
	cin >> n;
	while(n--){
		string s;
		a = 0;
		cin >> s;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '(') a++;
			else if(s[i] == ')') a--;
			if(a < 0){
				break;
			}
		}
		a == 0 ? cout << "YES" << "\n" : cout << "NO" << "\n";
	}
}