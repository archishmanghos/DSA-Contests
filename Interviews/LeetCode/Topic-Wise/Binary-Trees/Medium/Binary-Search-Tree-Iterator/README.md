Optimal Solution: TC = `O(1)`, SC = `O(Height of Tree)`

* Take a stack and put all left nodes to the stack. <br>
* When next() function is called, pop the topmost node of the stack. Check if the node had a right child, if it had, push the right child and all of it's left child nodes to the stack. <br>
* When hasNext() function, is called, return true if the stack is non-empty, else return false. <br>

Runtime: `48 ms`, faster than `27.26%`<br>
Memory Usage: `24.1 MB`, less than `87.51%`<br>


<details><summary>Clean code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/173.png)

</details>