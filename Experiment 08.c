/*
Knapsack Problem
Problem Description:
Given the weights and values of N objects, place them in a bag with a capacity of W to calculate the bag's maximum possible total value. To put it another way, given are two integer arrays, val[0..N-1] and wt[0..N-1], which, respectively, represent values and weights connected to N items.
Additionally, given an integer W that represents the capacity of a knapsack, determine the largest value subset of val[] such that the total of its weights is less than or equal to W. An item cannot be broken; you must either pick it in its entirety or not at all (0-1 property).
*/

#include <stdio.h>

int max(int a, int b) {
	return (a > b) ? a : b;
}

int knapsack(int N, int val[], int wt[], int W) {
	int dp[N + 1][W + 1];
	for (int i = 0; i <= N; i++) {
		for (int w = 0; w <= W; w++) {
			if (i == 0 || w == 0) {
				dp[i][w] = 0;
			} else if (wt[i - 1] <= w) {
				dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
			} else {
				dp[i][w] = dp[i - 1][w];
			}
		}
	}
	return dp[N][W];
}

int main() {
	int N, W;
	scanf("%d", &N);
	int val[N], wt[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &val[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &wt[i]);
	}
	scanf("%d", &W);
	printf("%d\n", knapsack(N, val, wt, W));
	return 0;
}
