# 693. Binary Number with Alternating Bits

### 🔗 Problem Link
LeetCode - 693. Binary Number with Alternating Bits

---

## 🧠 Problem Statement

Given a positive integer `n`, return `true` if it has alternating bits in its binary representation.

Otherwise, return `false`.

An integer has alternating bits if no two adjacent bits are equal.

---

## 📌 Example 1

Input:
n = 5

Binary representation:
101

Output:
true

---

## 📌 Example 2

Input:
n = 7

Binary representation:
111

Output:
false

---

## 💡 Approach

### 🔥 Key Idea

1. Convert the number into its binary representation.
2. Store each bit into a vector.
3. Check adjacent elements:
   - If any two consecutive bits are equal → return `false`.
4. If no equal adjacent bits are found → return `true`.

---

## 🧾 Implementation

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> res;

        // Convert number to binary
        while(n > 0){
            int a = n % 2;
            n = n / 2;
            res.insert(res.begin(), a);
        }

        // Check for alternating bits
        for(int i = 0; i < res.size() - 1; i++){
            if(res[i + 1] == res[i]){
                return false;
            }
        }

        return true;
    }
};
```

---

## ⏱️ Complexity Analysis

Time Complexity: O(log n)  
- Number of bits in `n`.

Space Complexity: O(log n)  
- Storing binary representation.

---

## 🏷️ Tags

Bit Manipulation  
Binary Representation  
Simulation  

---

## 🎯 Key Takeaways

- Convert integer to binary using division by 2.
- Compare adjacent bits to verify alternation.
- Can be optimized further using bit manipulation without extra space.
