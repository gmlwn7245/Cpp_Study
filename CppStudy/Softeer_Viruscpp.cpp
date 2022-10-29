#include<stdio.h>

using namespace std;

long long mod = (long long)1e9 + 7;

int main(int argc, char** argv)
{
	long long P, K, N;

	scanf("%d %d %d", &K, &P, &N);

	while (N--) {
		K = (K * P) % mod;
	}

	printf("%d", K);
	return 0;
}