Optimal Solution: TC = `O(N)`, SC = `O(1)`

* Perform a reverse in-order traversal. <br>
* Pass on a reference value, *valTillNow*, which is the new value till now of the recent node. <br>
* When the right call gets over, change the value of *valTillNow* to [node's value + *valTillNow*] and also the node's value to the current value of *valTillNow* which is [node's value + previous value of *valTillNow*]. <br>
* Call for the left value by passing the updated *valTillNow*. <br>

Runtime: `43 ms`, faster than `74.57%`<br>
Memory Usage: `33.5 MB`, less than `19.45%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode-538.png)

</details>