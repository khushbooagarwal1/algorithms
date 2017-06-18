https://www.hackerrank.com/challenges/journey-to-the-moon/copy-from/44408729


The member states of the UN are planning to send 2 people to the Moon. But there is a problem. In line with their principles of global unity, they want to pair astronauts of  different countries.

There are N trained astronauts numbered from 0  to N-1. But those in charge of the mission did not receive information about the citizenship of each astronaut. The only information they have is that some particular pairs of astronauts belong to the same country.

Your task is to compute in how many ways they can pick a pair of astronauts belonging to different countries. Assume that you are provided enough pairs to let you identify the groups of astronauts even though you might not know their country directly. For instance, if (1,2,3) are astronauts from the same country; it is sufficient to mention that (1,2) and (2,3) are pairs of astronauts from the same country without providing information about a third pair (1,3) . 

Input Format

The first line contains two integers, N and P, separated by a single space.P  lines follow. Each line contains2  integers separated by a single space A and B such that

0 <= A ,B <= N-1
and A and B are astronauts from the same country.
