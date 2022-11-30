#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int N, M;
int idx, nums;
vector<int> frame;
map<int, int> cnt;
map<int, int> times;

void findMinIdx();

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		
		// �̹� �����ӿ� ����
		if (find(frame.begin(), frame.end(), num) != frame.end()) {
			cnt[num] += 1;
			continue;
		}

		// �������� �� ���� �ʾ��� ���
		if (frame.size() < N) {
			frame.push_back(num);
			cnt[num] = 1;
			times[num] = i;
			continue;
		}

		// �������� �� á�� ��� 
		findMinIdx();
		
		cnt.erase(nums);
		times.erase(nums);
		frame.erase(frame.begin() + idx);

		frame.push_back(num);
		cnt[num] = 1;
		times[num] = i;
		
	}
	
	sort(frame.begin(), frame.end());

	for (int i = 0; i < frame.size(); i++) {
		cout << frame[i] << " ";
	}
}

// cnt ���� �� ã��
void findMinIdx() {
	int minCnt = INT_MAX;
	int minTime = INT_MAX;
	int ansIdx = 0;
	int ansNum = 0;

	
	for (int i = 0; i < frame.size(); i++) {
		cout << "fin"<<i<<"\n";
		int c = cnt.at(frame[i]);
		int t = times.at(frame[i]);
		if (c == minCnt && minTime > t) {
			minTime = t;
			ansIdx = i;
			ansNum = frame[i];
		}
		else if (c < minCnt) {
			minCnt = c;
			minTime = t;
			ansIdx = i;
			ansNum = frame[i];
		}
	}

	idx = ansIdx;
	nums = ansNum;
}