# 27. Remove Element

### 🔗 Problem Link
LeetCode - 27. Remove Element

---

## 🧠 Problem Statement

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in-place.

The relative order of the elements may be changed.

Return the number of elements in `nums` which are not equal to `val`.

---

## 📌 Example 1

Input:
nums = [3,2,2,3], val = 3

Output:
2

Explanation:
After removing all occurrences of 3, nums = [2,2].
Return k = 2.

---

## 📌 Example 2

Input:
nums = [0,1,2,2,3,0,4,2], val = 2

Output:
5

Explanation:
After removing all occurrences of 2, nums = [0,1,3,0,4].
Return k = 5.

---

## 💡 Approach

### 🔥 Key Idea

- Traverse the array.
- Store all elements that are NOT equal to `val` in a new vector.
- Replace the original vector with the filtered one.
- Return the count of remaining elements.

---

## 🧾 Implementation

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> ans;
        int n = nums.size();
        int k = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] != val)
            {
                ans.push_back(nums[i]);
                k++;
            }
        }

        nums = ans;
        return k;
    }
};
```

---

## ⏱️ Complexity Analysis

Time Complexity: O(n)  
- Single traversal of the array.

Space Complexity: O(n)  
- Extra vector used to store filtered elements.

---

## 🏷️ Tags

Array  
Two Pointers  
In-place Modification  

---

## 🎯 Key Takeaways

- Simple filtering approach.
- Uses extra space to store valid elements.
- Can be optimized to O(1) space using two-pointer technique.
