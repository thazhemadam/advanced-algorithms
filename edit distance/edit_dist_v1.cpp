#include <bits/stdc++.h>
using namespace std;

#define PRIME 1000000007

/* Helper function that calculates the minimum of 3 integers: @x, @y, @z */
static inline int min(int x, int y, int z)
{
	return std::min(std::min(x, y), z);
}

/* edit_distance_v1:
 * Compute the case-insensitive minimum edit distance using the LCS algorithm.
 * Supported Operations:
 * 	1. Insertion
 * 	2. Deletion
 * 
 * @str1:	string 1
 * @str2:	string 2
 * @m:		length of @str1
 * @n:		length of @str2
 *
 * Returns the case-insensitive minimum edit distance
 */
static int edit_distance_v1(string str1, string str2, int m, int n)
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
				min_distance[i][j] = (1 + min(min_distance[i - 1][j],	// Deletion
							      min_distance[i][j - 1])	// Insertion
						     ) % PRIME;
		}
	}

	return min_distance[m][n];
}

int main(void)
{
	int T;
	cin >> T;
	cin.ignore(1, '\n');
	while (T--) {
		int distance;
		string test_input;

		std::getline(std::cin, test_input);
		std::istringstream iss_input(test_input);
		std::vector<std::string> input_strs(std::istream_iterator<std::string>{iss_input}, std::istream_iterator<std::string>());

		if (!input_strs.size())
			distance = 0;

		else if (input_strs.size() == 1)
			distance = input_strs[0].length();

		else {
			/* Convert input strings into lowercase */
			transform(input_strs[0].begin(), input_strs[0].end(), input_strs[0].begin(), ::tolower);
			transform(input_strs[1].begin(), input_strs[1].end(), input_strs[1].begin(), ::tolower);
			distance = edit_distance_v1(input_strs[0], input_strs[1], input_strs[0].length(), input_strs[1].length());
		}

		cout << distance << endl;
	}

	return 0;
}
