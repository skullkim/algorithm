#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Range{
	long long start;
	long long end;
};
struct PosRange{
	Range y_range;
	Range x_range;
};
struct Pos{
	long long y;
	long long x;
};
long long max_pos;
int divide_num;
string origin, target = "-1";
PosRange origin_range;
Pos dist, origin_pos, target_pos;

//void findOriginPosition(const int& rest_divide, const string& curr_pos_num, const Pos& curr_pos, long long gap){
//	static bool has_ans = false;
//	if(gap == 0) return;
//	if(0 >= curr_pos.y || curr_pos.y > max_pos || 0 >= curr_pos.x || curr_pos.x > max_pos) return;
//	if(rest_divide == 0 && curr_pos_num == origin){
//		origin_pos = curr_pos;
//		has_ans = true;
//		return;
//	}
//	if(rest_divide == 0) return;
//	gap = gap >> 1LL;
//	if(!has_ans) findOriginPosition(rest_divide - 1, curr_pos_num + "1", {curr_pos.y, curr_pos.x}, gap);
//	if(!has_ans) findOriginPosition(rest_divide - 1, curr_pos_num + "2", {curr_pos.y, curr_pos.x - gap}, gap);
//	if(!has_ans) findOriginPosition(rest_divide - 1, curr_pos_num + "3", {curr_pos.y + gap, curr_pos.x - gap}, gap);
//	if(!has_ans) findOriginPosition(rest_divide - 1, curr_pos_num + "4", {curr_pos.y + gap, curr_pos.x}, gap);
//}
//
//void findTargetPosition(const string& curr_pos_num, const Pos& curr_pos, long long gap, const int& rest_divide){
//	static bool has_ans = false;
//	if(gap == 0) return;
//	if(rest_divide == 0){
//		has_ans = true;
//		return;
//	}
//	if(0 >= curr_pos.y || curr_pos.y > max_pos || 0 >= curr_pos.x || curr_pos.x > max_pos) return;
//	if(curr_pos.y == target_pos.y && curr_pos.x == target_pos.x){
//		target = curr_pos_num;
//		has_ans = true;
//		return;
//	}
//	gap = gap >> 1LL;
//	if(!has_ans && rest_divide > 0) findTargetPosition(curr_pos_num + "1", {curr_pos.y, curr_pos.x}, gap, rest_divide - 1);
//	if(!has_ans && rest_divide > 0) findTargetPosition(curr_pos_num + "2", {curr_pos.y, curr_pos.x - gap}, gap, rest_divide - 1);
//	if(!has_ans && rest_divide > 0) findTargetPosition(curr_pos_num + "3", {curr_pos.y + gap, curr_pos.x - gap}, gap, rest_divide - 1);
//	if(!has_ans && rest_divide > 0) findTargetPosition(curr_pos_num + "4", {curr_pos.y + gap, curr_pos.x}, gap, rest_divide - 1);
//	
//}

void findOriginPosition(const string& origin_num, const PosRange& curr_pos_range, const int& div_num){
	static bool has_ans = false;
//	if(range.x < 0 && range.y < 0) return;
	if(div_num == 0 && origin_num == origin){
		origin_range = curr_pos_range;
		has_ans = true;
		return;
	}
	if(div_num <= 0) return;
	long long next_range_x = (curr_pos_range.x_range.start + curr_pos_range.y_range.end) / 2;
	long long next_range_y = (curr_pos_range.y_range.start + curr_pos_range.y_range.end) / 2; 
	if(!has_ans) findOriginPosition(origin_num + "1", {{curr_pos_range.x_range.start, next_range_x}, {next_range_y + 1, curr_pos_range.y_range.end}}, div_num - 1);	
	if(!has_ans) findOriginPosition(origin_num + "2", {{curr_pos_range.x_range.start, next_range_x}, {curr_pos_range.y_range.start, next_range_y}}, div_num - 1);	
	if(!has_ans) findOriginPosition(origin_num + "3", {{next_range_x + 1, curr_pos_range.x_range.end}, {curr_pos_range.y_range.start, next_range_y}}, div_num - 1);	
	if(!has_ans) findOriginPosition(origin_num + "4", {{next_range_x + 1, curr_pos_range.x_range.end}, {next_range_y + 1, curr_pos_range.y_range.end}}, div_num - 1);	
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> divide_num >> origin;
	cin >> dist.x >> dist.y;
	max_pos = pow(2, divide_num);
	findOriginPosition("", {{0, max_pos}, {0, max_pos}}, divide_num);
	cout << origin_range.x_range.start << " " << origin_range.x_range.end << " " << origin_range.y_range.start << " " << origin_range.y_range.end << endl;
//	dist.y < 0 ? target_pos.y = origin_pos.y + abs(dist.y) : target_pos.y = origin_pos.y + dist.y * -1;
//	target_pos.x = origin_pos.x + dist.x;
//	if(0 >= target_pos.y || target_pos.y > max_pos || 0 > target_pos.x || target_pos.x > max_pos){
//		cout << -1;
//		return 0;
//	}
//	target == "-1" ? cout << -1 : cout << target;
}
