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

	// 0�� -> �ƹ� ������ �����ϴ� ��� 1����
	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		// �� �������� ����
		// ������ �� �̸��� ����� �� 0

		for (int j = arr[i]; j <= k; j++) {
			// j=7�̰� arr[i] = 2 �̸�, 2 1�������� ������ 5�� ���� �� �ִ� ����� ���� ������
			// �װ� 2 x 3�� + 1 x 1�� �̴�, 2 x 1�� + 5 x 1�� �̵�, �տ� ��� ����� ���� ��Ÿ��
			dp[j] += dp[j - arr[i]];
		}
	}
	cout << dp[k];
}