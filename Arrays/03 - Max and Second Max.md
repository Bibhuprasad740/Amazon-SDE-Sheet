## 03. Max and Second Max 

<span style="color: white; padding: 5px 20px; background-color: darkgreen; border-radius: 20px">Easy</span>

Given an array arr[] of size N of positive integers which may have duplicates. The task is to find the maximum and second maximum from the array, and both of them should be different from each other, so If no second max exists, then the second max will be -1.

##### Example 1:
``` cpp
Input:
N = 3
arr[] = {2,1,2}
Output: 2 1
Explanation: From the given array 
elements, 2 is the largest and 1 
is the second largest.
```

##### Example 2:
``` cpp
Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 5 4
Explanation: From the given array 
elements, 5 is the largest and 4 
is the second largest.
```

##### Constraints: 
- **1 ≤ N ≤ 10^6**
- **1 ≤ arr[i] ≤ 10^6** 

### My Approach

- Let's take two variables `largest`, `secondLargest` to begin. 
- As it is explicitly asked to return `-1` if we can't get a valid output, initialize all the three variables with `-1`. 
- We iterate over every element of the array and check the following.
- If the currentElement is greater than our `largest` , then it is clear that we will update our `largest` value, and if we have a bigger number than our `largest` , then the value present at `largest` , is now the second largest. so store the value of `largest` in `secondLargest`. 

##### Algorithm:

    - Initialize largest, secondLargest to -1
    - Iterate from index 0 to n-1 and do the following:
    - If the currentElement is greater than largest, update
        secondLargest = largest
        largest = currentElement
    - Else check if currentElement is greater than secondLargest, update
        secondLargest = currentElement
    - Return the largest and secondLargest as a vector.

### Time and Auxiliary Space Complexity:

- **Time Complexity:** `O(n)` where `n` is the length of the number.
- **Space complexity:** `O(1)` as I am not using any extra space.

### Code(C++)

```cpp
class Solution{
  public:
    vector<int> largestAndSecondLargest(int n, int arr[]){
        int largest = -1, second= -1;
        
        for(int i = 0; i < n; i++){
            if(arr[i] > largest) {
                second = largest;
                largest = arr[i];
            } else if (arr[i] > second and arr[i] != largest) {
                second = arr[i];
            }
        }
        
        return {largest, second};
    }
};
```

- **If you find this solution helpful, consider supporting me by giving a `⭐ star` to the [Amazon-SDE-Sheet](https://github.com/Bibhuprasad740/Amazon-SDE-Sheet) repository.**

 ```cpp
 Made With ❤️ By Bibhu Prasad Sahoo
 ``` 