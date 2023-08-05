## 02. Third largest element

Given an array of distinct elements. Find the third largest element in it.

Suppose you have `A[] = {1, 2, 3, 4, 5, 6, 7}`, its output will be 5 because it is the 3 largest element in the array A. Return `-1` if there are less than 3 elements in the given array.

##### Example 1:
``` cpp
Input:
N = 5
A[] = {2,4,1,3,5}
Output: 3
```

##### Example 2:
``` cpp
Input:
N = 2
A[] = {10,2}
Output: -1
```

##### Constraints: 
- **1 ≤ N ≤ 10^5**
- **1 ≤ A[i] ≤ 10^5** 

### My Approach

- Let's take three variables `largest`, `secondLargest` and `thirdLargest` to begin. 
- As it is explicitly asked to return `-1` if we can't get a valid output, initialize all the three variables with `-1`. 
- We iterate over every element of the array and check the following.
- If the currentElement is greater than our `largest` , then it is clear that we will update our `largest` value, and if we have a bigger number than our `largest` , then the value present at `largest` , is now the second largest. so store the value at `largest` in `secondLargest`. 
- Similarly, when we change `secondLargest` , we must store the value at `secondLargest` in `thirdLargest`. 

##### Algorithm:

    - Initialize largest, secondLargest and thirdLargest to -1
    - Iterate from index 0 to n-1 and do the following:
    - If the currentElement is greater than largest, update
        thirdLargest = secondLargest
        secondLargest = largest
        largest = currentElement
    - Else check if currentElement is greater than secondLargest, update
        thirdLargest = secondLargest
        secondLargest = currentElement
    - Else check if currentElement is greater than thirdLargest, update
        thirdLargest = currentElement
    - Return the thirdLargest.

### Time and Auxiliary Space Complexity:

- **Time Complexity:** `O(n)` where `n` is the length of the number.
- **Space complexity:** `O(1)` as I am not using any extra space.

### Code(C++)

```cpp
class Solution{
  public:
    int thirdLargest(int arr[], int n)
    {
         int largest = -1, second = -1, third = -1;
         for(int i = 0; i < n; i++){
             if(arr[i] > largest){
                 third = second;
                 second = largest;
                 largest = arr[i];
             } else if(arr[i] > second) {
                 third = second;
                 second = arr[i];
             } else if(arr[i] > third){
                 third = arr[i];
             }
         }
         return third;
    }

};
```

- **If you find this solution helpful, consider supporting me by giving a `⭐ star` to the [Amazon-SDE-Sheet](https://github.com/Bibhuprasad740/Amazon-SDE-Sheet) repository.**

 ```cpp
 Made With ❤️ By Bibhu Prasad Sahoo
 ``` 
