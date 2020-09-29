#include <iostream>
#include <algorithm>
using namespace std;

int countNum(int limit, const int target){
	int cnt = 0;
	for(long long i = target; i <= limit; i *= target) cnt += (limit / i);
	return cnt;
}

int main(void){
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	 const int FIVE = 5;
	 const int TWO = 2;
	 int n, m;
	 cin >> n >> m;
	 int five_num = countNum(n, FIVE) - countNum(m, FIVE) - countNum(n - m, FIVE);
	 int two_num = countNum(n, TWO) - countNum(m, TWO) - countNum(n - m, TWO);
	 cout << min(five_num, two_num);
}
