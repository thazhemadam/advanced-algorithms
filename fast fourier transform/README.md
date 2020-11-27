# Fast Fourier Transform

## Polynomial Multiplication

### Introduction

A Fast Fourier transform (FFT) is an algorithm that computes the discrete Fourier transform (DFT) of a sequence, or its inverse (IDFT).

This can be applied for performing polynomial multiplication as well.

Given two polynomials,<br /> 
&emsp;&emsp;A(x) = a<sub>0</sub> + a<sub>1</sub>x<sup>1</sup> + a<sub>2</sub>x<sup>2</sup> + ... + a<sub>n-1</sub>x<sup>n-1</sup> <br />
&emsp;&emsp;B(x) = b<sub>0</sub> + b<sub>1</sub>x<sup>1</sup> + b<sub>2</sub>x<sup>2</sup> + ... + b<sub>n-1</sub>x<sup>n-1</sup>

Find the product C(x) = A(x) * B(x) in O(N logN) time using Fast Fourier Transform.

### Input

1. The first line contains *n* - the degree bound of polynomials A(x) and B(x). <br />
The degree of a polynomial of degree bound *n* may be any integer between 0 and *n* -1.

2. The second line contains the *n* integer coefficients of polynomial A(x) separated by a whitespace starting from the
lowest order coefficient (a<sub>0</sub> a<sub>1</sub> a<sub>2</sub> a<sub>3</sub> ... a<sub>n-1</sub>).

3. The second line contains the *n* integer coefficients of polynomial B(x) separated by a whitespace starting from the
lowest order coefficient (b<sub>0</sub> b<sub>1</sub> b<sub>2</sub> b<sub>3</sub> ... b<sub>n-1</sub>).


### Output
Print 2*n* integer coefficients of C(x) separated by a whitespace starting from the lowest order coefficient (c<sub>0</sub> c<sub>1</sub> c<sub>2</sub> c<sub>3</sub> ... c<sub>n-1</sub>).


### Constraints
* 1 <= *n* <= 100
* *n* is a power of 2
* -200 <= a<sub>i</sub> <= 200
* -200 <= b<sub>i</sub> <= 200 

<!-- ### Examples
1. Example - 1: <br />
* Input: <br />
4 <br />
9 -10 7 6 <br />
-5 4 0 -2
* Output: <br />
-45 86 -75 -20 44 -14 -12 0
* Explanation: <br />
A(x) = 6x<sup>3</sup> + 7x<sup>2</sup> - 10x<sup>1</sup> + 9 <br />
B(x) = -2x<sup>3</sup> + 4x<sup>1</sup> - 5 <br />
C(x) = -12x<sup>6</sup> - 14<sup>5</sup> + 44x<sup>4</sup> - 20x<sup>3</sup> - 75x<sup>2</sup> + 86x - 45 <br />
2. Example - 2: <br />
* Input: <br />
4 <br />
3 0 1 0 <br />
0 1 0 0
* Output: <br />
0 3 0 1 0 0 0 0
* Explanation: <br /> 
A(x) = x<sup>2</sup> + 3 <br />
B(x) = x <br />
C(x) = x<sup>3</sup> + 3x  <br /> -->