Optimal Solution: TC = `O(N)`, SC = `O(1)`

* Traverse tree in-order wise and keep track of nodes violating the increasing order rule. <br>
* There can be 2 types of swapped nodes violation. <br>

> 1. The swapped nodes are adjacent. <br>
> 2. The swapped nodes are not adjacent. <br>
>

* To account for both of these, we maintain a pair of pair and int. The first pair caters to first violation and the second one corresponds to second violation. <br>
* If there is no second violation, we swap nodes of first and second elements, else we swap nodes of first and third elements. <br>

Runtime: `24 ms`, faster than `95.40%`<br>
Memory Usage: `58 MB`, less than `47.12%`

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/99.png)

</details>