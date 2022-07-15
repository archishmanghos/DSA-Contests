Optimal Solution: TC = `O(Height of Tree)`, SC = `O(1)`

The main crux of the idea is that we don't have to traverse the whole tree to find the value. <br>
<details><summary>Why don't we have to?</summary>

The tree given is a [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree). Hence, if the given value is less than the current node's value, we can conclude, that every node in the right subtree of the current node cannot be an answer and vice-versa if the value is greater than the current node's value. 

</details>

Thus we use a loop till the root either becomes null or we find the value and change the root depending if the given value is less than the root's value or not. <br>

Runtime: `42 ms`, faster than `82.65%`<br>
Memory Usage: `34.9 MB`, less than `24.22%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode-700.png)

</details>