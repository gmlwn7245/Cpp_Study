#include<stdio.h>
#include<queue>
#include<algorithm>

#define MAX 500
using namespace std;
int M, N;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
   
int map[MAX][MAX];
int dp[MAX][MAX];

bool visited[MAX][MAX];

bool isInArea(int x, int y) {
	return x < M && x >= 0 && y < N&& y >= 0;
}

int dfs(int x, int y) {
	if (x == M - 1 && y == N - 1) {
		return -1;
	}

}


int main() {
	scanf_s("%d %d", &M, &N);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &map[i][j]);
		}
	}
}