Optimal Solution: TC = `O(NlogN)`, SC = `O(1)`

We need to select the maximum number of courses, such that none of them overlap. <br>
We can think of a greedy approach, where we start with course that ends the most early. <br>
This approach will give a correct answer because, the earlier a course ends, the more the courses we can opt for. <br>
Thus, we sort the array in ascending order of 2nd element of the vector. <br>
Then we pick greedily each course such that the last time of ending of a course is less than or equal to the start time of the current course. <br>

Total Time Taken: `0.44 / 1.52`