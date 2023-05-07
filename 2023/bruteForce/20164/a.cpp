#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int minV = INF, maxV = 0;
string str;

int toInt(char c) {
	return c - '0';
}

void f(string str, int odds) {
//cout << str << endl;
	for (int i = 0; i < str.size(); i++) {
		if (toInt(str[i]) % 2 != 0) odds++;
	}
	if (str.size() == 1) {
		minV = min(minV, odds);
		maxV = max(maxV, odds);
		return;
	} else if (str.size() == 2) {
		string tmp = to_string(toInt(str[0]) + toInt(str[1]));
		f(tmp, odds);
	} else {
		for (int idx = 1; idx < str.size() - 1; idx++) {
			for (int idx2 = idx + 1; idx2 < str.size(); idx2++) {
//				cout << "==================================================" << endl;
//				cout << str << " " << idx << " " << idx2 << " " << endl;;
//				cout << str.substr(0, idx) << " " << str.substr(idx, idx2 - idx) << " "
//					<< str.substr(idx2, str.size() - idx2) << endl;
				int num1 = stoi(str.substr(0, idx));
				int num2 = stoi(str.substr(idx, idx2 - idx));
				int num3 = stoi(str.substr(idx2, str.size() - idx2));
//				cout << num1 << " " << num2 << " " << num3 << endl << endl;
//				cout << "==================================================" << endl;
				string tmp = to_string(num1 + num2 + num3);
				f(tmp, odds);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;
	f(str, 0);
	cout << minV << " " << maxV;
}
