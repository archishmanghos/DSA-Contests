![](https://github.com/archishmanghos/code-images/blob/master/GFG-Min-Coin.png)

Optimal Solution: TC = O(N x amount), SC = O(amount)

We use dynamic programming to solve this problem. <br>
We take the states as the amount left to be selected. <br>
Inside the recursive function, we define the functions as, <br>

$$
F(amount) = \sum_{i = 1}^{n}{F(amount - nums[i])} \forall{{nums[i]} \leqslant {amount}}
$$