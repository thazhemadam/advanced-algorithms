# K Factor

### Introduction
The K factor of a string is defined as the number of times ‘abba’ appears as a substring. <br /><br />
Given two numbers N and k, find the number of strings of length N with ‘K factor’ = k.
* Do all calculations modulo 10<sup>9</sup> + 7.
* Only lower case english alphabets are allowed.
* Overlapping matches should be counted as different substrings.<br />
	For example: <br />
&emsp;&emsp;The K factor of the string ‘abbabba’ is 2.<br />
&emsp;&emsp;The K factor of the string ‘abbacdef’ is 1.<br />

### Requirement
The solution has to be O(N<sup>2</sup>).

### Input
First line contains a single integer T, where T is the number of test cases.<br />
The second line contains two integers N and K.<br />
* 1 <= N <= 200<br />
* 1 <= T <= 10<sup>5</sup>

### Output
Output T numbers (Number of strings of length N, with K-factor k); each number on a new line.