https://www.hackerrank.com/contests/m-tech-cse-2017-practice-test-graphs-special/challenges/matrix-game/problem


Jim invents a matrix game for doing timepass. In this game, he creates a NxM matrix of positive integers. The objective of the game is to move from any given location in the matrix , to a border element in the matrix. Border element are all those elements which have less than 4 adjacent elements( Note that non-border elements have exactly 4 adjacent elements).

In any move he can change his location from i,j to p,q if and only if

1. i,j and p,q are adjacent. ( Note that diagonal elements are not adjacent )
2. Value at index p,q is smaller or equal to value at index i,j.
Jim wins the game if by making zero or more moves he can reach any border element of the matrix.

Count the number of start locations which ends in a win.

Input Format

The first line of the input gives the number of test cases, T.

The first line of each test case contains two numbers R and C indicating the number of rows and columns of matrix.

Then, there are R lines of C positive integers each. The jth value on the ith of these lines gives value[i][j]: the value of the matrix element in the ith row and the jth column.

Constraints
1 <= T <= 100
1 <= R, C <= 50
1 <= Value of any Element  <= 1000

Output Format

For every test case print the single integer, denoting number of winning locations.
