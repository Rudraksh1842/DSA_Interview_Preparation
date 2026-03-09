# 1980. Find Unique Binary String

## 🔗 Problem Link

LeetCode - 1980. Find Unique Binary String

---

## 🧠 Problem Statement

Given an array `nums` containing **n unique binary strings**, each of length `n`, return a **binary string of length `n` that does not appear in `nums`**.

If there are multiple valid answers, you may return **any of them**.

---

## 📌 Example 1

**Input**

```
nums = ["01","10"]
```

**Output**

```
"00"
```

**Explanation**

Possible answers are `"00"` or `"11"` since neither exists in `nums`.

---

## 📌 Example 2

**Input**

```
nums = ["00","01"]
```

**Output**

```
"10"
```

---

## 📌 Example 3

**Input**

```
nums = ["111","011","001"]
```

**Output**

```
"101"
```

---

# 💡 Approach (Diagonalization Trick)

This solution uses a clever idea inspired by **Cantor's Diagonal Argument**.

### Key Idea

Construct a new string by **flipping the diagonal bits**:

* If `nums[i][i]` is `'0'`, append `'1'`
* If `nums[i][i]` is `'1'`, append `'0'`

This guarantees that the generated string **differs from every string in `nums` at least at one position**.

Therefore, the generated string **cannot exist in the given list**.

---

## 🚀 Algorithm

1. Let `n` be the number of binary strings.
2. Initialize an empty string `ans`.
3. For each index `i` from `0` to `n-1`:

   * If `nums[i][i] == '0'` → append `'1'`
   * Otherwise append `'0'`
4. Return the constructed string.

This ensures the new string differs from the `i-th` string at position `i`.

---

## 🧾 Implementation

```cpp
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(nums[i][i]=='0'){
                ans+='1';
            }
            else 
            ans+='0';
        }
        return ans;
    }
};
```

---

## ⏱️ Complexity Analysis

| Complexity       | Value    |
| ---------------- | -------- |
| Time Complexity  | **O(n)** |
| Space Complexity | **O(n)** |

---

## 🎯 Key Takeaways

* Uses **Cantor's Diagonalization principle**.
* Guarantees the generated string differs from every input string.
* Much more efficient than generating all binary combinations.
* Elegant **O(n) solution**.

---

## 🏷️ Tags

* String
* Hashing
* Math
* Bit Manipulation
* Cantor's Diagonalization
