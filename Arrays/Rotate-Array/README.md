# 189. Rotate Array

### 🔗 Problem Link
LeetCode - 189. Rotate Array

---

## 🧠 Problem Statement

Given an integer array `nums`, rotate the array to the right by `k` steps.

### Example:

Input:
nums = [1,2,3,4,5,6,7], k = 3

Output:
[5,6,7,1,2,3,4]

---

## 💡 Approach (Using Extra Array)

1. Create a temporary array `temp` of the same size as `nums`.
2. Traverse through the original array.
3. For each element at index `i`, place it at:
   
   (i + k) % n

   where `n` is the size of the array.
4. Copy the temporary array back to `nums`.

This ensures circular rotation.

---

## 🔍 Key Concept Used

### Modulo Operator (%)

The expression:

(i + k) % n

ensures that when the index exceeds array size,
it wraps around to the beginning (circular behavior).

---

## 🧾 Implementation

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        
        for(int i = 0; i < nums.size(); i++) {
            temp[(i + k) % nums.size()] = nums[i];
        }
        
        nums = temp;
    }
};
