#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	vector<int> arr(n);
	vector<int> dp(k + 1);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 0원 -> 아무 동전도 선택하는 경우 1가지
	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		// 각 동전마다 진행
		// 동전의 값 미만은 경우의 수 0

		for (int j = arr[i]; j <= k; j++) {
			// j=7이고 arr[i] = 2 이면, 2 1개고정에 나머지 5를 만들 수 있는 경우의 수를 더해줌
			// 그게 2 x 3개 + 1 x 1개 이던, 2 x 1개 + 5 x 1개 이든, 앞에 모든 경우의 수가 나타남
			dp[j] += dp[j - arr[i]];
		}
	}
	cout << dp[k];
}