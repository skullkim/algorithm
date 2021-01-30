#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	list<int> l;
	for(int i = 1; i <= n; i++){
		l.push_back(i);	
	}
	vector<int> v;	
	auto s = l.begin();
	while(!l.empty()){
		for(int i = 0; i < k - 1; i++){
			s++;
			if(s == l.end()) s = l.begin();
		}
		v.push_back(*s);
		s = l.erase(s);
		if(s == l.end()) s = l.begin();
	}
	cout << "<";
	for(int i = 0; i < v.size(); i++){
		if(i + 1 == v.size()) cout << v[i];
		else cout << v[i] << ", ";
	}
	cout << ">";
}