#include <iostream>

using namespace std;

int dp[1001];
int num[1001];

int main() {
	int N;
	cin >> N;

	int ans = 1;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		dp[i] = 1;
		for (int j = i-1; j >= 0; j--) {
			if (num[j] < num[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
				ans = max(ans, dp[j]+1);
			}
		}
	}

	
	cout << ans;
}