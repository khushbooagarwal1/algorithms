https://www.hackerrank.com/contests/m-tech-cse-2017-practice-test-graphs-special/challenges/food-chain-1


Jim is doing research on food chains. Currently Jim knows only one object in the food chain "cheese". He gets a list of relations of form A eats B where A and B are any arbitrary objects.For every such relation he adds A into the food chain.It is guaranteed that for every such relation A eats B, A has not eaten any other object in the past, and B must have eaten atleast one object(except for the case when  is cheese, which is the base case).

Also remember that object names are case insensitive. i.e cheese and ChEEse are same objects.

Jim is now interested in the length of largest food chain. Length of a food chain is the number of objects in the food chain.

Input Format

First line contains N, number of relations. Next N lines contains a relation of form A eats B, where A and B are variables.

Constraints

1 <= N <= 200
1 <= |S| <= 20

S contains english alphabets only(both lower and upper cases and case insensitive).

Output Format

Print length of the largest food chain.
