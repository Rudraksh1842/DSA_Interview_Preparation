# 1800. Maximum Ascending Subarray Sum

## Problem

Given an array of positive integers `nums`, return the **maximum possible sum of an ascending subarray**.

A subarray `[nums[l], nums[l+1], ..., nums[r]]` is **ascending** if:

```
nums[i] < nums[i + 1]
```

for all:

```
l <= i < r
```

In other words, each element must be **strictly greater than the previous one**.

---

# Example

### Example 1

Input:

```text
nums = [10,20,30,5,10,50]
```

Output:

```text
65
```

Explanation:

Ascending subarrays:

```
[10,20,30] → sum = 60
[5,10,50] → sum = 65
```

Maximum sum = **65**

---

### Example 2

Input:

```text
nums = [10,20,30,40,50]
```

Output:

```text
150
```

Explanation:

The entire array is strictly ascending:

```
10 + 20 + 30 + 40 + 50 = 150
```

---

### Example 3

Input:

```text
nums = [12,17,15,13,10,11,12]
```

Output:

```text
33
```

Explanation:

Ascending subarrays:

```
[12,17] → 29
[10,11,12] → 33
```

Maximum sum = **33**

---

# Approach

We iterate through the array and maintain two variables:

* `currSum` → sum of the current ascending subarray
* `maxi` → maximum sum found so far

### Logic

1. Start with the first element.
2. If the current element is **greater than the previous element**, extend the ascending subarray.
3. Otherwise, start a **new subarray**.
4. Update the maximum sum at each step.

---

# C++ Implementation

```cpp
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int currSum = nums[0];
        int maxi = nums[0];

        for(int i = 1; i < nums.size(); i++){

            if(nums[i] > nums[i-1]){
                currSum += nums[i];
            }
            else{
                currSum = nums[i];
            }

            maxi = max(maxi, currSum);
        }

        return maxi;
    }
};
```

---

# Dry Run

Input:

```
nums = [10,20,30,5,10,50]
```

Steps:

```
currSum = 10, maxi = 10

20 > 10 → currSum = 30
maxi = 30

30 > 20 → currSum = 60
maxi = 60

5 <= 30 → currSum = 5

10 > 5 → cur
```
