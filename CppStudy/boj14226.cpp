#include <iostream>
#include <queue>

using namespace std;


// ���� ���� X
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int s;
	cin >> s;

	// 1�� ���ֱ�
	// ȭ�鿡 �ִ� �̸�Ƽ�� ���� ��ŭ Ŭ�����忡 ���ϱ�
	// ȭ�鿡 Ŭ������ 

	int ans = 2000;
	int dp[1000] = {2000, };

	// first = { ��Ƽ ����, �ð� }
	// second = ȭ�鿡 �ִ��� 
	queue<pair<pair<int, int>, bool>> q;
	q.push({ {1,0},true });
	
	dp[1] = 1;
	
	while (!q.empty()) {
		pair<int, int> p = q.front().first;
		bool isDisplay = q.front().second;

		q.pop();
		
		if (isDisplay) {

		}
		else {

		}
	}
	
}