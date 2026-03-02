# 744. Find Smallest Letter Greater Than Target

### 🔗 Problem Link
LeetCode - 744. Find Smallest Letter Greater Than Target

---

## 🧠 Problem Statement

Given a sorted array of characters `letters` and a character `target`, return the smallest character in the array that is strictly greater than `target`.

The letters wrap around:
- If no character is greater than `target`, return the first character in the array.

---

## 📌 Example 1

Input:
letters = ['c','f','j']  
target = 'a'

Output:
'c'

---

## 📌 Example 2

Input:
letters = ['c','f','j']  
target = 'j'

Output:
'c'

Explanation:
There is no character greater than 'j', so we return the first character due to wrap-around.

---

## 💡 Approach

### 🔥 Key Idea

1. Sort the array (to ensure correct order).
2. Traverse through the letters.
3. Return the first character greater than `target`.
4. If no such character exists, return the first element (wrap-around case).

---

## 🧾 Implementation

```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        sort(letters.begin(), letters.end());

        for(char ch : letters) {
            if(ch > target) {
                return ch;
            }
        }

        return letters[0]; 
    }
};
```

---

## ⏱️ Complexity Analysis

Time Complexity: O(n log n)  
- Sorting takes O(n log n)  
- Traversal takes O(n)

Space Complexity: O(1)  
- No extra space used (ignoring sorting space)

---

## 🏷️ Tags

Array  
Binary Search  
Sorting  

---

## 🎯 Key Takeaways

- Handle wrap-around carefully.
- Sorting ensures correct order before searching.
- Can be optimized further using binary search in O(log n).
