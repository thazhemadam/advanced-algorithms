#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define BASE 31
#define PRIME 1000000007
#define min(x, y) \
   ({ __typeof__ (x) _x = (x); \
       __typeof__ (y) _y = (y); \
     _x > _y ? _y : _x; })

static void preprocess(const char *A, unsigned long *hash_table, int len);
static unsigned long hash_lookup(const unsigned long *hash_table, int left, int right);
static bool hash_match_check(const unsigned long *hash_table, int left, int right, int split_index);
static bool binary_search_compare(const unsigned long *hash_table, int left, int right, int split_index, int *retval);
static int lcp_splitting(const char *A, const unsigned long *hash_table, int len, int i);

/*
 * Preprocess by populating the hash_table with calculated
 * progressive cumulative hash values.
 *
 * @A:	string to be preprocessed
 * @hash_table:	hash_table that should be populated
 * @len:	length of string @A
 */
static void preprocess(const char *A, unsigned long *hash_table, int len)
{
	hash_table[0] = A[0] - 'a' + 1;
	for (int i = 1; i < len; i++)
		hash_table[i] = ((hash_table[i-1]*BASE)%PRIME + (A[i] - 'a' + 1))%PRIME;
}

/*
 * Calculate and return the cumulative hash value that a substring
 * (string[left...right]) would have, by making use of the existing
 * preprocessed @hash_table.
 *
 * @hash_table: preprocessed hashtable that contains cumulative hash
 *		 values calculated using the hash function
 * @left:	left-most boundary index
 * @right:	right-most boundary index
 */
static unsigned long hash_lookup(const unsigned long *hash_table, int left, int right)
{
	if (!left)
		return hash_table[right];

	unsigned long power_factor = (unsigned long)pow(BASE, right-left+1)%PRIME;

	return (hash_table[right] - (hash_table[left-1]*(power_factor)%PRIME));
}

/*
 * Checks if the two substrings
 *	string[left...right] and string[left+@split_index...right+@split_index]
 * have the same hash value or not.
 * This determines if the substrings are identical or not.
 *
 * Returns true, if the hash values of the respective substrings
 * is equal. Returns false otherwise.
 * 
 * @hash_table:   preprocessed hashtable that contains cumulative hash
 *		  values calculated using the hash function
 * @left:	  left-most boundary index
 * @right:	  right-most boundary index
 * @split_index: index that divides the initial string into two
 */
static bool hash_match_check(const unsigned long *hash_table, int left, int right, int split_index)
{
	if (hash_lookup(hash_table, left, right) == hash_lookup(hash_table, split_index+left, split_index+right))
		return true;
	return false;
}

/*
 * Determines the longest common prefix by
 * performing binary search (by applying mathematical principles
 * and formula which helps speed things along significantly).
 *
 * @hash_table:   preprocessed hashtable that contains cumulative hash
 *		  values calculated using the hash function
 * @left:	  left-most boundary index
 * @right:	  right-most boundary index
 * @split_index: index that divides the initial string into two
 * @retval:	  pointer to the length of the longest common prefix
 */
static bool binary_search_compare(const unsigned long *hash_table, int left, int right, int split_index, int *retval)
{
	if (hash_match_check(hash_table, left, right, split_index)) {
		*retval += (right - left + 1);
		return true;
	}

	if (right <= left)
		return false;

	else {
		int mid = (left + right)/2;

		if (!binary_search_compare(hash_table, left, mid, split_index, retval))
			return false;

		binary_search_compare(hash_table, mid+1, right, split_index, retval);
	}
}

/*
 * Returns the length of the longest common prefix observed
 * between the substrings obtained when a string is split
 * into two parts.
 *
 * @A:		the string that is supposed to be split
 * @hash_table: preprocessed hashtable that contains cumulative hash
 *		values calculated using the hash function
 * @len:	length of the string
 * @split_index:	index at which the split occurs
 *
 * The "split" occurs such that @A gets split into
 *	@A[0...@split_index-1] and @A[@split_index...@len-1]
 *
 * It must be noted that the idea of splitting is purely conceptual here.
 * Rather than literally splitting @A, manipulation of indexes properly
 * to reflect the same idea proves to be sufficient.
 */
static int lcp_splitting(const char *A, const unsigned long *hash_table, int len, int i)
{
	int retval = 0;

	/*
	 * Since @retval has been initialized with 0, we do not have to check
	 * the return value and see if binary_search_compare succeeded or not.
	 */
	binary_search_compare(hash_table, 0, min(len - i, i) - 1, i, &retval);
	return retval;

}


int main(void)
{
	int len;
	int queries;
	unsigned long *hash_table;

	scanf("%d", &len);

	char A[len];

	scanf("%s", A);

	hash_table = (unsigned long *)malloc(strlen(A)*sizeof(unsigned long));
	preprocess(A, hash_table, len);

	scanf("%d", &queries);

	for (int z = 0; z < queries; z++) {
		int split_index;

		scanf("%d", &split_index);
		printf("\n%d", lcp_splitting(A, hash_table, len, split_index));
	}

	free(hash_table);
	return 0;
}
