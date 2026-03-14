# 229. Majority Element II

## Problem

Given an integer array `nums`, return all the elements that appear **more than ⌊ n / 3 ⌋ times**.

Where:

* `n` = size of the array.

You may return the answer in **any order**.

---

## Example

### Example 1

Input:

```text
nums = [3,2,3]
```

Output:

```text
[3]
```

---

### Example 2

Input:

```text
nums = [1]
```

Output:

```text
[1]
```

---

### Example 3

Input:

```text
nums = [1,2]
```

Output:

```text
[1,2]
```

---

# Key Observation

In an array of size `n`, **there can be at most two elements** that appear more than `n/3` times.

Why?

If there were **three elements** appearing more than `n/3` times:

```
n/3 + n/3 + n/3 > n
```

which is **impossible**.

---

# Approach (Hash Map)

1. Use a **hash map** to store the frequency of each element.
2. Traverse the array and count occurrences.
3. Traverse the map and check:

   * If frequency > `n/3`, add it to the result.

---

# C++ Implementation

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<_
```
