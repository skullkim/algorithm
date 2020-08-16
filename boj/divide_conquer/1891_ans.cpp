#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Pos{
	long long y;
	long long x;
};
struct PosRange{
	Pos start;
	Pos end;
};
long long max_pos;
int divide_num;
string origin, target = "-1";
Pos dist, origin_pos, target_pos;

void findOriginPosition(int curr_idx, PosRange pos, int range){
	static bool has_ans = false;
	if(curr_idx > divide_num) return;	
	if(curr_idx == divide_num){
		origin_pos = {pos.start.y, pos.start.x};
		has_ans = true;
		return;
	}
	if(!has_ans && origin[curr_idx] == '1'){
		findOriginPosition(curr_idx + 1, {
			{pos.start.y, pos.start.x + range},
			{pos.end.y - range, pos.end.x}
		}, range / 2);		
	}
	if(!has_ans && origin[curr_idx] == '2'){
		findOriginPosition(curr_idx + 1, {
			{pos.start.y, pos.start.x},
			{pos.end.y - range, pos.end.x - range}
		}, range / 2);	
	}
	if(!has_ans && origin[curr_idx] == '3'){
		findOriginPosition(curr_idx + 1, {
			{pos.start.y + range, pos.start.x},
			{pos.end.y, pos.end.x - range}
		}, range / 2);
	}
	if(!has_ans && origin[curr_idx] == '4'){
		findOriginPosition(curr_idx + 1, {
			{pos.start.y + range, pos.start.x + range},
			{pos.end.y, pos.end.x}
		}, range / 2);
	}
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
	max_pos = pow(2, divide_num);
	Pos start_pos = {1, 1};
	Pos end_pos = {max_pos, max_pos};
	findOriginPosition(0, {start_pos, end_pos}, max_pos / 2);
	dist.y < 0 ? target_pos.y = origin_pos.y + abs(dist.y) : target_pos.y = origin_pos.y + dist.y * -1;
	target_pos.x = origin_pos.x + dist.x;
	if(0 >= target_pos.y || target_pos.y > max_pos || 0 > target_pos.x || target_pos.x > max_pos){
		cout << -1;
		return 0;
	}
	findTargetPosition(max_pos, "", target_pos, max_pos / 2);
	target == "-1" ? cout << -1 : cout << target;
}
