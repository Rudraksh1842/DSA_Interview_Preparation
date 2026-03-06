# 1784. Check if Binary String Has at Most One Segment of Ones

### 🔗 Problem Link
LeetCode - 1784. Check if Binary String Has at Most One Segment of Ones

---

## 🧠 Problem Statement

Given a binary string `s` without leading zeros, return **true** if `s` contains **at most one contiguous segment of ones**, otherwise return **false**.

A segment of ones means a group of consecutive `'1'` characters.

---

## 📌 Example 1

Input:
```
s = "1001"
```

Output:
```
false
```

Explanation:  
There are **two segments of '1'** → `"1"` and `"1"`.

---

## 📌 Example 2

Input:
```
s = "110"
```

Output:
```
true
```

Explanation:  
There is only **one segment of '1's**.

---

## 💡 Approach

We traverse the string and track whether we have already encountered a **segment of consecutive ones**.

### Logic

1. If the string starts with `'1'`, mark that we are currently inside a segment.
2. Traverse the string from index `1`.
3. If we encounter `'1'` and the previous character was `'0'` **after already seeing a segment**, it means a **new segment starts**, so return `false`.
4. Otherwise continue scanning the string.
5. If no second segment is found, return `true`.

---

## 🧾 Implementation

```cpp
class Solution {
public:
    bool checkOnesSegment(string s) {
      int flag=0;
      if(s[0]=='1'){
        flag=1;
      }
      for(int i=1;i<s.size();i++){
       
        if(s[i]=='1' && flag==1 && s[i-1]!='1'){
            return false;
        }
        if(s[i]=='1' && s[i-1]=='1'){
            flag=1;
        }

      }
        return true;
    }
};
```

---

## ⏱️ Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time Complexity | **O(n)** |
| Space Complexity | **O(1)** |

---

## 🎯 Key Takeaways

- A valid string can have **only one continuous block of '1's**.
- If we ever find `'1'` after a `'0'` **once a segment already existed**, the answer is **false**.
- The solution requires only **one pass through the string**.

---

## 🏷️ Tags

- String
- Greedy
- Simulation
