https://www.hackerrank.com/contests/m-tech-cse-2017-practice-test-graphs-special/challenges/ticket-shortest-path/problem


Jim lives in a country with N cities, M road links and M railway links, between cities. He wants to travel from city A to city B in minimal time. But he has a problem. He only has one universal railway ticket, using which he can travel atmost once from any one city to another adjacent city using the railway link, i.e he can travel on atmost 1 railway link.

Find the minimum time he requires to reach from city  to city .

Input Format

First line contains T, the number of test cases. For each test case: The first line contains two space-separated integers, N and M. The next lines each have four space separated integers i,j,p,q.

i and j denotes two cities connected both by road and railway. p denotes road length.q  denotes railway length.

Last line for every test case contains two integers  and .

Constraints
1 <= T <= 10
1 <= N <= 3000
1 <= M <= (N - 1)* N
1 <= p,q <= 500

Output Format

For each test case, print the corresponding answer.
