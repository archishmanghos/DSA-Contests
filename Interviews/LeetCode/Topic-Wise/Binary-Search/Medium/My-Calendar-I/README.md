<!-- [Link to Striver's SDE Sheet]() -->

[Link to problem on Leetcode](https://leetcode.com/problems/my-calendar-i/)


<!-- 
<details><summary>Sub-Optimal Solution</summary>

Sub-Optimal Solution: TC = , SC =  

*


Runtime: , faster than <br>
Memory Usage: , less than <br>

<details><summary>Clean Code</summary>

![]()

</details>

</details> -->



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(NlogN)`, SC = `O(N)` 

- Construct a map of start times and use binary search to find the closest start time to the given start time.
- Check for the interval found and insert if possible.
- [Solution using map in Leetcode's official Solution](https://leetcode.com/problems/my-calendar-i/solution/)


Runtime: `99 ms`, faster than `92.87%`<br>
Memory Usage: `39.1 MB`, less than `27.98%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/729.png)

</details>

</details>