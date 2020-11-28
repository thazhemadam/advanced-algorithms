#include <stdio.h>
#include <math.h>
#include <string.h>

#define PRIME 1000000007
#ifndef MAX_N
#define MAX_N 200
#endif
#define MAX_K MAX_N/3
#define a 0
#define ab 1
#define abb 2
#define other 3

/*
 * Fully populate the dynamic programming table that has is supposed to contain 
 * the total number of possible strings that can be generated with a suffix of 
 * 'a'/'ab'/'abb'/something else up up until for string of length @N.
 * 
 * @k_table:	dynamic programming table to be populated
 * @N:		Length of string
 * @K:		Maximum K factor that a string of length @N can have
 */
static void populate_ktable(unsigned long long k_table[][MAX_K + 1][4], int N, int K)
{
	int n, k;

	/* Initialization */
	k_table[1][0][a] = 1;
	k_table[1][0][other] = 25;

	/* Computation */
	for (n = 2; n <= N; n++) {
		for (k = 0; k <= K; k++) {
			if (k == 0)
				k_table[n][k][a] = (k_table[n - 1][k][a] + k_table[n - 1][k][ab] + k_table[n - 1][k][other])%PRIME;
			else
				k_table[n][k][a] = (k_table[n - 1][k - 1][abb] + k_table[n - 1][k][a] + k_table[n - 1][k][ab] + k_table[n - 1][k][other]) % PRIME;

			k_table[n][k][ab] = k_table[n - 1][k][a];
			k_table[n][k][abb] = k_table[n - 1][k][ab];
			k_table[n][k][other] = ((24 * k_table[n - 1][k][a]) + (24 * k_table[n - 1][k][ab]) + (25 * k_table[n - 1][k][abb]) + (25 * k_table[n - 1][k][other])) % PRIME;
		}
	}
}

/*
 * Returns the total number of strings length @N with K -factor = @k
 * and updates the @k_table accordingly as well
 * 
 * @k_table: the k_table itself
 * @exponents_array: array containing the exponents
 * @N: Length of string
 * @k: Number of times 'abba' appears in the string
 * 
 */
static unsigned long long kfactor(int N, int k, unsigned long long k_table[][MAX_K + 1][4])
{
	/* Invalid N - k combination */
	if (N < ((3 * k) + 1))
	    return 0;

	return (k_table[N][k][a] + k_table[N][k][ab] + k_table[N][k][abb] + k_table[N][k][other]) % PRIME;
}

int main(void)
{
	int T, N, k;
	unsigned long long k_factor_table[MAX_N+1][MAX_K+1][4];
/*
 *	k_factor_table[n][k] will be a 4 element array, wherein each element can be the number of strings of length n and “K factor” = k 
 *	which belong to the criteria represented by that index :
 *
 *		k_factor_table[n][k][0] can be the number of strings of length n and K-factor = k which end with substring ‘a’ 
 *		k_factor_table[n][k][1] can be the number of strings of length n and K-factor = k which end with substring ‘ab’
 *		k_factor_table[n][k][2] can be the number of strings of length n and K - factor = k which end with substring ‘abb’
 *		k_factor_table[n][k][3] can be the number of strings of length n and K - factor = k which end with anything other than ‘a’ ‘ab’ ‘abb’
 */

	memset(k_factor_table, 0, sizeof(k_factor_table));
	populate_ktable(k_factor_table, MAX_N, MAX_K);

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		scanf("%d", &k);
		printf("%lld\n", kfactor(N, k, k_factor_table));
	}

	return 0;
}
