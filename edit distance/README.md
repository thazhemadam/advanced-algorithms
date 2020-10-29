# Operations and Longest Prefix

## 1. Edit Distance v1<br />

### Introduction
Compute the case-insensitive minimum edit distance using the LCS algorithm.

### Requirements
* Replace/substitute operation should not be supported
* Only insert and delete operations are to be considered
* Should be case-insensitive (*'A'* is equivalent to *'a'*)
* Do all calculations modulo 10<sup>9</sup> + 7

### Input
First line contains a single integer T, where T is the number of test cases.
The next T lines contain two strings.<br />
* 1 <= T <= 10<sup>5</sup> <br />
* 0 <= len(strings) <= 10<sup>3</sup>
### Output
Output T numbers (the minimum edit distance between each pair of strings, using LCS); each number on a new line.

----------------------------

## 2. Edit Distance v2<br />

### Introduction
Generally, the LCS algorithm handles only insertion and deletion operations, to compute the edit distance. <br /> 
Tweak **Edit Distance v1** to accommodate substitution/replace as an
operation.

### Requirements
* Insert, delete and replace operations are to be considered
* Should be case-insensitive (*'A'* is equivalent to *'a'*)
* Do all calculations modulo 10<sup>9</sup> + 7

### Input
First line contains a single integer T, where T is the number of test cases.
The next T lines contain two strings.<br />
* 1 <= T <= 10<sup>5</sup> <br />
* 1 <= len(strings) <= 10<sup>3</sup>

### Output
Output T numbers (the minimum edit distance between each pair of strings, using LCS); each number on a new line.

----------------------------

## 3. Edit Distance v3<br />

### Introduction
Compute the minimum weighted edit distance using the LCS algorithm where the insert, delete and replace operations have a weight associated with them.
* For the insert and delete operation:
&emsp;The weights are the rank of the letters in the alphabet (A=1, B=2, Z=26, etc)
* For the replace operation:
&emsp;The weight is the distance between the letters.<br/>
&emsp;&emsp; The weight associated with replacing *A* with *B* is 1, *Z->A* is 25, *D->C* is 1, *C->D* is 1. <br />

Tweak **Edit Distance v2** to accommodate the weights of each operation. 
<br />

### Requirements
* Insert, delete and replace operations are to be considered
* Should be case-insensitive (*'A'* is equivalent to *'a'*)
* Do all calculations modulo 10<sup>9</sup> + 7

### Input
First line contains a single integer T, where T is the number of test cases.
The next T lines contain two strings.<br />
* 1 <= T <= 10<sup>5</sup> <br />
* 1 <= len(strings) <= 10<sup>3</sup>

### Output
Output T numbers (the minimum edit distance between each pair of strings, using LCS); each number on a new line.
