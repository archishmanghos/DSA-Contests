Optimal Solution: TC = `O(N)`, SC = `O(1)`

We can see that as we shrink the rectangle from any side, the width of the container decreases irrespective of the side we shrink. <br>
Hence, everytime we shrink, we need to shrink towards the larger height rectangles, so that the area remains equal to increases. <br>
This hints us towards a 2-pointer solution. <br>
We put pointer-1 to the start of the array and pointer-2 to the end of the array. <br>
At every point we calculate the area and maximise it using another variable and then we shrink it to the right if the height of the bar of pointer-1 is lesser than that of poiter-2, else we shrink it to the left. <br>

Runtime: `88 ms`, faster than `86.45%`<br>
Memory Usage: `59 MB`, less than `81.47%`