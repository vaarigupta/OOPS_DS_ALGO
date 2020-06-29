// DP based CPP program to find n-th Rencontres
// Number
#include <bits/stdc++.h>
using namespace std;
#define MAX 100

// Fills table C[n+1][k+1] such that C[i][j]
// represents table of binomial coefficient
// iCj
int binomialCoeff(int C[][MAX], int n, int k)
{
	// Calculate value of Binomial Coefficient
	// in bottom up manner
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= min(i, k); j++) {

			// Base Cases
			if (j == 0 || j == i)
				C[i][j] = 1;

			// Calculate value using previously
			// stored values
			else
				C[i][j] = C[i - 1][j - 1] +
						C[i - 1][j];
		}
	}
}

// Return Recontres number D(n, m)
int RencontresNumber(int C[][MAX], int n, int m)
{
	int dp[n+1][m+1] = { 0 };

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (j <= i) {

				// base case
				if (i == 0 && j == 0)
					dp[i][j] = 1;

				// base case
				else if (i == 1 && j == 0)
					dp[i][j] = 0;

				else if (j == 0)
					dp[i][j] = (i - 1) * (dp[i - 1][0] +
										dp[i - 2][0]);
				else
					dp[i][j] = C[i][j] * dp[i - j][0];
			}
		}
	}

	return dp[n][m];
}

// Driver Program
int main()
{
    int n,m;
    cin>>n>>m;
	int C[MAX][MAX];
	binomialCoeff(C, n, m);
	cout << RencontresNumber(C, n, m) << endl;
	return 0;
}

