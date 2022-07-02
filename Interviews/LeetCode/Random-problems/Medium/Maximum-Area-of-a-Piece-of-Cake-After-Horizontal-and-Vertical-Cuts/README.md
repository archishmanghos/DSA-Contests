[Link to problem on Leetcode](https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/)



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(NlogN + N)`, SC = `O(1)`

**Key idea**:
- If we need the area, we must think of lengths and breadths of each cake piece.

**Assume**
- LENGTH as total horizontal length of the original cake.
- HEIGHT as total vertical height of the original cake.
- H as number of horizontal cuts. HCUTS is array of horizontal cuts.
- Similarly, V as number of vertical cuts and VCUTS is an array of vertical cuts.

**Solution**

1. Let's only think of horizontal cuts. Each HCUTS[i] would create a piece with length LENGTH and height, say, heights[i].
As there are H cuts, there will be (H+1) pieces of length LENGTH.

2. Now each vertical cut VCUTS[i] will cut each of the horizontal pieces that we got in step 1.
We already know the height of each piece (step 1), now with each vertical cut, we will know the length of each piece as well.

3. Because we want the maximize the area, we must try to maximize the length and height of each piece.

**Algorithm**

1. Find heights of pieces if we only perform the horizontal cuts. Say this array is heights[].
2. Find lengths of pieces if we only perform the vertical cuts. Say this arrays is lengths[].
3. Find max of heights[] and lengths[].
4. Multiply those two max and take mod 10e7.
5. Return the answer

[Editorial Credits](https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/discuss/661995/Do-you-like-visual-explanation-You-got-it.-%3A-)-With-2-code-variations.)


Runtime: `112 ms`, faster than `37.93%`<br>
Memory Usage: `32.2 MB`, less than `76.96%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/1465.png)

</details>

</details>