[Link to the Problem on GFG](https://practice.geeksforgeeks.org/problems/sum-of-two-numbers-without-using-arithmetic-operators/0/)


Optimal Solution: TC = `O(31)`, SC = `O(1)`

* Maintain a carry variable. <br>
* Traverse bit by bit from the 31st bit.<br>
* Take the value of the i-th bit of both a and b and sum them up along with carry. <br>
* If the summed value is odd, it means that the i-th bit of the answer will be set, set it using the OR operator. <br>
* If the summed value is >= 2, make the carry 1. <br>

Total Time Taken: `0.01/1.12`


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Sum%20of%20two%20numbers%20without%20using%20arithmetic%20operators.png)

</details>