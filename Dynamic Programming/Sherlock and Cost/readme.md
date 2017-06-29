https://www.hackerrank.com/challenges/sherlock-and-cost/copy-from/44094705


Array A contains the elements, A1,A2...AN. And array B contains the elements, B1,B2...BN. There is a relationship between Ai and Bi, ∀ 1 ≤ i ≤ N, i.e., 
any element Ai lies between 1 and Bi.

Let the cost S of an array A be defined as:
  S = \SUM{i = 2}{N} |A_i - A_{i-1}|

You have to print the largest possible value of S.

Input Format

The first line contains, T, the number of test cases. Each test case contains an integer, N, in first line. The second line of each test case contains N integers that denote the array B.

Constraints

1 ≤ T ≤ 20 
1 ≤ N ≤ 10^5 
1 ≤ Bi ≤ 100

Output Format

For each test case, print the required answer in one line.
