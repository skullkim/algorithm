#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string a, b, c = "";
bool v[20];

char findLargest(int ch) {
	int ans = 0;
	int i;
	for (i = 0; i < a.size(); i++){
		int an = a[i] - '0';
		if (an <= ch && an > ans && !v[i]) {
			ans = an;
		}
	}
	v[i] = true;
	return ans + '0';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;

	if (a.size() > b.size() || a == b) {
		cout << -1;
		return 0;
	}


	while(c.size() < b.size() && c.size() < a.size()) {
		int idx = c.size();
		char tmp = findLargest(b[idx] - '0');
		if (c.size() == 0 && tmp == '0') {
			cout << -1;
			return 0;
		}
		c += tmp;
	}
	cout << c;
}
