# 961. N-Repeated Element in Size 2N Array

### 🔗 Problem Link
LeetCode - 961. N-Repeated Element in Size 2N Array

---

## 🧠 Problem Statement

You are given an integer array `nums` with the following properties:

- `nums.length == 2 * n`
- The array contains **n + 1 unique elements**
- Exactly **one element is repeated n times**

Return the element that is repeated **n times**.

---

## 📌 Example 1

Input:
```
nums = [1,2,3,3]
```

Output:
```
3
```

---

## 📌 Example 2

Input:
```
nums = [2,1,2,5,3,2]
```

Output:
```
2
```

---

## 💡 Optimal Approach

### 🔍 Key Observation

Since:

```
Array size = 2N
One element repeats N times
```

The repeated element **must appear very close to itself**.

Therefore, we only need to check if:

```
nums[i] == nums[i+1]
nums[i] == nums[i+2]
nums[i] == nums[i+3]
```

One of these comparisons will always identify the repeated element.

This allows us to solve the problem **without extra space**.

---

## 🚀 Algorithm

1. Traverse the array.
2. For every index `i`, check:
   - If `nums[i] == nums[i+1]`
   - If `nums[i] == nums[i+2]`
   - If `nums[i] == nums[i+3]`
3. If any condition is true → return that element.

---

## 🧾 Implementation

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(i+1 < n && nums[i] == nums[i+1]) return nums[i];
            if(i+2 < n && nums[i] == nums[i+2]) return nums[i];
            if(i+3 < n && nums[i] == nums[i+3]) return nums[i];
        }

        return -1;
    }
};
```

---

## ⏱️ Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time Complexity | **O(n)** |
| Space Complexity | **O(1)** |

---

## 🎯 Key Takeaways

- Problem has a **hidden mathematical constraint**.
- The repeated element cannot be far from itself.
- We can solve it **without using HashMap or extra memory**.
- Efficient **constant space solution**.

---

## 🏷️ Tags

- Array
- Hashing
- Mathematical Observation
- Greedy
