#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> steps;
vector<int> dp;

void getStepNum() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		steps.push_back(num);
	}
}


void setDP() {
	dp[0] = steps[0];
	dp[1] = max(steps[1], steps[0] + steps[1]);
	dp[2] = max(steps[0] + steps[2], steps[1] + steps[2]);

	for (int i = 3; i < n; i++) {
		// 2번째 전 -> 현재 (2칸)
		// 3번째 전 -> 1번째전 (2칸) -> 현재 (1칸) 
		dp[i] = max(dp[i - 2] + steps[i], dp[i - 3] + steps[i - 1] + steps[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getStepNum();

	steps.resize(n + 1);
	dp.resize(n + 1);

	setDP();

	cout << dp.at(n - 1);
}