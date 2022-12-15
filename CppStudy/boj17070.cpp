#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int cnt = 0;
int n = 0;

int map[17][17];
void bfs();

void bfs();
bool isInArea(int x, int y);
bool checkSide(int x, int y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	bfs();
	cout << cnt;
}

void bfs() {
	// 0 →, 1 ↘, 2 ↓ 

	// d[현재 방향][갈 수 있는 방향 3가지]
	int nMap[3][3]{ {0,1,-1},{0,1,2},{1,2,-1} };
	
	// d[방향][좌표]
	int dMap[3][2]{ {0,1},{1,1},{1,0} };


	queue<pair<pair<int, int>, int>> q;
	q.push({ {1,2},0 });

	while (!q.empty()) {
		pair<pair<int, int>,int> node = q.front();
		q.pop();
		//cout << "qsize" << q.size() << endl;
		//cout << "qemtpy" << q.empty() << endl;

		int nowDir = node.second;

		for (int i = 0; i < 3; i++) {
			int dir = nMap[nowDir][i];

			if (dir == -1)
				continue;

			int nx = node.first.first + dMap[dir][0];
			int ny = node.first.second + dMap[dir][1];


			if (!isInArea(nx, ny))
				continue;

			if (map[nx][ny] == 1)
				continue;

			if (dir == 1 && !checkSide(nx, ny))
				continue;

			if (nx == n && ny == n) {
				cnt++;
				continue;
			}
			//cout << nx << " " << ny << " ==> " << map[nx][ny] << endl;
			q.push({ {nx, ny},dir });
		}

	}
}

bool checkSide(int x, int y) {
	return map[x - 1][y] == 0 && map[x][y - 1] == 0;
}

bool isInArea(int x, int y) {
	return x > 0 && x <= n && y > 0 && y <= n;
}