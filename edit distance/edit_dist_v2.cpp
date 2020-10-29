#include <bits/stdc++.h>
using namespace std;

#define PRIME 1000000007

/* Helper function that calculates the minimum of 3 integers: @x, @y, @z */
static inline int min(int x, int y, int z)
{
	return std::min(std::min(x, y), z);
}

/* edit_distance_v2:
 * Compute the case-insensitive minimum edit distance using the LCS algorithm.
 * Supported Operations:
 * 	1. Insertion
 * 	2. Deletion
 * 	3. Replacement
 * 
 * @str1:	string 1
 * @str2:	string 2
 * @m:		length of @str1
 * @n:		length of @str2
 * 
 * Returns the case-insensitive minimum edit distance
 */
int edit_distance_v2(string str1, string str2, int m, int n)
{
	int i, j;
	int min_distance[m + 1][n + 1];

	/* Initialization */
	for (i = 0; i <= m; i++)
		min_distance[i][0] = i;

	for (i = 1; i <= n; i++)
		min_distance[0][i] = i;

	/* Computation */
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {

			if (str1[i - 1] == str2[j - 1])
				min_distance[i][j] = min_distance[i - 1][j - 1];

			else
				min_distance[i][j] = (1 + min(min_distance[i - 1][j],		// Deletion
							      min_distance[i][j - 1],		// Insertion
							      min_distance[i - 1][j - 1])	// Replacement
						     ) % PRIME;
		}
	}

	return min_distance[m][n];
}

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		string str1;
		string str2;
		cin >> str1;
		cin >> str2;
		/* Convert input strings into lowercase */
		transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
		transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
		cout << edit_distance_v2(str1, str2, str1.length(), str2.length()) << endl;
	}

	return 0;
}
