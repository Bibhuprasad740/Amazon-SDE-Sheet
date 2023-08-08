## 04. Minimum distance between two numbers 

<span style="color: white; padding: 5px 20px; background-color: darkgreen; border-radius: 20px">Easy</span>

You are given an array A, of N elements. Find minimum index based distance between two elements of the array, x and y such that (x!=y). If no such distance is possible then return -1.

##### Example 1:
``` cpp
Input:
N = 4
A[] = {1,2,3,2}
x = 1, y = 2
Output: 1
Explanation: x = 1 and y = 2. There are two distances between x and y, which are
1 and 3 out of which the least is 1.
```

##### Example 2:
``` cpp
Input:
N = 7
A[] = {86,39,90,67,84,66,62}
x = 42, y = 12
Output: -1
Explanation: x = 42 and y = 12. We return -1 as x and y don't exist in the array.
```

##### Constraints: 
- **1 ≤ N ≤ 10^6**
- **1 ≤ arr[i] ≤ 10^6** 

### My Approach

- There is an important observation, **the difference between any two indices `i` and `j` can never be minimum if there are multiple occurances of `X` and `Y` from `i` to `j`.** 
- for e.g, 

```cpp
arr = [1, 4, 3, 2, 6, 1, 5, 2]
X = 1, Y = 2
```

Look at the index 0 and index 7. 
[**1**, 4, 3, 2, 6, 1, 5, **2**] 
These are the target elements, but it's for sure that the difference between these two indices is not minimum because there are multiple instances of `X = 1` and `y = 2` in between index 0 and index 7 ==> [**1**, 4, 3, **2**, 6, **1**, 5, **2**]
**So, the difference will be minimum if we find the recent occurance of X and the recent occurance of Y and then take difference**. 


##### Algorithm:

    - Take lastX and lastY as -1
    - Mark answer as infinity
    - For every element in the array, do the following:
        If the element at currentIndex equals to X, then 
            lastX = currentIndex
        Otherwise if the element at currentIndex equals to Y, then
            lastY = currentIndex
        If both lastX and lastY are not -1, then
            Make answer = minimum of ((current answer) and (absolute diffrence between lastX and lastY)).
    - If answer equals to infinity, then return -1
    - Otherwise return answer.

### Time and Auxiliary Space Complexity:

- **Time Complexity:** `O(n)` where `n` is the length of the array.
- **Space complexity:** `O(1)` as I am not using any extra space.

### Code(C++)

```cpp
class Solution{
  public:
    int minDist(int arr[], int n, int x, int y) {
        int posofx = -1, posofy = -1;
        int ans = 1e9;
        for(int i = 0; i < n; i++){
            if(arr[i] == x) {
                posofx = i;
            } else if (arr[i] == y) {
                posofy = i;
            }
            if(posofx != -1 and posofy != -1) {
                ans = min(ans, abs(posofx - posofy));
            }
        }
        
        return ans == 1e9 ? -1 : ans;
    }
};
```

- **If you find this solution helpful, consider supporting me by giving a `⭐ star` to the [Amazon-SDE-Sheet](https://github.com/Bibhuprasad740/Amazon-SDE-Sheet) repository.**

 ```cpp
 Made With ❤️ By Bibhu Prasad Sahoo
 ``` 