Optimal Solution: TC = O(4 x N) ≈ O(N) ≈ O(1), SC = O(1)

We can play with bits to obtain a constant time-complexity. <br>
We have been given 2 segments in the binary representation to be swapped with each other. Let us create a third segment which is very away from the maximum bound (p2 + n) can reach. Let's take this bound as 20. <br>
We will swap with the method of swapping using a third variable. The third variable here is the third segment. <br>
We transfer the bits of the segment [p1, p1 + n] to the third segment [20, 20 + n] using this: <br>
> If the i-th bit is set, i.e, `x & (1 << i) != 0` we set the j-th bit using XOR operator ∀ i ∈ [p1, p1 + n] and ∀ j ∈ [20, 20 + n]. Setting the j-th bit means doing `x ^ (1 << j)`. <br>
> If the i-th bit is not set, we don't do anything as the far away bits are already un-set. <br>
Next up, we transfer the bits of the segment [p2, p2 + n] to the segment [p1, p1 + n], since we have already transferred the bits of [p1, p1 + n] to the far position. <br>
> If the i-th bit is set, i.e, `x & (1 << i) != 0` we set the j-th bit using OR operator ∀ i ∈ [p2, p2 + n] and ∀ j ∈ [p1, p1 + n]. Setting the j-th bit means doing `x | (1 << j)`. <br>
> If the i-th bit is not set, we check if the j-th bit is set or not: <br>
>> If it is set, we unset it using XOR operator, like `x ^ (1 << j`. <br>
>> If it is not set, we don't do anything as we want the bit to remain unset. <br>

We have finished segment [p1, p1 + n]. The remaining work is with segment [p2, p2 + n] and unsetting all the bits of [20, 20 + n]. <br>
The transeferring of bits from segment [20 , 20+ n]  to segment [p2, p2 + n] follows the same strategy as from segment [p2, p2 + n] to segment [p1, p1 + n], described above.<br>
Hence, the only remaining is unsetting the bits of segment [20, 20 + n] as that was only a dummy segment and we need to return it in it's original state. <br>
The unsetting is easy, we just check if i-th bit is set ∀ i ∈ [20, 20 + n], if it is set, we unset it using XOR operator, i.e, `x ^ (1 << i)`. <br>  
Finally, x will hold our answer. <br>

Total Time Taken: `0.0/1.1`<br>
Your Accuracy: `50%`
