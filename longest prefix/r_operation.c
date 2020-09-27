#include <stdio.h>
#include <string.h>

static int max;

static void compute_lps_array(const char *pattern, int length, int *lps_table);
static int r_shift_kmp(const char *pattern, const char *text);

/*
 * Computes the longest prefix-suffix array for a given pattern.
 *
 * @pattern:	pattern for which the longest prefix-suffix
 *		array must be computed
 * @length:	length of @pattern
 * @lps_table:	newly initialized longest prefix-suffix array
 */
static void compute_lps_array(const char *pattern, int length, int *lps_table)
{
	int i, len_prev;

	max = len_prev = 0;
	i = 1;

	lps_table[0] = 0;

	while (i < length) {
		if (pattern[i] == pattern[len_prev])
			lps_table[i++] = ++len_prev;

		else {
			if (len_prev != 0)
				len_prev = lps_table[len_prev - 1];

			else
				lps_table[i++] = 0;
		}
	}
}

/*
 * Returns the number of rotations required in order to observe
 * the longest prefix match between @pattern and @text.
 *
 * @pattern:	string for which length of longest prefix that matches
 *		anywhere in @text must be found
 * @text:	string which is used for comparison by @pattern such
 *		that @pattern's longest prefix is observed somewhere
 *		within @text
 */
static int r_shift_kmp(const char *pattern, const char *text)
{
	int i, j, r_shift, pattern_len, text_len;

	pattern_len = strlen(pattern);
	text_len = strlen(text);
	i = j = r_shift = 0;

	int lps_table[pattern_len];

	/* preprocess the pattern, and fill longest prefix-suffix table */
	compute_lps_array(pattern, pattern_len, lps_table);

	while (i < text_len) {
		if (pattern[j] == text[i]) {
			j++;
			i++;
		}

		if (j > max) {
			max = j;
			r_shift = i - max;
		}

		if (j == pattern_len)
			j = lps_table[j - 1];

		else if ((i < text_len) && (pattern[j] != text[i])) {
			if (j)
				j = lps_table[j - 1];
			else
				i++;
		}
	}

	return r_shift;
}

int main(void)
{
	int len;

	scanf("%d", &len);

	char stable_pattern[len + 1];
	char rotate_text[2*len + 1];

	scanf("%s", stable_pattern);
	scanf("%s", rotate_text);

	/*
	 * The string to be "rotated" is duplicated/doubled and copied.
	 *
	 * Formally speaking, if the string to be "rotated" is actually
	 * A = 'abc', then it is considered to be (A^2) = 'abcabc'.
	 */
	strncpy(rotate_text+len, rotate_text, sizeof(char)*len);

	stable_pattern[len + 1] = '\0';
	rotate_text[2*len + 1] = '\0';

	/*
	 * Find the longest substring in @rotate_text that matches a prefix
	 * of @stable_pattern.
	 * The starting index of this longest substring is the total 
	 * number of "rotations" required to get the longest commonn prefix.
	 */
	int value = r_shift_kmp(stable_pattern, rotate_text);

	printf("%d", value);

	return 0;
}
