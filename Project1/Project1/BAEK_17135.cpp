#include<iostream>
#include<queue>
#include<math.h>
#include<vector>
#include<set>
using namespace std;
int N, M, D;
int archer;
int map[16][16];
int tmap[16][16];
int cnt;
int ans;
struct enemy {
	int x;
	int y;
	int d;
};
typedef struct enemy enemy;
struct compare {
	bool operator() (const enemy& L,const enemy& C ) {
		if (C.d == L.d) {
			return C.x < L.x;
		}
		return C.d < L.d;
	}
};

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = tmap[i][j];
		}
	}


}
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout<<map[i][j];
		}
		cout << "\n";
	}
}
void dfs(int sel[], int k, int idx) {
	if (k == 3) {
		init();
		cnt = 0;
		archer = N;
		int tn = N;
		while (true) {
			if (archer == 0)break;
			priority_queue <enemy,vector<enemy>,compare> pq;//가장 가까우면서 왼쪽에 있는 적
			set<pair<int, int>> v;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < tn; j++) {
					for (int k = 0; k < M; k++) {
						if (map[j][k] == 1) {
							if ((abs(archer - j) + abs(sel[i] - k)) <= D) {//D이하인 거리에 있는 적 다 담기
								enemy tmp;
								tmp.x = k;
								tmp.y = j;
								tmp.d = abs(archer - j) + abs(sel[i] - k);
								pq.push(tmp);//담으면서 알아서 비교 
							}
						}
					}
				}
				if (pq.size() == 0)continue;//D이하인 거리에 적이 없는 경우이므로 다음 궁수로
				v.insert({ pq.top().y,pq.top().x });//비교해서 맨 위에 있는애 set에 입력
				while (!pq.empty()) {//나머지는 필요 없음
					pq.pop();
					
				}
			}
			archer--;//궁수 위치 위로 한칸 올려주고
			tn--;//탐색 마지막 위치도 한칸 올려줌
			cnt += v.size();//set에 있는게 죽여야할 적 ->set에 들어가는 순간 중복 제거
			for (auto it = v.begin(); it != v.end(); ++it) {
				map[(*it).first][(*it).second] = 0;//set 돌면서 적 죽이기
			}
		}
		ans = max(ans, cnt);
		return;
	}
	for (int i = idx; i < M; i++) {
		sel[k] = i;
		dfs(sel, k + 1, i + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);


	cin >> N >> M >> D;
	archer = N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			tmap[i][j] = map[i][j];
		}
	}

	dfs(new int[3], 0, 0);
	cout << ans;




	return 0;
}