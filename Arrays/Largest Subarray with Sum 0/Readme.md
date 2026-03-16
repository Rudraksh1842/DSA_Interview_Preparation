# Largest Subarray with Sum 0

## Problem

Given an array of integers `arr`, find the **length of the longest subarray whose sum is equal to 0**.

A subarray is a **contiguous part of the array**.

---

## Example

### Example 1

Input:

```text
arr = [15,-2,2,-8,1,7,10,23]
```

Output:

```text
5
```

Explanation:

The longest subarray with sum `0` is:

```
[-2, 2, -8, 1, 7]
```

Length = **5**

---

### Example 2

Input:

```text
arr = [1,2,-3,3]
```

Output:

```text
3
```

Explanation:

```
[1,2,-3]
```

Sum = **0**, Length = **3**

---

# Approach (Prefix Sum + HashMap)

## Key Idea

We use the concept of **Prefix Sum**.

If two prefix sums are equal:

```
prefixSum[i] == prefixSum[j]
```

then the subarray between them has sum:

```
0
```

because the sums cancel out.

Example:

```
prefixSum = [15, 13, 15]
```

Since `15` appears twice:

```
index 0 and index 2
```

The subarray between them:

```
[-2, 2]
```

has sum `0`.

---

# Important Trick

We initialize the hashmap with:

```
mp[0] = -1
```

This handles cases where the subarray starts from **index 0**.

Example:

```
[2, -2]
```

Prefix sum becomes `0` at index `1`.

Length becomes:

```
1 - (-1) = 2
```

---

# Algorithm

1. Create a hashmap `mp` to store **prefix sum → index**.
2. Insert `mp[0] = -1`.
3. Traverse the array and maintain a running `sum`.
4. If the sum already exists in the map:

   * A zero-sum subarray is found.
   * Update `maxLen`.
5. If the sum does not exist:

   * Store the index in the map.

---

# C++ Implementation

```cpp
class Solution {
public:
    int maxLen(vector<int>& arr) {

        unordered_map<int,int> mp;
        mp[0] = -1;

        int sum = 0;
        int maxLen = 0;

        for(int i = 0; i < arr.size(); i++){

            sum += arr[i];

            if(mp.find(sum) != mp.end()){
                maxLen = max(maxLen, i - mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }

        return maxLen;
    }
};
```

---

# Dry Run

Array:

```
[15,-2,2,-8,1,7,10,23]
```

Prefix sums:

```
15
13
15
7
8
15
25
48
```

Since `15` appears multiple times:

```
index 0 and index 5
```

Subarray:

```
[-2,2,-8,1,7]
```

Length:

```
5
```

---

# Complexity Analysis

| Complexity       | Value    |
| ---------------- | -------- |
| Time Complexity  | **O(n)** |
| Space Complexity | **O(n)** |

Explanation:

* We traverse the array once.
* HashMap stores prefix sums.

---

# Key Concepts

* Prefix Sum
* HashMap
* Longest Subarray Pattern
* Handling Negative Numbers

---

# Repository Path

```
DSA_Interview_Preparation/
└── Arrays/
    └── Largest_Subarray_With_Sum_0/
        └── README.md
```
