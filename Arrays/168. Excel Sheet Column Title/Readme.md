# 📘 Excel Sheet Column Title

## 🧩 Problem Statement

Given an integer `columnNumber`, return its corresponding column title as it appears in an Excel sheet.

### 🔤 Mapping:

```
A -> 1  
B -> 2  
C -> 3  
...  
Z -> 26  
AA -> 27  
AB -> 28  
...
```

---

## 📥 Examples

### Example 1

```
Input: columnNumber = 1  
Output: "A"
```

### Example 2

```
Input: columnNumber = 28  
Output: "AB"
```

### Example 3

```
Input: columnNumber = 701  
Output: "ZY"
```

---

## ⚙️ Constraints

```
1 <= columnNumber <= 2^31 - 1
```

---

## 🧠 Approach

This problem is a variation of **base-26 conversion**, but with a twist:

* Instead of digits `0–25`, Excel uses `1–26`
* There is **no zero**, which makes it different from standard base systems

### 💡 Key Idea

Before taking modulo, decrement the number:

```
columnNumber--
```

This converts the system into **0-based indexing**:

```
0 → A  
1 → B  
...  
25 → Z  
```

---

## 🚀 Algorithm

1. Initialize an empty string `result`
2. While `columnNumber > 0`:

   * Decrement `columnNumber`
   * Compute character:

     ```
     char ch = 'A' + (columnNumber % 26)
     ```
   * Append to result
   * Divide `columnNumber` by 26
3. Reverse the result
4. Return it

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            columnNumber--; 
            
            char ch = 'A' + (columnNumber % 26);
            result += ch;
            
            columnNumber /= 26;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
```

---

## 🧪 Dry Run

### Input: 28

```
28 - 1 = 27 → 27 % 26 = 1 → 'B'  
27 / 26 = 1  

1 - 1 = 0 → 0 % 26 = 0 → 'A'
```

Result before reverse: `"BA"`
Final Output: `"AB"`

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O(log₍26₎ n)
* **Space Complexity:** O(1) (excluding output)

---

## 🔥 Key Takeaways

* Modified **base-26 conversion**
* No zero in mapping (1–26 instead of 0–25)
* `columnNumber--` is the most important step

---

## 🚀 Related Problems

* Excel Sheet Column Number
* Base Conversion Problems
* String Encoding / Decoding

---

⭐ Star this repo if it helped you!
