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
If more than one such number exists, print the smallest number of **‘R’**s required.<br />
The time complexity of the solution has to be **O(N)**, where N is the length of the string.

### Implementation
The theory behind *Knuth–Morris–Pratt Algorithm* has been applied, with some alterations and tweaks that help in obtaining the required result.

### I/O format
* Input:<br />
	1.	First line contains a single integer **N**, where **N** is the length of the strings. (1 <= **N** <= 10<sup>5</sup>)
	2.	The second line contains string **P**, and the third line contains string **Q**.
* Output:<br />
	&emsp;&emsp;A single integer which contains the number of ***'R' operations***.
<br />
--------------------------------------------------
<br />
