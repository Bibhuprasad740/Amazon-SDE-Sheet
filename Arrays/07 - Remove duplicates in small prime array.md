## 07. Remove duplicates in small prime array

<span style="color: white; padding: 5px 20px; background-color: darkgreen; border-radius: 20px">Easy</span>

Given an array consisting of only prime numbers, remove all duplicate numbers from it. Retain only the first occurrence of the duplicate element.
**Note: The elements in the returning array should be in the same order as they appear in the original array.**

##### Example 1:

``` cpp
Input:
N = 6
A[] = {2,2,3,3,7,5}
Output: 2 3 7 5
Explanation: After removing the duplicate
2 and 3 we get 2 3 7 5.
```

##### Constraints: 
- **1<=N=10^6**
- **2<=A[i]<100**

### My Approach

- One thing to notice from the constraints is that, `A[i]` can never go beyond 99. 
- We can take a hash table or even an array of size 100 to store if an element was present earlier.


##### Algorithm:

    - Take an array of size 100 and mark 0 in each index let's say freq.
    - Scan the entire array and check 
        If the index of currentElement stores 0, then
            add currentElement in result array
        Mark the currentElement index as 1 in freq
    - Return the freq array.


### Time and Auxiliary Space Complexity:

- **Time Complexity:** `O(n)` where ``n` is size of the array
- **Space complexity:**  `O(1)` I am taking an array of size 100 which is anyways constant. 

### Code(C++)

```cpp
class Solution{
  public:
    vector<int> removeDuplicate(vector<int>& arr, int n)
    {
        vector<int> hash(100), ans;
        for(int i = 0; i < n; i++){
            if(!hash[arr[i]]) ans.push_back(arr[i]);
            hash[arr[i]] = 1;
        }
        
        return ans;
    }
};
```

- **If you find this solution helpful, consider supporting me by giving a `⭐ star` to the [Amazon-SDE-Sheet](https://github.com/Bibhuprasad740/Amazon-SDE-Sheet) repository.**

 ```cpp
 Made With ❤️ By Bibhu Prasad Sahoo
 ``` 