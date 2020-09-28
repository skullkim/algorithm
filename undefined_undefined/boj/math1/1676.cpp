#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int max_num;
	cin >> max_num;
	int cnt2 = 0, cnt5 = 0;
	for(int two = 2; two <= max_num; two *= 2) cnt2 += (max_num / two);
	for(int five = 5; five <= max_num; five *= 5) cnt5 += (max_num / five);
	cout << min(cnt2, cnt5);
}
