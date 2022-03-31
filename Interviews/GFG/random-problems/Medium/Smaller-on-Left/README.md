My solution: TC = `O(NlogN)`, SC = `O(N)`

We can start traversing the array and maintain a set. <br>
When we encounter a element, we check if the set is non-empty and the lowest element of the set is smaller than the element or not. <br>
> If it is smaller, it means, we have atleast a valid candidate for this element. We then find the element using the lower bound element and decrementing the iterator. That is the highest value of an element smaller than A[i]. <br>
> If it is not, we conclude, either the set is empty or the smallest element of the set is greater than the current element, both of which will lead to the answer being -1. <br>
>
Finally we push the current element to the set. <br>

Total Time Taken: `0.7/2.2`