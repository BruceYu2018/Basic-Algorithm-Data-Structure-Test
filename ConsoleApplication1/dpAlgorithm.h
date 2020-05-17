#pragma once
#include <algorithm>
#include <vector>
using namespace std;

/**********************************/
/**** DP Algorithm Declaration ****/
/**********************************/
long long dpAlgorithm(int a[], int n, int k, int d);

/********************************************/
/**** Recursive Algorithm Implementation ****/
/********************************************/
vector<vector<long long>> memo;
long long memoSearch(int a[], int index, int n, int k) {
	if (k <= 0 || index >= n)
		return 1;
	if (memo[index][k] != -1)
		return memo[index][k];

	long long result = 0;
	for (int i = index; i < n; i++)
		result = max(result, a[i] * memoSearch(a, i+1, n, k-1));
	memo[index][k] = result;
	return result;
}

long long recursive(int a[], int index, int n, int k) {
	if (k <= 0 || index >= n)
		return 1;

	long long result = 0;
	for (int i=index; i < n; i++)
	     result = max(result, a[i] * recursive(a, i+1, n, k-1));
	return result;
}

long long recursiveResult(int a[], int n, int k, int d) {
	memo = vector<vector<long long>>(n, vector<long long>(k + 1, -1));
	long long result = recursive(a, 0, n, k);
	//long long result = memoSearch(a, 0, n, k);
	return result;
}

/*************************************/
/**** DP Algorithm Implementation ****/
/*************************************/
long long dpAlgorithm(int a[], int n, int k, int d) {
	memo = vector<vector<long long>>(n, vector<long long>(k+1, -1));
	long long result = 0;
	for (int j = 1; j < k+1; j++) {
		for (int i = 0; i < n; i++) {
			if (j == 1) {
				memo[i][j] = a[i];
			}
			else {
				long long temp = 0;
				for (int index = i + 1; index < n; index++) {
					temp = max(temp, memo[index][j - 1]);
					memo[i][j] = temp * a[i];
				}
			}
			if (j == k) result = max(result, memo[i][j]);
		}
	}
	return result;
}

long long dpAlgorithm2(int a[], int n, int k, int d) {
	vector<long long> memo2 = vector<long long>(n, -1);
	long long result = 0;
	for (int j = 1; j < k + 1; j++) {
		for (int i = 0; i < n; i++) {
			if (j == 1) {
				memo2[i] = a[i];
			}
			else {
				for (int index = i + 1; index < n; index++) {
					memo2[i] = max(memo2[i], a[i] * memo2[index]);
				}
			}
			if (j == k) result = max(result, memo2[i]);
		}
	}
	return result;
}

long long singProblem(int a[], int n, int k, int d) {
	vector<long long> dpmax = vector<long long>(n, 0);
	vector<long long> dpmin = vector<long long>(n, 0);
	long long result = 0;
	for (int j = 1; j < k + 1; j++) {
		for (int i = 0; i < n; i++) {
			if (j == 1) {
				dpmax[i] = a[i];
				dpmin[i] = a[i];
			}
			else {
				for (int index = i + 1; index <= min(i + d, n - 1); index++) {
					dpmax[i] = max(dpmax[i], max(a[i] * dpmax[index], a[i] * dpmin[index]));
					dpmin[i] = min(dpmin[i], min(a[i] * dpmax[index], a[i] * dpmin[index]));
				}
			}
			if (j == k) result = max(result, dpmax[i]);
		}
	}
	return result;
}