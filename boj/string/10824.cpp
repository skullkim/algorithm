#include <iostream>
#include <string>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string tmp;
	string ab = "", cd = "";
	for(int i = 0; i < 2; i++){
		cin >> tmp;
		ab += tmp;
	}
	for(int i = 0; i < 2; i++){
		cin >> tmp;
		cd += tmp;
	}
	cout << stoll(ab) + stoll(cd);
}
