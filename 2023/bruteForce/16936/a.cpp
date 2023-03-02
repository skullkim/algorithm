#include <iostream>
#include <vector>
#include <cstring>
#define ll long long

using namespace std;

const int MAX_IDX = 110;
int n;
bool vi[MAX_IDX];
bool hasAns, fail;
vector<ll> seq;

int findEleIdx(ll num) {
	ll val = -1;
	for (int i = 0; i < n; i++) {
		if (!vi[i] && seq[i] == num) {
			val = i;
			break;
		}
	}
	return val;
}

int canD3(ll currNum) {
	ll val = findEleIdx(currNum / 3);
	if (currNum % 3 == 0 && val != -1) {
		return val;
	}
	return -1;
}

int canM2(ll currNum) {
	return findEleIdx(currNum * 2);
}

void f(int idx, vector<ll> ans) {
	vi[idx] = true;
	if (fail) return;
	ll currNum = seq[idx];
	ans.push_back(currNum);
	if (ans.size() == n) {
		for (int i = 0; i < n; i++) cout << ans[i] << " ";
		hasAns = true;
		return;
	}

	ll d3Idx = canD3(currNum);
	ll m2Idx = canM2(currNum);
//	cout << "d3: " << "currNum: " << currNum << ", " << "d3Idx: " << d3Idx << " ";
//	cout << "m2: " << "m2Idx: " << m2Idx << "\n"; 
	if (d3Idx != -1 && !hasAns && !fail) f(d3Idx, ans);
	if (m2Idx != -1 && !hasAns && !fail) f(m2Idx, ans);
	fail = true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	ll tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		seq.push_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		vector<ll> ans;
//		cout << seq[i] << endl;
		f(i, ans);
		if (hasAns) return 0;
		fail = false;
		ans.clear();
		memset(vi, false, sizeof(vi));
	}
}
