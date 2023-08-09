## 05. Max sum path in two arrays

<span style="color: white; padding: 5px 20px; background-color: darkgreen; border-radius: 20px">Easy</span>

Given two sorted arrays A and B of size M and N respectively. Each array may have some elements in common with the other array. Find the maximum sum of a path from the beginning of any array to the end of any of the two arrays. We can switch from one array to another array only at the common elements. **Both the arrays are sorted.**
**Note:** Only one repeated value is considered in the valid path sum.

##### Example 1:

``` cpp
Input:
M = 5, N = 4
A[] = {2,3,7,10,12}
B[] = {1,5,7,8}
Output: 35
Explanation: The path will be 1+5+7+10+12
= 35.
```

##### Example 2:
``` cpp
M = 3, N = 3
A[] = {1,2,3}
B[] = {3,4,5}
Output: 15
Explanation: The path will be 1+2+3+4+5=15.
```

##### Constraints: 
- **1 <= M,N <= 10^4**
- **1 <= A[i], B[i] <= 10^4**

### My Approach

- The idea is to break the arrays at every common element let's call it a `breakPoint` 
```cpp
for e.g,
A[] = {2,3,7,10,12}
B[] = {1,5,7,8}
here 7 is a breakPoint
```
- At every stage we notice that, two paths can be possible to reach to that `breakPoint` from the start(or from the previous `breakPoint`).
- There are two cases
a. There are no `breakPoint` at all
b. There is/are  `breakPoint`

**Case 1: No BreakPoints**
This is the simplest case, if we don't have a `breakPoint` then we can take the sum of all elements of both the arrays and return the maximum value.  

```cpp
for e.g,
arr1 = [1, 2, 3, 4, 5] // sum = 15
arr2 = [6, 7, 8, 9, 10] // sum = 40

so the answer is 40 simple.
```
**Case 2: There is a BreakPoint**
- If we found a `breakPoint` then at that point of time we can decide which path we will take. Obviously the path which resulted more sum we will take that path. So we will keep cumulative sum of `arr1` and `arr2` in two variables `sum1` and `sum2` respectively. 
- We will take two pointers `i` and `j` to point `arr1` and `arr2` respectively. 
- At every point, we want to go one step closer to `case 1` so that we just decide which path to choose.
- If `arr1[i]` > `arr2[j]` then, incrementing the `i` pointer will never result in `case 1` as `arr1[i]` is already greater than `arr2[j]` and the arrays are sorted in assending order. Incrementing `i` will result in an even bigger value of `arr1[i]`. Hence, increment `j` pointer so that may be next time we will find `arr1[i]` == `arr2[j]` and we can take the decission according to `case 1`. Before incrementing `j` add the value of `arr2[j]` in `sum2` to compare when we reach `breakPoint`
- Similarly, if `arr1[i]` < `arr2[j]` store the value of `arr1[i]` in `sum1` and increment the `i` pointer.


##### Algorithm:

    - Mark sum1 and sum2 as 0
    - Take two pointers i, j and mark them as 0
    - Mark result as 0
    - While both the pointers are pointing to array elements do the following
        If element at ith index in arr1 > element at jth index in arr2:
            Add jth element of arr2 in sum2
            Increment j
        Else if element at ith index in arr1 < element at jth index in arr2:
            Add ith element of arr1 in sum1
            Increment i
        Otherwise both the elements are equal, then
            Add max of sum1 and sum2 with result
            Add currentElement with result
            Reset sum1 and sum2 to 0
            Increment both the pointers
    - If elements left in arr1, then add all the remaining elements in sum1.
    - If elements left in arr2, then add all the remaining elements in sum2.
    - Add max of sum1 and sum2 with result.
    - Return result.



### Time and Auxiliary Space Complexity:

- **Time Complexity:** `O(m + n)` where `m` is the length of the array1 and `n` is length of array2.
- **Space complexity:** `O(1)` as I am not using any extra space.

### Code(C++)

```cpp
class Solution{
    public:
     int max_path_sum(int arr1[], int arr2[], int m, int n)
    {
        int sum1 = 0, sum2 = 0, i = 0, j = 0, result = 0;
        while(i < m and j < n) {
            if(arr1[i] > arr2[j]) {
                sum2 += arr2[j];
                j++;
            } else if (arr1[i] < arr2[j]) {
                sum1 += arr1[i];
                i++;
            } else {
                result += max(sum1, sum2);
                result += arr1[i];
                sum1 = 0, sum2 = 0;
                i++, j++;
            }
        }
        
        while(i < m) {
            sum1 += arr1[i];
            i++;
        }
        while(j < n) {
            sum2 += arr2[j];
            j++;
        }
        result += max(sum1, sum2);
        
        return result;
    }
};
```

- **If you find this solution helpful, consider supporting me by giving a `⭐ star` to the [Amazon-SDE-Sheet](https://github.com/Bibhuprasad740/Amazon-SDE-Sheet) repository.**

 ```cpp
 Made With ❤️ By Bibhu Prasad Sahoo
 ``` 