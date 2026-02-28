# 67. Add Binary

### 🔗 Problem Link
LeetCode - 67. Add Binary

---

## 🧠 Problem Statement

Given two binary strings `a` and `b`, return their sum as a binary string.

You must perform binary addition and return the result as a string.

---

## 📌 Example 1

Input:
a = "11"  
b = "1"

Output:
"100"

---

## 📌 Example 2

Input:
a = "1010"  
b = "1011"

Output:
"10101"

---

## 💡 Approach: Binary Addition (Right to Left with Carry)

### 🔥 Key Idea

- Start from the last character of both strings.
- Add digits along with carry.
- Store `(sum % 2)` as the result digit.
- Update `carry = sum / 2`.
- Continue until both strings and carry are exhausted.

This simulates how we perform binary addition manually.

---

## 🧾 Implementation

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            ans.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

---

## ⏱️ Complexity Analysis

Time Complexity: O(n)  
- Single traversal of both strings.

Space Complexity: O(n)  
- Result string stores at most `max(a.length, b.length) + 1`.

---

## 🏷️ Tags

String  
Binary  
Simulation  
Bit Manipulation  

---

## 🎯 Key Takeaways

- Avoid converting large binary strings to integers (overflow risk).
- Simulate addition directly using carry.
- Always compute result bit and carry from the same original sum.
- `push_back()` + `reverse()` is cleaner than inserting at the beginning.
