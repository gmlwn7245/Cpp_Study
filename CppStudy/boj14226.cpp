#include <iostream>
#include <queue>

using namespace std;


// 아직 제출 X
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int s;
	cin >> s;

	int ans = 2000;
	int dp[3000][3000];

	// dp { 개수, 클립 개수 }
	queue<pair<int, int>> q;
	q.push({1,0});
	
	dp[1][0] = 1;
	
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();


		int n = cur.first;
		int c = cur.second;

		if (n == s) {
			cout << dp[n][c] - 1 << "\n";
			break;
		}

		int nC = n;
		if (dp[n][nC] == 0) {
			q.push({ n, nC });
			dp[n][nC] = dp[n][c] + 1;
		}

		if (n + c <= s) {
			if (dp[n + c][c] == 0) {
				q.push({ n + c,c });
				dp[n + c][c] = dp[n][c] + 1;
			}
		}

		if (n > 0) {
			if (dp[n - 1][c] == 0) {
				q.push({ n - 1, c });
				dp[n - 1][c] = dp[n][c] + 1;
			}
		}
	}
	
}