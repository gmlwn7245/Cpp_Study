#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int bridge[N];
	int leftDP[N];
	int rightDP[N];

	for (int i = 0; i < N; i++) {
		cin >> bridge[i];
		leftDP[i] = 1;
		rightDP[i] = 0;
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (bridge[j] > bridge[i]) {
				leftDP[j] = max(leftDP[i] + 1, leftDP[j]);
			}

		}
	}

	for (int i = N - 1; i > 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (bridge[j] > bridge[i]) {
				rightDP[j] = max(rightDP[i] + 1, rightDP[j]);
			}
		}
	}

	int maxStep = 0;

	for (int i = 0; i < N; i++) {
		maxStep = max(maxStep, leftDP[i] + rightDP[i]);
	}

	cout << maxStep;
	return 0;
}