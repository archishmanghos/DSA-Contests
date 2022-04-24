[Link to problem on Leetcode](https://leetcode.com/problems/sliding-window-maximum/)

My Solution: TC = `O(NlogN)`, SC = `O(N)`

* Take a set and an unordered map. <br>
* Take the first k elements, put it in the set and increment the values in the map.<br>
* Use sliding window technique, decrement the values left by the window and increment the current index value in th map. <br>
* If the mapped value hits 0 after decrement, erase the key from the set. <br>
* The answer at each index will be the current maximum element in the set which can be easily found in logN time. <br>

Runtime: `772 ms`, faster than `11.43%`<br>
Memory Usage: `193.3 MB`, less than `9.39%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/239.png)

</details>