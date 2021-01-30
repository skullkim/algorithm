#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int>	v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	stack<int>a, b;
	string s = "";
	for(int i = 1, j = 0; i <= n; i++){
		a.push(i);
		s += '+';
		while(!a.empty() && a.top() == v[j]){
			b.push(a.top());
			a.pop();
			j++;
			s += '-';
		}
	}
	if(n == b.size()){
		for(int i = 0; i < s.size(); i++) cout << s[i] << "\n";
	}
	else cout << "NO";
}