#include <iostream>

#include <algorithm>
#include <vector>

using namespace std;
void binarySearch(int num);

int N, M;
vector<int> v;
int main() {
	
	cin >> N;
	
	
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		binarySearch(num);
	}
}

void binarySearch(int num) {
	int start = 0;
	int end = N - 1;
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;

		if (v.at(mid) == num) {
			cout << "1\n";
			return;
		}
		else if (v.at(mid) > num) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << "0\n";
	return;
}