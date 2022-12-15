#include <iostream>
#include <vector>

using namespace std;

int map[1001][1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	

	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		
		for (int j = 0; j < m; j++) {
			map[i][j+1] = str.at(j) - '0';
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0)
				continue;

			map[i][j] = min(min( map[i - 1][j - 1], map[i - 1][j]), map[i][j - 1] ) + 1;

			ans = max(ans, map[i][j]);
		}
	}

	ans *= ans;
	cout << ans;
}
