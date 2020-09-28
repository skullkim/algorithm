#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int brothers, curr_loc, brother;
	vector<int> distance;
	cin >> brothers >> curr_loc;
	for(int i = 0; i < brothers; i++){
		cin >> brother;
		distance.push_back(abs(brother - curr_loc));
	}
	int max_move = distance[0];
	for(int i = 1; i < distance.size(); i++){
		max_move = gcd(distance[i], max_move);
	}
	cout << max_move;
}
