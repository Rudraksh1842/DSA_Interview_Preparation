# 169. Majority Element

### 🔗 Problem Link
LeetCode - 169. Majority Element

---

## 🧠 Problem Statement

Given an array `nums` of size `n`, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.

It is guaranteed that the majority element always exists in the array.

---

## 📌 Example

Input:
nums = [3,2,3]

Output:
3

---

## 💡 Approach 1: Using Hash Map (Basic)

We can count the frequency of each element using an unordered_map.

### Steps:
1. Traverse the array and count frequencies.
2. Return the element whose frequency is greater than `n/2`.

### Code

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;

        for(int num : nums) {
            m[num]++;
        }

        for(auto it : m) {
            if(it.second > nums.size() / 2) {
                return it.first;
            }
        }

        return -1;
    }
};
