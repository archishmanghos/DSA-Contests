[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/longest-substring-without-repeating-characters/)


<details><summary>Sub-Optimal Solution 1</summary>

Sub-Optimal Solution 1: TC = `O(N ^ 2)`, SC = `O(N)`

* We can traverse for all subarrays and account the number of subarrays which have unique elements. <br>
* Traversing all subarrays will take O(N ^ 2) times and constant space. <br>
* We also need a hashset to keep track if the subarray contains unique elements or not.


Runtime: `1803 ms`, faster than `5.01%`<br>
Memory Usage: `264 MB`, less than `5.37%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/3-A.png)

</details>

</details>



<details><summary>Sub-Optimal Solution 2</summary>

Sub-Optimal Solution 1: TC = `O(N + NlogN)`, SC = `O(N)`

* We use a 2 pointer approach here. <br>
* We keep both the pointers at first index initially. <br>
* We also keep a hashset to keep track of the unique elements status. <br>
* Now we move the 2nd pointer as long as we encounter unique elements. An element is unique if it is not in the hashset. <br>
* If an element is encountered which is already in the hashset, we move the 1st pointer and start deleting characters from the set till we get rid of the current element from the hashset. <br>
* And the process repeats. At each step we take the maximum of the length between the 2 pointers. <br>
* The maximum over all such lengths is the answer. <br>


Runtime: `58 ms`, faster than `19.73%`<br>
Memory Usage: `13.6 MB`, less than `13.31%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/3-B.png)

</details>

</details>


<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(N)`, SC = `O(N)`

* Here we optimise the same Sub-Optimal Solution 2 further. <br>
* Instead of moving the low pointer step by step, we can store the index of the last occurence of the current element. We can just shift the low pointer to the index juts after the last occurence. <br>
* This can be done in constant time using a frequency array. <br>
* Hence, the algorithm works in linear time with constant time lookups for the low pointer. <br>


Runtime: `4 ms`, faster than `96.10%`<br>
Memory Usage: `7.4 MB`, less than `86.99%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/3-C.png)

</details>

</details>
