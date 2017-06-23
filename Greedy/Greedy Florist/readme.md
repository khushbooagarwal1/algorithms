A group of k friends want to buy n flowers where each flower i has some base cost, c_i . The florist wants to maximize his number of new customers, so he increases the price of flowers purchased by repeat customers; more precisely, if a customer has already purchased x flowers, the price, p_i, for flower is p_i = (x+1)*c_i.

Given n, k, and the base cost for each flower, find and print the minimum cost for the group to purchase n flowers.

Note: Flowers can be purchased in any order.

Input Format

The first line contains two space-separated integers describing the respective values of n and k.
The second line contains n space-separated positive integers describing the respective values of c_0, c_1,..,c_(n-1).

Constraints
1 <= n, k <= 100
1 <= c_i <= 10^6
answer <= 2^31
0 <= i < n
Output Format

Print the minimum cost to buy n flowers.
