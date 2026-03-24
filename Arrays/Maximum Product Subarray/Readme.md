# 152. Maximum Product Subarray (LeetCode)

## 📌 Problem Statement

Given an integer array `nums`, find a contiguous subarray within the array that has the **largest product**, and return that product.

---

## 💡 Key Insight

Unlike sum problems, the product can flip sign due to negative numbers:

- A **negative × negative = positive**
- So a **minimum product can become maximum**, and vice versa

👉 That’s why we track:
- `currMax` → maximum product till current index
- `currMin` → minimum product till current index

---

## 🧠 Approach

1. Initialize:
   - `currMax = nums[0]`
   - `currMin = nums[0]`
   - `ans = nums[0]`

2. Traverse the array:
   - Store previous `currMax` (important for updating `currMin`)
   - Update:
     - `currMax = max(nums[i], currMax * nums[i], currMin * nums[i])`
     - `currMin = min(nums[i], prevMax * nums[i], currMin * nums[i])`
   - Update global answer:
     - `ans = max(ans, currMax)`

---

## 💻 Code

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin = nums[0];
        int currMax = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int temp = currMax;

            currMax = max({nums[i], currMax * nums[i], currMin * nums[i]});
            currMin = min({nums[i], nums[i] * temp, currMin * nums[i]});

            ans = max(currMax, ans);
        }

        return ans;
    }
};
