# Operations and Longest Prefix

## 1. Longest common prefix - R operation<br />

### Introduction
Consider two strings of the same length **P** and **Q**. Both contain lower case alphabets from (a-z).<br />
***‘R’ operation*** will move the first character of the string to the end of the string.

* Example<br />
&emsp;1 R operation:	*‘advancedalgorithms’* -> *‘dvancedalgorithmsa’*<br />
&emsp;2 R operations:	*‘advancedalgorithms’* -> *‘vancedalgorithmsad’*<br />

### Requirement
Find the number of **‘R’s** that have to be carried out on **Q** such that **P** and **Q** have the longest
identical prefix possible.<br />
If more than one such number exists, print the smallest number of **‘R’s** required.<br />
The time complexity of the solution has to be **O(N)**, where N is the length of the string.

### Implementation
The theory behind *Knuth–Morris–Pratt Algorithm* has been applied, with some alterations and tweaks that help in obtaining the required result.

### I/O format
*  **Input**<br />
	1.	First line contains a single integer **N**, where **N** is the length of the strings. (1 <= **N** <= 10<sup>5</sup>)
	2.	The second line contains string **P**, and the third line contains string **Q**.
*  **Output**<br />
	&emsp;&emsp;A single integer which contains the number of ***'R' operations***.
<br />


## 2. Longest common prefix - Splitting<br />

### Introduction
Given a string **A** containing lowercase alphabets [a..z] of length **N**, the string is split into two parts;<br />
&emsp;**B** = **A**[0...i-1] &emsp;and&emsp;**C** = **A**[i...N-1]; based on a point of split, **i**.

### Requirement
For the given string **A**,**Q** queries are asked. Each query gives the value of **i** at which the
splitting is to be done. <br />
For each query, return the longest common prefix of the two splits.<br />
The overall time complexity of the expected solution should be **O(Q*logN\*LogN)**.

### Implementation
Concepts from Number Theory, Hashing, Rabin Karp Algorithm, and Binary search have been used.

### I/O format
*  **Input**<br />
	1.	First line contains length **L** of the string **A**. (1 <= **L** <= 10<sup>5</sup>)
	2.	The second line contains the string **A**.
	3.	The third line contains a number of queries **Q**. **Q** <= 10
	4.	**Q** lines will follow each containing a positive number **i**. **i** <= **i** <= **L** - 1
*  **Output**<br />
	&emsp;&emsp;**Q** numbers (the length of the longest common prefix). Each number on a new line.
<br />
