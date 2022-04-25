[Link to problem on Leetcode](https://leetcode.com/problems/peeking-iterator/)

Optimal Solution: TC = O(1) per call, SC = O(N)

* Initialise a vector and an iterator in the constructor. <br>
* In peek function, return the current array element pointed by the iterator. <br>
* In next function, print the current array element and increase the iterator. <br>
* In hasNext function, if the iterator is within array bounds, return true, else false. <br>

Runtime: 3 ms, faster than 79.17%<br>
Memory Usage: 7.4 MB, less than 88.55%<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/284.png)

</details>