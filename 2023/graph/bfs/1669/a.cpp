#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int firstHeight, target;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> firstHeight >> target;

	pii tmp = make_pair(firstHeight + 1, 1);
	queue<pii> q;
	q.push(tmp);
	int answer = 0;
	while(!q.empty()) {
		pii curr = q.front();
		q.pop();
		answer++;
		if (curr.first + 1 == target) {
			break;
		}
		cout << answer << endl;
		cout << curr.first << " " << curr.second << endl;
		for (int i = curr.second - 1; i <= curr.second + 1; i++) {
			if (i <= 0) continue;
			if (curr.first + i > target) continue;
			cout << i << " ";
			pii tmp = make_pair(curr.first + i, i);
			q.push(tmp);
		}
		cout << endl << endl;
	}
	cout << answer;
}
