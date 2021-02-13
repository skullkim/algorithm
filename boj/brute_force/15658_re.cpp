#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

const int MAX = 30;
int n, max_ans = INT_MAX * -1, min_ans = INT_MAX, max_idx;
int nums[MAX], op[MAX];
vector<int> v(4);

void f(int cur){
	if(cur > max_idx){
		int tmp = nums[1];
		for(int i = 2; i <= max_idx; i+= 2){
			if(op[i] == 0) tmp += nums[i + 1];
			else if(op[i] == 1) tmp -= nums[i + 1];
			else if(op[i] == 2) tmp *= nums[i + 1];
			else if(op[i] == 3) tmp /= nums[i + 1];
		}
		max_ans = max(max_ans, tmp);
		min_ans = min(min_ans, tmp);
		return;
	}
	for(int i = 0; i < 4; i++){
		if(v[i] == 0) continue;
		op[cur] = i;
		v[i]--;
		f(cur + 2);
		v[i]++;
		op[cur] = -1;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	v.resize(n);
	for(int i = 1; i <= n; i++){
		cin >> nums[2*i - 1];
	}
	max_idx = 2 * n - 1;
	// for(int i = 1; i <= max_idx; i++){
	// 	cout << i << " " << nums[i] << endl;
	// }
	memset(op, -1, sizeof(op));
	for(int i = 0; i < 4; i++){
		cin >> v[i];
	}
	f(2);
	cout << max_ans << "\n" << min_ans;
}