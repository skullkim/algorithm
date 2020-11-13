#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string bi_num;
	string oct_num = "";
	cin >> bi_num;
	for(int i = bi_num.size() - 1; i >= 0; i -= 3){
		int tmp = 0;
		if(i - 3 > 0){
			for(int k = 2; k >= 0; k--) tmp += ((bi_num[i - k] - '0') * pow(2, k));
		}	
		else{
			if(i - 3 == -2){
				for(int k = 1; k >= 0; k--) tmp += ((bi_num[i - k] - '0') * pow(2, k));
			}	
			else if(i - 3 == -3){
				tmp += ((bi_num[i] - '0') * pow(2, 0));
			}
		}
		oct_num += to_string(tmp);
	}
	for(int i = oct_num.size() - 1; i >= 0; i--) cout << oct_num[i];
}
