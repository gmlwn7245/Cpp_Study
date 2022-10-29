#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	vector<int> dp(k + 1);


	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	dp[0] = 0;

	for (int i = 1; i <= k; i++) {
		dp[i]=100001;
	}

	for (int i = 0; i < n; i++) {
		dp[v[i]] = 1;
	}


	for (int i = 0; i < n; i++) {
		for (int j = v[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - v[i]] + 1);
		}
	}


	if (dp[k] == 100001)
		cout << -1;
	else
		cout << dp[k];
}