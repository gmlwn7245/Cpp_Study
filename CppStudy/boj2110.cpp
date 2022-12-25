#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, C;
int ans = -1;
vector<int> v;

bool check(int mid);
void binSearch();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	if (N == 2) {
		int ans = abs(v.at(0) - v.at(1));
		cout << ans;
		return 0;
	}

	sort(v.begin(), v.end());

	binSearch();
	cout << ans;

}

bool check(int mid) {
	int cnt = 1;
	int prev = v.at(0);

	for (int i = 1; i < N; i++) {
		if (v.at(i) - prev >= mid) {
			cnt++;
			prev = v.at(i);
		}
	}

	if (cnt >= C) return true;
	return false;
}

void binSearch() {
	int left = 0;
	int right = v.back();

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (check(mid)) {
			left = mid + 1;
			if (ans < mid)
				ans = mid;
		}
		else right = mid - 1;
	}
}