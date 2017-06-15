Given an undirected weighted connected graph, it is required to find the Really Special SubTree in it. The Really Special SubTree is defined as a subgraph consisting of all the nodes in the graph and

There is only one exclusive path from a node to every other node.
The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
While creating the Really Special SubTree, start by picking the edge with smallest weight. If there are edges of equal weight available at an instant, then the edge to be chosen first among them is the one with minimum value of sum of the following expression :
u + wt + v , where u and v are the node numbers of the corresponding edge and wt is the weight.
Even then if there is a collision, choose any one of them.
While doing the above, ensure that no cycle is formed while picking up edges.
Finally, you need to print the overall weight of the Tree so formed using above rules.


