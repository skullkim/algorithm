#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct S {
    int st;
    int ed;
    vector<int> v;
};

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<S> vs;
    int st = 0, en = 0, sum = sequence[st];
    while(st < sequence.size()) {
        if (st == en && en < sequence.size()) {
            en++;
            continue;
        }
		cout << st << " " << en << " " << sum << endl << endl;
        if (sum < k && en < sequence.size()) {
            sum += sequence[en];
            en++;
        }
        else if (sum > k || en >= sequence.size()) {
            sum -= sequence[st];
            st++;
        }
		if (sum == k) {
            vector<int> tv;
            for (int i = st; i < en; i++) tv.push_back(sequence[i]);
            S tmp = {st, en - 1, tv};
            vs.push_back(tmp);
			en++;
        }
    }
    for (int i = 0; i < vs.size(); i++) {
        cout << vs[i].st << " " << vs[i].ed << endl;
        for(int k = 0; k < vs[i].v.size(); k++) {
            cout << vs[i].v[k] << " ";
        }
        cout << endl;
    }
    return answer;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	vector<int> s;
	cin >> n;
	for (int i =0; i < n; i++) {
		int tmp;
		cin >> tmp;
		s.push_back(tmp);
	}
	int k;
	cin >> k;
	vector<int> ans = solution(s, k);
}
