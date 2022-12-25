#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int mod = 1000000;
	int N;
	cin >> N;

	N++;

	int sum = 0;

	queue<pair<int, int>> q;
	q.push({ 0,0 });

	while (!q.empty()) {
		int oCnt = q.front().first;
		int sCnt = q.front().second;
		q.pop();

		for (int i = 1; i <= 3; i++) {
			int noCnt = oCnt + 1;
			int nsCnt = sCnt + i;

			if (nsCnt == N) {
				sum += noCnt % mod;
				break;
			}
			
			q.push({ noCnt, nsCnt });
		}
	}
	sum %= mod;
	cout << sum;
}