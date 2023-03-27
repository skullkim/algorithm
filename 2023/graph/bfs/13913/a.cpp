#include <bits/stdc++.h>
using namespace std;

const int MAX = 100100;
int meP, broP;
bool vi[MAX];
int distances[MAX], path[MAX];

void print(int idx) {
	if (idx != meP) {
		print(path[idx]);
	}
	cout << idx << " ";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> meP >> broP;
	queue<int> q;
	q.push(meP);
	vi[meP] = true;
	while(!q.empty()) {
		int pos = q.front();
		q.pop();
		int arr[] = {pos + 1, pos -1, pos * 2};
		for (int i = 0; i < 3; i++) {
			int nextP = arr[i];
			if (0 > nextP || nextP > 100000 || vi[nextP]) continue;
			vi[nextP] = true;
			distances[nextP] = distances[pos] + 1;
			path[nextP] = pos;
			q.push(nextP);
		}
	}

	cout << distances[broP] << "\n";
	print(broP);
}
