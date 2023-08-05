## 01. Replace all 0s with 5s

You are given an integer N. You need to convert all zeroes of N to 5.

##### Example 1:
``` cpp
Input:
N = 1004
Output: 1554
Explanation: There are two zeroes in 1004
on replacing all zeroes with "5", the new
number will be "1554".
```

##### Example 2:
``` cpp
Input:
N = 121
Output: 121
Explanation: Since there are no zeroes in
"121", the number remains as "121".
```

##### Constraints: 1 <= n <= 10000

### My Approach

The easiest way is to convert the number into a string and iterate over every digit from left to right and check whether it is a `0`. If it the case, then replace that `0` with `5` and then convert back the resulting string into number.

##### Algorithm:

    - Convert the number into a string.
    - Iterate from left to right and check if the character at ith index is 0 or not.
    - If it is 0, then change it to 5.
    - Convert back the resulting string into number.
    - Return the number.

### Time and Auxiliary Space Complexity:

- **Time Complexity:** `O(n)` where `n` is the length of the number.
- **Space complexity:** `O(1)` as I am not using any extra space.

### Code(C++)

```cpp
int convertFive(int n)
{
    string num = to_string(n);
    
    for(int i = 0; i < num.size(); i++){
        if(num[i] == '0') num[i] = '5';
    }
    
    return stoi(num);
}
```

- **If you find this solution helpful, consider supporting me by giving a `⭐ star` to the [Amazon-SDE-Sheet](https://github.com/Bibhuprasad740/Amazon-SDE-Sheet) repository.**

 ```cpp
 Made With ❤️ By Bibhu Prasad Sahoo
 ``` 
