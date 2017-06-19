https://www.hackerrank.com/contests/m-tech-cse-2017-practice-test-graphs-special/challenges/quadricycle/copy-from/1302102713

Given an undirected graph, containing  nodes, count the number of quadricycles in the graph. Quadricycle is a cycle of  nodes(V1,V2,V3,V4) i.e there is an edge between V1, V2 and V2, V3 and V3, V4 and V4, V1. Two quadricycles are different if atleast one edge is different.

Input Format

First line contains N, number of nodes in graph. Next N lines contains graph in adjacency matrix format, i.e A[i][j] = 1 represents there is an edge between  and  node.

Graph will not contain any self loops. It is guaranteed that the given adjacency matrix is symmetrical(as the graph is undirected).

Constraints
1 <= N <= 2000

Output Format

Output single integer, number of quadrilaterals in the graph.
