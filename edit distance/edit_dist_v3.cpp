#include <bits/stdc++.h>
using namespace std;

#define PRIME 1000000007

/* Helper function that calculates the minimum of 3 integers: @x, @y, @z */
static inline int min(int x, int y, int z)
{
	return std::min(std::min(x, y), z);
}

/* Helper function that returns the deletion weight for a letter: @x */
static inline int deletion_weight(char x)
{
	return x - 'a' + 1;
}

/* Helper function that returns the insertion weight for a letter: @x */
static inline int insertion_weight(char x)
{
	return x - 'a' + 1;
}

/* Helper function that returns the replacement weight for two letters: @x, @y */
static inline int replacement_weight(char x, char y)
{
	return abs((x - 'a') - (y - 'a'));
}

/* edit_distance_v3:
 * Compute the minimum weighted edit distance using the LCS algorithm where the
 * weights are  * the rank of the letters in the alphabet for the insert and 
 * delete operation the weight of the replace operation is the distance between 
 * the letters.
 * 
 * @str1:	string 1
 * @str2:	string 2
 * @m:		length of @str1
 * @n:		length of @str2
 * Returns the weighted minimum edit distance
 */
static int edit_distance_v3(string str1, string str2, int m, int n)
{
	int i, j;
	int min_distance[m + 1][n + 1];

	/* Initialization */
	min_distance[0][0] = 0;
	for (i = 1; i <= m; i++)
		min_distance[i][0] = (min_distance[i - 1][0] + deletion_weight(str1[i - 1])) % PRIME;

	for (i = 1; i <= n; i++)
		min_distance[0][i] = (min_distance[0][i - 1] + insertion_weight(str2[i - 1])) % PRIME;

	/* Computation */
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			/* 
			 * This checking is not explicitly necessary, since replacement_weight(str1[i - 1], str2[j - 1])
			 * will always be = 0 when this condition occurs (for the given weight conditions).
			 * However, performing this check will help optimize runtime speed, since in this case, the other
			 * table lookups, addition and computing minimum operations don't have to be performed unnecessarily.
			 * This is also allows for scalability in case another weight measure is to be considered.
			 */
			if (str1[i - 1] == str2[j - 1])
				min_distance[i][j] = min_distance[i - 1][j - 1];

			else
				min_distance[i][j] = min((min_distance[i - 1][j] + deletion_weight(str1[i - 1])) % PRIME,
							 (min_distance[i][j - 1] + insertion_weight(str2[j - 1])) % PRIME,
							 (min_distance[i - 1][j - 1] + replacement_weight(str1[i - 1], str2[j - 1])) % PRIME);
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
		cout << edit_distance_v3(str1, str2, str1.length(), str2.length()) << endl;
	}

	return 0;
}
