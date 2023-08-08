## 05. Rotate Array

<span style="color: white; padding: 5px 20px; background-color: darkgreen; border-radius: 20px">Easy</span>

Given an unsorted array arr[] of size N. Rotate the array to the left (counter-clockwise direction) by D steps, where D is a positive integer.  **The array must be modified in-place without using extra space.** 

##### Example 1:
``` cpp
Input:
N = 5, D = 2
arr[] = {1,2,3,4,5}
Output: 3 4 5 1 2
Explanation: 1 2 3 4 5  when rotated
by 2 elements, it becomes 3 4 5 1 2.
```

##### Example 2:
``` cpp
Input:
N = 10, D = 3
arr[] = {2,4,6,8,10,12,14,16,18,20}
Output: 8 10 12 14 16 18 20 2 4 6
Explanation: 2 4 6 8 10 12 14 16 18 20 
when rotated by 3 elements, it becomes 
8 10 12 14 16 18 20 2 4 6.
```

##### Constraints: 
- **1 <= N <= 10^6**
- **1 <= D <= 10^6**
- **0 <= arr[i] <= 10^5**

### My Approach

- If d is greater than n then, **rotating an array of size n, n + k times is same as rotating the array k times**. For e.g, Rotating [1,2,3,4,5] 7 times is same as rotating it 2 times. So we can take remainder of d / n and store it in d to be safe.
- Reversing the array from 0 to d first, then d to n and finally reversing the entire array will yield the actual output.


##### Algorithm:

    - Take remainder of n / d and store it in d
    - Reverse the array from start to position d
    - Reverse the array from position d to end
    - Reverse the entire array 

### Time and Auxiliary Space Complexity:

- **Time Complexity:** `O(n)` where `n` is the length of the array.
- **Space complexity:** `O(1)` as I am not using any extra space.

### Code(C++)

```cpp
class Solution{
    public:
    void rotateArr(int arr[], int d, int n){
        d = d % n;
        reverse(arr, arr + d);
        reverse(arr + d, arr + n);
        reverse(arr, arr + n);
    }
};
```

- **If you find this solution helpful, consider supporting me by giving a `⭐ star` to the [Amazon-SDE-Sheet](https://github.com/Bibhuprasad740/Amazon-SDE-Sheet) repository.**

 ```cpp
 Made With ❤️ By Bibhu Prasad Sahoo
 ``` 