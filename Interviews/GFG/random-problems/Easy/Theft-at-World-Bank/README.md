Optimal Solution: TC = `O(NlogN)`, SC = `O(1)`

* Take a vector of pairs. The pairs can be defined as:<br>

> First: This will contain the the profit we can earn per unit weight of the element. <br>
> Second: This will contain the weight of the element. <br>
>

* Sort the vector in decreasing order of the profit per unit weight. <br>
* Traverse the vector, take the maximum weight we can take, and add to our answer the profit using [proft per unit weight x weight that can be taken]. <br>
* This will give us the maximum profit. <br>

Total Time Taken: `0.09/2.2`


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Theft-at-World-Bank.png)

</details>