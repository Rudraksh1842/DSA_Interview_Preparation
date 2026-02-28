# 1356. Sort Integers by The Number of 1 Bits

### 🔗 Problem Link
LeetCode - 1356. Sort Integers by The Number of 1 Bits

---

## 🧠 Problem Statement

Given an integer array `arr`, sort the integers in ascending order by the number of 1's in their binary representation.

If two numbers have the same number of 1's, sort them in ascending order.

Return the sorted array.

---

## 📌 Example 1

Input:
arr = [0,1,2,3,4,5,6,7,8]

Output:
[0,1,2,4,8,3,5,6,7]

Explanation:
The binary representation of each number:

0 -> 0  (0 bits)
1 -> 1  (1 bit)
2 -> 10 (1 bit)
4 -> 100 (1 bit)
8 -> 1000 (1 bit)
3 -> 11 (2 bits)
5 -> 101 (2 bits)
6 -> 110 (2 bits)
7 -> 111 (3 bits)

Numbers are sorted first by bit count, then by value.

---

## 💡 Approach

### 🔥 Key Idea

1. Count the number of set bits (1's) for each number using `__builtin_popcount`.
2. Store pairs as:
   
   {bitCount, number}

3. Sort the vector of pairs.
   - Default sorting of `pair` sorts by `.first`
   - If equal, it sorts by `.second`
4. Extract only the numbers from the sorted pairs.

---

## 🧾 Implementation

```cpp
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> v;
        vector<int> res;

        // Store {bitCount, number}
        for(int num : arr){
            v.push_back({__builtin_popcount(num), num});
        }

        // Sort pairs (first by bit count, then by number)
        sort(v.begin(), v.end());

        // Extract numbers
        for(const auto &p : v){
            res.push_back(p.second);
        }

        return res;
    }
};
```

---

## ⏱️ Complexity Analysis

Time Complexity: O(n log n)  
- Building vector → O(n)  
- Sorting → O(n log n)

Space Complexity: O(n)  
- Extra vector to store pairs

---

## 🏷️ Tags

Array  
Sorting  
Bit Manipulation  

---

## 🎯 Key Takeaways

- `__builtin_popcount()` efficiently counts set bits.
- `pair` sorting is lexicographical (first → second).
- When sorting by multiple conditions, storing pairs is a clean approach.
