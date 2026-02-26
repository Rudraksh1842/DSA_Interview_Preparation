# 53. Maximum Subarray

### 🔗 Problem Link
LeetCode - 53. Maximum Subarray

---

## 🧠 Problem Statement

Given an integer array `nums`, find the subarray with the largest sum, and return its sum.

A subarray is a contiguous part of an array.

---

## 📌 Example 1

Input:
nums = [-2,1,-3,4,-1,2,1,-5,4]

Output:
6

Explanation:
The subarray [4,-1,2,1] has the largest sum = 6.

---

## 📌 Example 2

Input:
nums = [1]

Output:
1

---

## 💡 Approach: Kadane’s Algorithm (Optimal)

### 🔥 Key Idea

If the current running sum becomes negative, 
it will only reduce the future subarray sum.

So:
- Keep adding elements to `currSum`
- Update `maxSum`
- If `currSum` becomes negative → reset it to 0

---

## 🧾 Implementation

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            currSum += nums[i];

            maxSum = max(currSum, maxSum);

            if(currSum < 0) {
                currSum = 0;
            }
        }

        return maxSum;
    }
};
