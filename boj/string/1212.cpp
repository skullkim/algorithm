#include <iostream>
#include <string>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string oct_to_bi[] {
		"000", "001", "010", "011", "100", "101", "110", "111", "1000", "1001"
	};
	string oct, ans = "";
	cin >> oct;
	if(oct == "0"){
		cout << 0;
		return 0;
	}
	for(int i = 0; i < oct.size(); i++){
		if(i == 0 && oct_to_bi[oct[i] - '0'][0] == '0'){
			int k = 0;
			while(k < oct_to_bi[oct[i] - '0'].size() && oct_to_bi[oct[i] - '0'][k] != '1') k++;
			for(; k < oct_to_bi[oct[i] - '0'].size(); k++){
				ans += oct_to_bi[oct[i] - '0'][k];
			}
		}
		else ans += oct_to_bi[oct[i] - '0'];
	}
	cout << ans;
}
