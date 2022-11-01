#include <iostream>
#include <algorithm>

#define MAX 1000001;

using namespace std;

int main() {
	int n;
	cin >> n;

	int minNum = MAX;
	int maxNum = -MAX;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		minNum = min(minNum, num);
		maxNum = max(maxNum, num);
	}

	cout << minNum << " " << maxNum;
}