#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Pos{
	long long y;
	long long x;
};
long long max_pos;
int divide_num;
string origin, target = "-1";
Pos dist, origin_pos, target_pos;

void findOriginPosition(int rest_divide, string curr_pos_num, Pos curr_pos, long long gap){
	static bool has_ans = false;
	if(gap == 0) return;
	if(0 >= curr_pos.y || curr_pos.y > max_pos || 0 >= curr_pos.x || curr_pos.x > max_pos) return;
	if(rest_divide == 0 && curr_pos_num == origin){
		//cout << curr_pos_num << " " << origin << endl;
		origin_pos = curr_pos;
		has_ans = true;
		return;
	}
	if(rest_divide == 0) return;
	gap /= 2;
	if(!has_ans) findOriginPosition(rest_divide - 1, curr_pos_num + "1", {curr_pos.y, curr_pos.x}, gap);
	if(!has_ans) findOriginPosition(rest_divide - 1, curr_pos_num + "2", {curr_pos.y, curr_pos.x - gap}, gap);
	if(!has_ans) findOriginPosition(rest_divide - 1, curr_pos_num + "3", {curr_pos.y + gap, curr_pos.x - gap}, gap);
	if(!has_ans) findOriginPosition(rest_divide - 1, curr_pos_num + "4", {curr_pos.y + gap, curr_pos.x}, gap);
}

bool isCorrectTarget(Pos curr_pos){
	Pos gap = {abs(origin_pos.y - curr_pos.y), abs(origin_pos.x - curr_pos.x)};
	if(gap.y == abs(dist.y) && gap.x == abs(dist.x)){
		if(dist.y < 0) dist.y *= -1;
		if(dist.x < 0) dist.x *= -1;
		if(curr_pos.y - origin_pos.y == dist.y && curr_pos.x - origin_pos.x == dist.x) return true;
	}
	return false;
}

void findTargetPosition(string curr_pos_num, Pos curr_pos, long long gap, int rest_divide){
	static bool has_ans = false;
	if(gap == 0 || rest_divide == 0) return;
	if(0 >= curr_pos.y || curr_pos.y > max_pos || 0 >= curr_pos.x || curr_pos.x > max_pos) return;
	//cout << curr_pos_num << endl;
	if(isCorrectTarget(curr_pos)){
		//cout << curr_pos.y << " " << curr_pos.x << endl;
		target = curr_pos_num;
		has_ans = true;
		return;
	}
	gap /= 2;
	if(!has_ans && rest_divide > 0) findTargetPosition(curr_pos_num + "1", {curr_pos.y, curr_pos.x}, gap, rest_divide - 1);
	if(!has_ans && rest_divide > 0) findTargetPosition(curr_pos_num + "2", {curr_pos.y, curr_pos.x - gap}, gap, rest_divide - 1);
	if(!has_ans && rest_divide > 0) findTargetPosition(curr_pos_num + "3", {curr_pos.y + gap, curr_pos.x - gap}, gap, rest_divide - 1);
	if(!has_ans && rest_divide > 0) findTargetPosition(curr_pos_num + "4", {curr_pos.y + gap, curr_pos.x}, gap, rest_divide - 1);
	
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> divide_num >> origin;
	cin >> dist.x >> dist.y;
	//cout << dist.x << " " << dist.y << endl;
	max_pos = pow(2, divide_num);
	findOriginPosition(divide_num, "", {1, max_pos}, max_pos);
	findTargetPosition("", {1, max_pos}, max_pos, 50);
//cout << origin_pos.y << " " << origin_pos.x;
	target == "-1" ? cout << -1 : cout << target;
}
