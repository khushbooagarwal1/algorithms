https://www.hackerrank.com/contests/m-tech-coding-practice-test-five5/challenges/string-conversion-1/copy-from/1302187898


Given N  strings, find minimum operations to make all string identical. For this you are allowed two different operations:

1. Select any character in any of the strings and repeat it (add another instance of this character exactly after it). For example, in a single move you can change "abc" to "abbc" (by repeating the character 'b').
2. Select any two adjacent and identical characters in any of the strings, and delete one of them. For example, in a single move you can change "abbc" to "abc" (delete one of the 'b' characters), but can't convert it to "bbc".
If there is no possible way to make all strings identical, print "-1"

Input Format

First line contains T, the number of test cases. For every test case, first line contains N, the number of strings. Next N lines contains N strings.

Output Format

For every test case print the minimum possible operations required, else print -1.
