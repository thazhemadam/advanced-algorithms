#include <bits/stdc++.h>
using namespace std;

typedef complex<double> cd;

/* 
 * Increase the number of terms in the initial vector 
 * appropriately by considering higher order terms 
 * to be present, but with coefficients = 0, and return
 * the resultant vector.
 */
vector<cd> add_zero_coeffs(vector<cd> &x)
{
	int n = x.size();

	for (int i = 0; i < n; i++)
		x.push_back(0);

	return x;
}

/*
 * Determination of Fast Fourier Transform
 */
vector<cd> fft(vector<cd> &x)
{
	int n = x.size();

	if (n == 1)
		return vector<cd>(1, x[0]);

	vector<cd> w(n); /* Roots of unity */

	for (int i = 0; i < n; i++) {
		double alpha = 2 * M_PI * i / n;
		w[i] = cd(cos(alpha), sin(alpha));
	}

	vector<cd> A0(n / 2), A1(n / 2);

	for (int i = 0; i < n / 2; i++)	{
		A0[i] = x[i * 2];
		A1[i] = x[i * 2 + 1];
	}

	vector<cd> y0 = fft(A0);
	vector<cd> y1 = fft(A1);
	vector<cd> y(n);

	for (int k = 0; k < n / 2; k++) {
		y[k] = y0[k] + w[k] * y1[k];
		y[k + (n / 2)] = y0[k] - w[k] * y1[k];
	}

	return y;
}

/*
 * Determination of Inverse of Fast Fourier Transform
 */
vector<cd> inverse_fft(vector<cd> &a)
{
	int n = a.size();

	if (n == 1)
		return vector<cd>(1, a[0]);

	vector<cd> w(n); /* Roots of unity */

	for (int i = 0; i < n; i++) {
		double alpha = 2 * M_PI * i / n;
		w[i] = cd(cos(alpha), sin(alpha));
	}

	vector<cd> A0(n/2), A1(n/2);

	for (int i = 0; i < (n/2); i++) {
		A0[i] = a[i * 2];
		A1[i] = a[i * 2 + 1];
	}

	vector<cd> y0 = inverse_fft(A0);
	vector<cd> y1 = inverse_fft(A1);
	vector<cd> y(n);

	for (int k = 0; k < (n/2); k++) {
		y[k] = y0[k] + y1[k]/w[k]; /* w[k]^-1 */
		y[k + (n/2)] = y0[k] - y1[k] / w[k];
	}

	return y;
}

/*
 * Perform pointwise multiplication, given two vectors @A, and @B, 
 * and return the product.
 */ 
vector<cd> pointwise_multiplication(vector<cd> &A, vector<cd> &B)
{
	int size = A.size();
	vector<cd> C(size);

	for (int i = 0; i < size; i++)
		C[i] = A[i] * B[i];

	return C;
}

/*
 * Convert point-wise representation into coefficient representation
 * and return the result.
 */ 
vector<cd> interpolation(vector<cd> &x)
{
	x = inverse_fft(x);
	int size = x.size();

	/* divide each element by size */
	for (int i = 0; i < size; i++)
		x[i] = x[i]/cd(size);

	return x;
}

int main(void)
{
	int n;
	vector<cd> A, B, C;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		A.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		B.push_back(x);
	}

	A = add_zero_coeffs(A);
	B = add_zero_coeffs(B);

	/* Evaluation */
	A = fft(A);
	B = fft(B);

	/* Pointwise Multiplication */
	C = pointwise_multiplication(A, B);

	/* Interpolation */
	C = interpolation(C);

	/* 
	 * Since C[i].real() can sometimes have a very small value 
	 * in lieu of 0, round it off using lround()
	 */
	for (int i = 0; i < 2*n; i++)
		cout << lround(C[i].real()) << " ";

	return 0;
}
