[Link to problem on Leetcode](https://leetcode.com/problems/maximum-units-on-a-truck/)



<details><summary>Sub-Optimal Solution</summary>

Sub-Optimal Solution: TC = `O(NlogN)`, SC = `O(1)` 

**Idea**:
- For this problem, we simply need to prioritize the more valuable boxes first. To do this, we should sort the boxtypes array (B) in descending order by the number of units per box (B[i][1]).

- Then we can iterate through B and at each step, we should add as many of the boxes as we can, until we reach the truck size (T). We should add the number of boxes added multiplied by the units per box to our answer (ans), and decrease T by the same number of boxes.

- Once the truck is full (T == 0), or once the iteration is done, we should return ans.

[Editorial Credits](https://leetcode.com/problems/maximum-units-on-a-truck/discuss/1271374/JS-Python-Java-C%2B%2B-or-Simple-Sort-Solution-w-Explanation)


Runtime: `86 ms`, faster than `43.10%`<br>
Memory Usage: `17.2 MB`, less than `32.38%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/1710-A.png)

</details>

</details>



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(N)`, SC = `O(max number of box units)`

**Intuition**:

The constraint that "boxes per unit" will be max 1000 allows us to use 1000 buckets to sort by boxes per unit.
Ie., we can create an array where the indices represent 0 boxes per unit, 1 boxes per unit, 2 boxes per unit, 3 boxes per unit, ... 1000 boxes per unit. And the buckets[i] will represent the number of boxes at each index.

**Algorithm**:

1. take the given data and sort it into the 1000 buckets. this is O(n) because we loop over the given data once.
2. loop over the buckets backwards- so that we start at a higher boxes per unit to get as many units as possible. in each iteration:

> - Check if the truck has space enough for all the boxes. if yes, load up all units.
> - if the truck hasn't enough space, load up only the units you can.
>

[Editorial Credits](https://leetcode.com/problems/maximum-units-on-a-truck/discuss/1000343/countingbucket-sort-O(n)-faster-than-100.)

Runtime: `53 ms`, faster than `77.34%`<br>
Memory Usage: `17.7 MB`, less than `30.86%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/1710-B.png)

</details>

</details>