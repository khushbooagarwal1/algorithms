https://www.hackerrank.com/contests/mtech-cse-2016-practice-test-3/challenges/dijkstrashortreach


Given a graph consisting  nodes (labelled  to ) where a specific given node  represents the starting position  and an edge between two nodes is of a given length, which may or may not be equal to other lengths in the graph.

It is required to calculate the shortest distance from the start position (Node ) to all of the other nodes in the graph.

Note: If a node is unreachable , the distance is assumed as .

Input Format

The first line contains , denoting the number of test cases. 
First line of each test case has two integers , denoting the number of nodes in the graph and , denoting the number of edges in the graph.

The next  lines each consist of three space-separated integers   , where  and  denote the two nodes between which the undirected edge exists,  denotes the length of edge between these corresponding nodes.

The last line has an integer , denoting the starting position.

If there are edges between the same pair of nodes with different weights, they are to be considered as is, like multiple edges.

Output Format

For each of the  test cases, print a single line consisting  space separated integers denoting the shortest distance of  nodes other than  from starting position  in increasing order of their labels.

For unreachable nodes, print -1.
