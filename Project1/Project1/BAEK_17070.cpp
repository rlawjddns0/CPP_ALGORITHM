#include<iostream>
using namespace std;
int state;
int dx[] = { 1,1,0 };
int dy[] = { 0,1,1 };
int N;
int map[17][17];
int cnt;
void solve(int y, int x, int state);
using namespace std;
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	map[0][0] = 2;
	map[0][1] = 2;//파이프 2 놓기 시작 위치
	state = 0;//0:가로 , 1:대각선, 2:세로

	solve(0, 1, 0);
	
	
	cout << cnt;



	return 0;
}

void solve(int y, int x, int state) {
	if (y == N - 1 && x == N - 1) {//도착했으면
		map[y][x] = 2;
		cout << "\n";

		print();
		cout << "\n";
		cnt++;

		return;
	}
	
	if (state == 0) {//지금 상태가 가로로 놓여 있으면
		for (int d = 0; d < 2; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
			if (d == 0 && map[ny][nx] == 0) {
				map[ny][nx] = 2;
				solve(ny, nx, d);
				map[ny][nx] = 0;
			}
			if (d == 1) {
				bool flag = true;
				for (int d1 = 0; d1 < 3; d1++) {
					int nx1 = x + dx[d1];
					int ny1 = y + dy[d1];
					if (nx1 < 0 || nx1 >= N || ny1 < 0 || ny1 >= N)continue;
					if (map[ny1][nx1] == 1) {
						flag = false;
						break;
					}
				}
				if (flag) {
					map[ny][nx] = 2;
					solve(ny, nx, d);
					map[ny][nx] = 0;
				}
			}
			
		}
	}
	else if (state == 1) {//지금 상태가 대각선으로 놓여 있으면ㅇ
		for (int d = 0; d < 3; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
			if (d == 0 && map[ny][nx] == 0) {
				map[ny][nx] = 2;
				solve(ny, nx, d);
				map[ny][nx] = 0;
			}
			if (d == 1) {
				bool flag = true;
				for (int d1 = 0; d1 < 3; d1++) {
					int nx1 = x + dx[d1];
					int ny1 = y + dy[d1];
					if (nx1 < 0 || nx1 >= N || ny1 < 0 || ny1 >= N)continue;
					if (map[ny1][nx1] == 1) {
						flag = false;
						break;
					}
				}
				if (flag) {
					map[ny][nx] = 2;
					solve(ny, nx, d);
					map[ny][nx] = 0;
				}
			}
			if (d == 2 && map[ny][nx] == 0) {
				map[ny][nx] = 2;
				solve(ny, nx, d);
				map[ny][nx] = 0;
			}
		}

	}
	else if (state == 2) {//지금 상태가 세로로 놓여있으면
		for (int d = 1; d < 3; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
			if (d == 2 && map[ny][nx] == 0) {
				map[ny][nx] = 2;
				solve(ny, nx, d);
				map[ny][nx] = 0;
			}
			if (d == 1) {
				bool flag = true;
				for (int d1 = 0; d1 < 3; d1++) {
					int nx1 = x + dx[d1];
					int ny1 = y + dy[d1];
					if (nx1 < 0 || nx1 >= N || ny1 < 0 || ny1 >= N)continue;
					if (map[ny1][nx1] == 1) {
						flag = false;
						break;
					}
				}
				if (flag) {
					map[ny][nx] = 2;
					solve(ny, nx, d);
					map[ny][nx] = 0;
				}
			}
		}
	}

	return;

}