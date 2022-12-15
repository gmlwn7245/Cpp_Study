#include <iostream>
#include <queue>

using namespace std;


// 아직 제출 X
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int s;
	cin >> s;

	// 1개 없애기
	// 화면에 있는 이모티콘 개수 만큼 클립보드에 더하기
	// 화면에 클립보드 

	int ans = 2000;
	int dp[1000] = {2000, };

	// first = { 임티 개수, 시간 }
	// second = 화면에 있는지 
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