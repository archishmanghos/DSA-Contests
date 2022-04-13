Optimal Solution: TC = `O(N x amount)`, SC = `O(amount)`

We use dynamic programming to solve this problem. <br>
We take the states as the amount left to be selected. <br>
Inside the recursive function, we define the functions as, <br>

> F(amount) = Σ(amount - nums[i]) ⋁ (i ∈ N and nums[i] ≤ amount) <br>
>

We return a large value if the amount becomes less than 0, else if the amount becomes equal to 0, we return 0. <br>
Finally, after the recursive function is over, we check if the value returned is very big, if it is, we return -1, else return the answer. <br>

Total Time Taken: `0.02/4.6`

#+html: <details><summary> Clear Code </summary> 
[](https://github.com/archishmanghos/code-images/blob/master/GFG-Min-Coin.png)
#+html: </details>