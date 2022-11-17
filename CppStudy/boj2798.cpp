#include <iostream>
#include <vector>

using namespace std;

int N, M;
int main() {
	cin >> N >> M;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	bool isFind = false;
	int ans = 0;
	for (int i = N - 1; i >= 2; i--) {
		for (int j = i - 1; j >= 1; j--) {
			for (int k = j - 1; k >= 0; k--) {
				int sum = v[i] + v[j] + v[k];
				if (sum <= M) {
					ans = max(ans, sum);
				}
			}
		}
	}
	cout << ans;
}