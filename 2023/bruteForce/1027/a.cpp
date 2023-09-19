#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

#define INF 1000100000;

struct Position {
	int x;
	int y;
};

double calculateInclination (Position pos1, Position pos2) {
	return (double)(pos2.y - pos1.y) / (pos2.x - pos1.x);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int buildings;
	cin >> buildings;

	vector<Position> positions;
	for (int x = 1, y; x <= buildings; x++) {
		cin >> y;
		Position position = {x, y};
		positions.push_back(position);
	}
	
	vector<int> watchableBuildings(buildings, 0);
	for (int i = 0; i < buildings; i++) {
		double maxInclination = -1.0 * INF;
		for (int k = i + 1; k < buildings; k++) {
			double inclination = calculateInclination(positions[i], positions[k]);
			if (inclination <= maxInclination) continue;
			maxInclination = inclination;
			watchableBuildings[i]++;
			watchableBuildings[k]++;
		}
	}

	int answer = -1;
	for (int i = 0; i < buildings; i++) {
		answer = max(answer, watchableBuildings[i]);
	}
	cout << answer << "\n";
}
