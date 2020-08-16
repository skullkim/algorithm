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

void findTargetPosition(const long long & max_pos, string ans, Pos curr_target_pos, int range){
	static bool has_ans = false;
	if(0 >= curr_target_pos.y || curr_target_pos.y > max_pos || 0 >= curr_target_pos.x || curr_target_pos.x > max_pos) return;
	if(ans.size() == divide_num){
		target = ans;
		has_ans = true;
		return;
	}
	if(!has_ans && curr_target_pos.y <= range && curr_target_pos.x > range){
		findTargetPosition(max_pos, ans + "1", {curr_target_pos.y, curr_target_pos.x - range}, range / 2);
	}
	if(!has_ans && curr_target_pos.y <= range && curr_target_pos.x <= range){
		findTargetPosition(max_pos, ans + "2", {curr_target_pos.y, curr_target_pos.x}, range / 2);
	}
	if(!has_ans && curr_target_pos.y > range && curr_target_pos.x <= range){
		findTargetPosition(max_pos, ans + "3", {curr_target_pos.y - range, curr_target_pos.x}, range / 2);
	}
	if(!has_ans && curr_target_pos.y > range && curr_target_pos.x > range){
		findTargetPosition(max_pos, ans + "4", {curr_target_pos.y - range, curr_target_pos.x - range}, range / 2);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> divide_num >> origin;
	cin >> dist.x >> dist.y;
	//cout << dist.x << " " << dist.y << endl;
	max_pos = pow(2, divide_num);
	findOriginPosition(divide_num, "", {1, max_pos}, max_pos);
	dist.y < 0 ? target_pos.y = origin_pos.y + abs(dist.y) : target_pos.y = origin_pos.y + dist.y * -1;
	target_pos.x = origin_pos.x + dist.x;
 //	cout << target_pos.y << " " << target_pos.x << endl;
	if(0 >= target_pos.y || target_pos.y > max_pos || 0 > target_pos.x || target_pos.x > max_pos){
		cout << -1;
		return 0;
	}
	findTargetPosition(max_pos, "", target_pos, max_pos / 2);
	target == "-1" ? cout << -1 : cout << target;
}
