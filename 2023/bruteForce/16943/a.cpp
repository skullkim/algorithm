#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string a, b, ans = "-1";
bool vi[100];

void f(string c) {
	if (c.size() == a.size() && stoi(c) < stoi(b) && c > ans) {
		ans = c;
	}

	for (int i = 0; i < a.size(); i++) {
		if (vi[i] || (c.size() == 0 && a[i] == '0')) continue;
		vi[i] = true;
		c.push_back(a[i]);
		f(c);
		c.pop_back();
		vi[i] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string tmp;
	cin >> tmp;
	a = tmp;
	cin >> tmp;
	b = tmp;

	f("");
	cout << ans;
}
