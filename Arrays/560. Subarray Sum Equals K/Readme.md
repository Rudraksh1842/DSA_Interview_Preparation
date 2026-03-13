# 560. Subarray Sum Equals K

## Problem

Given an integer array `nums` and an integer `k`, return the **total number of continuous subarrays whose sum equals `k`**.

A **subarray** is a contiguous part of an array.

---

## Example

### Example 1

Input:

```text
nums = [1,1,1]
k = 2
```

Output:

```text
2
```

Explanation:

```text
Subarrays with sum = 2

[1,1] (index 0 → 1)
[1,1] (index 1 → 2)
```

---

# Approach

A brute force approach would check all subarrays and calculate their sums, which takes **O(n²)** time.

To optimize this, we use:

### Prefix Sum + HashMap

The idea is:

If:

```
prefixSum[j] - prefixSum[i] = k
```

Then the subarray between `i+1` and `j` has sum `k`.

Rearranging:

```
prefixSum[i] = prefixSum[j] - k
```

So if we previously saw a prefix sum equal to `sum - k`, we found a valid subarray.

---

# Algorithm

1. Create a hashmap to store **prefix sum frequencies**.
2. Initialize:

```
map[0] = 1
```

This handles cases where the subarray starts from index `0`.

3. Traverse the array:

* Update running sum
* Check if `(sum - k)` exists in the hashmap
* Add its frequency to the count
* Store the current prefix sum in the hashmap

---

# C++ Implementation

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;

        int count = 0;
        int sum = 0;

        m[0] = 1;

        for(int n : nums){
            sum += n;

            if(m.find(sum - k) != m.end()){
                count += m[sum - k];
            }

            m[sum]++;
        }

        return count;
    }
};
```

---

# Dry Run

Example:

```
nums = [1,1,1]
k = 2
```

Step-by-step:

| Element | Running Sum | Sum-k | Found? | Count |
| ------- | ----------- | ----- | ------ | ----- |
| 1       | 1           | -1    | No     | 0     |
| 1       | 2           | 0     | Yes    | 1     |
| 1       | 3           | 1     | Yes    | 2     |

Final answer:

```
2
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
* Subarray Problems
* Frequency Counting

---

# Repository Path

```
DSA_Interview_Preparation/
└── Prefix_Sum/
    └── 560_Subarray_Sum_Equals_K/
        └── README.md
```
