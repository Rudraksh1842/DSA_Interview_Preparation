# 26. Remove Duplicates from Sorted Array

### 🔗 Problem Link
LeetCode - 26. Remove Duplicates from Sorted Array

---

## 🧠 Problem Statement

Given a **sorted** integer array `nums`, remove the duplicates in-place such that each unique element appears only once.

Return the number of unique elements `k`.

The first `k` elements of `nums` should contain the unique elements.

You must solve it **without using extra space**.

---

## 📌 Example

Input:
nums = [1,1,2]

Output:
2  
Modified nums = [1,2,_]

---

## 💡 Approach (Two Pointer Technique)

Since the array is already sorted, duplicate elements will always be adjacent.

### Idea:

- Use one pointer `i` to iterate through the array.
- Use another pointer `k` to track the position of the next unique element.
- When we find a new element (different from previous), place it at index `k`.

---

## 🔍 Algorithm

1. Initialize `k = 1` (first element is always unique).
2. Traverse the array from index `1` to `n-1`.
3. If `nums[i] != nums[i-1]`:
   - Assign `nums[k] = nums[i]`
   - Increment `k`
4. Return `k`

---

## 🧾 Implementation

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        
        return k;
    }
};
