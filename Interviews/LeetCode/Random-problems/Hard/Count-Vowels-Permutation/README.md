<!-- [Link to Striver's SDE Sheet]() -->

[Link to problem on Leetcode](https://leetcode.com/problems/count-vowels-permutation/)



<!-- <details><summary>Sub-Optimal Solution</summary>

Sub-Optimal Solution: TC = , SC =  

*


Runtime: , faster than <br>
Memory Usage: , less than <br>

<details><summary>Clean Code</summary>

![]()

</details>

</details> -->



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(N)`, SC = `O(6) = O(1)`

- The recursive solution is easy to understand.
- Take 2 parameters, index and the previous character.
- Map each character to an integer. For eg, I mapped 'a', 'e', 'i', 'o', 'u' to 1, 2, 3, 4, 5. I left 0 so that I can represent that in my state that there are no previous characters.
- Next, the transitions are simple to build, we just check the previous character and decide accordingly. Note: If there are no previous characters, we can take every character.
- Transform the recursive solution to top-down dp, which is pretty easy and then transform to the bottom-up iterative dp. Next, do a space optimistaion by removing a dimension from the memoization array.


Runtime: `104 ms`, faster than `43.61%`<br>
Memory Usage: `18.2 MB`, less than `49.53%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/1220.png)

</details>

</details>