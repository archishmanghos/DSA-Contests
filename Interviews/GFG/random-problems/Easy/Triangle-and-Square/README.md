Optimal Solution: TC = `O(1)`, SC = `O(1)`

Some key observations: <br>
> *Observation 1:* The available area to fit any number of 2x2 squares on any base is (Base - 2). <br>
>> *Explanation:* This is because, the triangle tapers somewhat inside and hence we cannot use that area to fit a square of size 2x2. Since, we have to leave a space, the space left is 2 units. <br>
>>
> *Observation 2:* For a base of odd size, we need to leave another unit. <br>
>> *Explanation:* This is so that the value of base becomes divisible by 2 as the length of the square is 2 units. <br> 
>> Thus, we need to leave 2 + (base % 2) units of length for utilising space to keep the squares. <br>
>>
> *Observation 3:* The height of the triangle will be equal to length of base. <br>
>> *Explanation:* We need to consider that the triangle is isosceles and the hypotenuse cannot be equal to the base since it's a right-angled triangle. <br>
>>
> *Observation 4:* The number of squares decrease by 1, everytime we stack another layer. <br>
>> *Explanation:* For every unit of height above base, the triangle tapers towards the inside. <br>
>> Thus if the base contained x squares, the above layer will contain (x - 1) squares. <br>
>>
> *Observation 5:* The number of squares will decrease till 1. <br>
>> *Explanation:* This is because the hypotenuse will meet the top and there will come a time, when we will be unable to put a square. <br>
>>
>
Thus, finally, we can calculate how many squares we can fit on the base. Suppose the value is `N`. Now the number of squares will be the sum of all integers from [1 to N], which is `N x (N + 1) / 2`.

Total Time Taken: `0.01/2.2`