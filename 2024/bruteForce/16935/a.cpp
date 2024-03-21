#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rows, cols, rots;
vector<vector<int>> arr;
vector<int>rot;

void print(vector<vector<int>> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int k = 0;  k <v[i].size(); k++) {
			cout <<v[i][k] <<" ";
		}
		cout <<"\n";
	}
}

void f1() {
	int st = 0, ed = rows - 1;
	while (st < ed) {
		vector<int> tmp = arr[st];
		arr[st] = arr[ed];
		arr[ed] = tmp;
		st++;
		ed--;
	}
}

void f2() {
	for (int r = 0; r < rows; r++) {
		int st = 0, ed = cols - 1;
		while (st < ed) {
			swap(arr[r][st], arr[r][ed]);
			st++; ed--;
		}
	}
}

void f3() {
	vector<vector<int>> tmp(cols);
	for (int c = 0; c < cols ; c++) {
		for (int r = rows - 1; r >= 0; r--) {
			tmp[c].push_back(arr[r][c]);
		}
	}
	arr.clear();
	arr.resize(cols);
	arr = tmp;
	swap(rows, cols);
}

void f4() {
	vector<vector<int>> tmp(cols);
	int i = 0;
	for (int c = cols - 1; c >= 0; c--) {
		for (int r = 0; r < rows; r++) {
			tmp[i].push_back(arr[r][c]);
		}
		i++;
	}
	arr.clear();
	arr.resize(cols);
	arr = tmp;
	swap(rows, cols);
}

void f5() {
	vector<vector<int>> tmp(rows);
	for (int i = 0; i <rows; i++) {
		tmp[i].resize(cols);
	}

	int rstd = rows / 2;
	int cstd = cols / 2;

	for (int r = 0; r < rstd; r++) {
		for (int c = 0; c < cstd; c++) {
			tmp[r][c] = arr[r + rstd][c];
		}
	}

	for (int r = 0; r < rstd; r++) {
		for (int c = cstd; c < cols; c++) {
			tmp[r][c] = arr[r][c - cstd];
		}
	}

	for (int r = rstd; r < rows; r++) {
		for (int c = 0; c < cstd; c++) {
			tmp[r][c] = arr[r][c + cstd];
		}
	}

	for (int r = rstd; r < rows; r++) {
		for (int c = cstd; c < cols; c++) {
			tmp[r][c] = arr[r - rstd][c];
		}
	}

	arr = tmp;
}

void f6() {
	vector<vector<int>> tmp(rows);
	for (int i = 0; i <rows; i++) {
		tmp[i].resize(cols);
	}

	int rstd = rows / 2;
	int cstd = cols / 2;

	for (int r = 0; r < rstd; r++) {
		for (int c = 0; c < cstd; c++) {
			tmp[r][c] = arr[r][c + cstd];
		}
	}

	for (int r = 0; r < rstd; r++) {
		for (int c = cstd; c < cols; c++) {
			tmp[r][c] = arr[r + rstd][c];
		}
	}

	for (int r = rstd; r < rows; r++) {
		for (int c= 0; c < cstd; c++) {
			tmp[r][c] = arr[r - rstd][c];
		}
	}

	for (int r = rstd; r <rows; r++) {
		for (int c = cstd; c < cols; c++) {
			tmp[r][c] = arr[r][c - cstd];
		}
	}

	arr = tmp;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> rows >> cols >>rots;
	arr.resize(rows);

	for (int i = 0, tmp; i < rows; i++) {
		for (int k = 0; k < cols; k++) {
			cin >> tmp;
			arr[i].push_back(tmp);
		}
	}

	for (int i = 0, tmp; i < rots; i++) {
		cin >> tmp;
		if (tmp == 1) f1();
		else if (tmp == 2) f2();
		else if (tmp == 3) f3();
		else if (tmp == 4) f4();
		else if (tmp == 5) f5();
		else if (tmp == 6) f6();
	}

	print(arr);
}
