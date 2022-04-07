Optimal Solution: TC = `O(101 x 101)`, SC = `O(105)`

We count the occurences of each array element in a vector. <br>
We traverse for all elements 0 to 100, consider this as i and run a nested for loop for all elements from 0 to 100, consider this as j. <br>
We check if k exists. k is derived as [target - i -j]. <br>
If k exist, 3 conditions arise: <br>
> `i = j = k`: This means, 3 of the elements are equal. Hence we have to choose 3 elements from the total count of integer i, which is NC3, where N is the count of i. <br>
> `i = j and j != k`: Here 2 elements are same. Hence we have to take 2 elements from the count of i and multiply the result with count of k. <br>
> `i < j and j < k`: 3 of the elements are difference. Hence we multiply the count of i and count of j and count of k. <br>
>

Runtime: `25 ms`, faster than `74.83%`<br>
Memory Usage: `10.4 MB`, less than `74.83%`