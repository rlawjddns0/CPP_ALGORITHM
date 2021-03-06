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
			priority_queue <enemy,vector<enemy>,compare> pq;//���� �����鼭 ���ʿ� �ִ� ��
			set<pair<int, int>> v;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < tn; j++) {
					for (int k = 0; k < M; k++) {
						if (map[j][k] == 1) {
							if ((abs(archer - j) + abs(sel[i] - k)) <= D) {//D������ �Ÿ��� �ִ� �� �� ���
								enemy tmp;
								tmp.x = k;
								tmp.y = j;
								tmp.d = abs(archer - j) + abs(sel[i] - k);
								pq.push(tmp);//�����鼭 �˾Ƽ� �� 
							}
						}
					}
				}
				if (pq.size() == 0)continue;//D������ �Ÿ��� ���� ���� ����̹Ƿ� ���� �ü���
				v.insert({ pq.top().y,pq.top().x });//���ؼ� �� ���� �ִ¾� set�� �Է�
				while (!pq.empty()) {//�������� �ʿ� ����
					pq.pop();
					
				}
			}
			archer--;//�ü� ��ġ ���� ��ĭ �÷��ְ�
			tn--;//Ž�� ������ ��ġ�� ��ĭ �÷���
			cnt += v.size();//set�� �ִ°� �׿����� �� ->set�� ���� ���� �ߺ� ����
			for (auto it = v.begin(); it != v.end(); ++it) {
				map[(*it).first][(*it).second] = 0;//set ���鼭 �� ���̱�
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