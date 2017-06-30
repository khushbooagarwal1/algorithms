https://www.hackerrank.com/challenges/fibonacci-modified/copy-from/48083115

We define a modified Fibonacci sequence using the following definition:
 
Given terms t_i and t_{i+1} where , term t_{i+2} is computed using the following relation:
 t_{i+2} = t_i + t_{i+1}^2
For example, if term t1= 0 and t2= 1, term t3 = 0 + 1^2 = 1.

Given three integers,t1, t2, and n, compute and print term tn of a modified Fibonacci sequence.

Note: The value of tn may far exceed the range of a 64-bit integer. Many submission languages have libraries that can handle such large results but, for those that don't (e.g., C++), you will need to be more creative in your solution to compensate for the limitations of your chosen submission language.

Input Format

A single line of three space-separated integers describing the respective values of t1, t2, and n.

Print a single integer denoting the value of term tn in the modified Fibonacci sequence where the first two terms are t1 and t2.
