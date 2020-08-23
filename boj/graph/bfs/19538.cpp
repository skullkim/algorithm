#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX_MAN = 2e5 + 10;
int people, started_people;
vector<vector<int>> graph(MAX_MAN);
vector<int> rumor_time(MAX_MAN, -1);

bool trustRumor(int person){
	int believe = 0, total_people = graph[person].size();
	for(int p = 0; p < total_people; p++){
		if(rumor_time[graph[person][p]] != -1) believe++;
	}
	int tp = total_people / 2;
	if(total_people % 2 == 0){
		return believe >= tp ? true : false;
	}
	else{
		return believe > tp ? true : false;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> people;
	int person; 
	for(int p = 1; p <= people; p++){
		while(true){
			cin >> person;
			if(person == 0) break;
			graph[p].push_back(person);
		}
	}
	cin >> started_people;
//	memset(rumor_time, -1, sizeof(rumor_time));
	int tmp;
	queue<int> curr_rumor;
	for(int p = 0; p < started_people; p++){
		cin >> tmp;
		rumor_time[tmp] = 0;
		curr_rumor.push(tmp);
	}
	int time = 0;
	while(!curr_rumor.empty()){
		queue<pair<int, int>> trust;
		int curr_person = curr_rumor.front();
		curr_rumor.pop();
		time++;
		for(int i = 0; i < graph[curr_person].size(); i++){
			int next_person = graph[curr_person][i];
			if(rumor_time[next_person] != -1) continue;
			if(trustRumor(next_person)){
				pair<int, int> tmp = {next_person, curr_person};
				trust.push(tmp);
				//rumor_time[next_person] = time;
				curr_rumor.push(next_person);
			}
		}
		while(!trust.empty()){
			rumor_time[trust.front().first] = rumor_time[trust.front().second] + 1;
			trust.pop();
		}
	}
	for(int p = 1; p <= people; p++) cout << rumor_time[p] << " ";
}
