#include <stdio.h>

/*
 * Extended Euclidean Algorithm that computes the modular multiplicative inverse.
 */ 
void extended_euclidean_algorithm(int value, int divisor, int *x, int *y)
{
	if (value == 0) {
		*x = 0;
		*y = 1;
		return;
	}

	int x1, y1;
	extended_euclidean_algorithm(divisor % value, value, &x1, &y1);

	*x = y1 - (divisor / value) * x1;
	*y = x1;

	return;
}

/*
 * Calculate the inverse of a @value w.r.t a @divisor.
 * (@value)*inverse ≡ 1 mod (@divisor)
 */
int compute_inverse(int value, int divisor)
{
	int x, y;
	extended_euclidean_algorithm(value, divisor, &x, &y);
	return (x % divisor + divisor) % divisor;
}

/*
 * Apply the Chinese Remainder theorem to evaluate the
 * number that satisfies all the divisor-remainder combinations
 *
 * @divisors:	array with all divisors
 * @remainders:	array with remainders corresponding to the respective divisors
 * @count:	total number of divisors and remainders
 */
int chinese_remainder(int divisors[], int remainders[], int count)
{
	int N = 1, result = 0;

	/* Calculate product of all divisors */
	for (int i = 0; i < count; i++)
		N = N*divisors[i];

	/* Apply the formula  (Σ (ai)*(Ni)*(inverse(Ni, divisors[i]))) mod(N) */
	for (int i = 0; i < count; i++)	{
		int Ni = N / divisors[i];
		result += remainders[i] * Ni * compute_inverse(Ni, divisors[i]);
	}

	return (result % N);
}

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int divisors[N], remainders[N];

	for (int i = 0; i < N; i++)
		scanf("%d %d", &divisors[i], &remainders[i]);

	printf("%d", chinese_remainder(divisors, remainders, N));
	return 0;
}
