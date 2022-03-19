Optimal Solution: TC = `O(1)`, SC = `O(N)`

> The intuition is that we need to group the integers by their frequency in order of their appearance, such that incase of a tie, we can easily pop out the recently encountered element. <br>
> We use a hashmap of vector to store the groups and another hashmap to store the frequency of each element. <br>
> We also use a maxCount element to keep in check the most frequented element. <br>
> In the push() function, we increase the frequency of the element by 1, check if the frequency exceeds the maxCount, if it exceeds, we change the maxCount and push it in the group of it's new frequency in the hashmap of vectors. <br>
> In the pop() function, we take out the recently encountered element from the hashmap of vectors using the maxCount key. This is our answer. We decrease the frequency of the answer element by 1, check if the the corresponding vector size has hit 0, if it has hit 0, we decrease the maxCount by 1, since it is no more the most frequent count. <br>

Runtime: 218 ms, faster than 76.94%<br>
Memory Usage: 79.7 MB, less than 86.55%