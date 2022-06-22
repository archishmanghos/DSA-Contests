[Link to problem on Leetcode](https://leetcode.com/problems/kth-largest-element-in-an-array/)



<details><summary>Sub-Optimal Solution</summary>

Sub-Optimal Solution: TC = `O(NlogN)`, SC = `O(1)` 

- We sort the array. <br>
- The k-th element from the last is our answer.<br>
- Sorting takes **NlogN** time and returning the k-th last takes **constant** time. <br>


Runtime: `8 ms`, faster than `83.25%`<br>
Memory Usage: `10.1 MB`, less than `61.91%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/215-A.png)

</details>

</details>



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(NlogK)`, SC = `O(K)`  

- We maintain a minimum priority queue. <br>
- We traverse the array and start pushing elements to the heap. <br>
- If the size of the heap exceeds k, it means, we don't require the smallest element anymore<br>
as that cannot be a candidate for k-th largest element anymore and hence is removed from the heap. <br>
- Thus, the size of the heap never exeeds k. <br>
- The insertion operation takes **logk** for a queue of size k at worst, deletion takes **constant** time and traversing the array takes **linear** time. <br>


Runtime: `8 ms`, faster than `83.25%`<br>
Memory Usage: `10.2 MB`, less than `21.99%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/215-B.png)

</details>

</details>