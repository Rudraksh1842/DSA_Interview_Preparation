# 📘 XOR Queries of a Subarray

---

## 🧩 Problem Statement

Given an array `arr` and a list of queries `queries`, where each query is of the form `[left, right]`, return an array containing the XOR of elements between indices `left` and `right` (inclusive) for each query.

---

## 📥 Examples

### Example 1

```
Input:
arr = [1, 3, 4, 8]
queries = [[0,1], [1,2], [0,3], [3,3]]

Output:
[2, 7, 14, 8]
```

### Explanation:

```
[0,1] → 1 ^ 3 = 2  
[1,2] → 3 ^ 4 = 7  
[0,3] → 1 ^ 3 ^ 4 ^ 8 = 14  
[3,3] → 8
```

---

## ⚙️ Constraints

```
1 <= arr.length, queries.length <= 10^5
0 <= arr[i] <= 10^9
0 <= left <= right < arr.length
```

---

## 🧠 Approach (Prefix XOR)

### 💡 Key Idea

Instead of calculating XOR for every query using a loop (**O(N)** per query), we optimize using **Prefix XOR**.

---

## 🔑 Concept

### Prefix XOR Definition

```
prefix[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]
```

---

### Range XOR Formula

```
XOR(left → right) = prefix[right] ^ prefix[left - 1]
```

👉 Special case:

```
If left == 0:
XOR = prefix[right]
```

---

## 🚀 Algorithm

1. Create a `prefix` array:

   * `prefix[0] = arr[0]`
   * `prefix[i] = prefix[i-1] ^ arr[i]`
2. For each query `[left, right]`:

   * If `left == 0`, answer = `prefix[right]`
   * Else, answer = `prefix[right] ^ prefix[left - 1]`
3. Store results in array and return

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        vector<int> prefix(n);
        prefix[0] = arr[0];
        
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] ^ arr[i];
        }

        vector<int> res;

        for(int i = 0; i < queries.size(); i++){
            int left = queries[i][0];
            int right = queries[i][1];

            if(left == 0){
                res.push_back(prefix[right]);
            } else {
                res.push_back(prefix[right] ^ prefix[left - 1]);
            }
        }

        return res;
    }
};
```

---

## 🧪 Dry Run

### Input:

```
arr = [1, 3, 4, 8]
```

### Prefix XOR:

```
prefix = [1, 2, 6, 14]
```

### Query: [1,2]

```
prefix[2] ^ prefix[0] = 6 ^ 1 = 7
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O(N + Q)
* **Space Complexity:** O(N)

---

## 🔥 Key Takeaways

* Prefix XOR helps reduce repeated calculations
* XOR has a unique property:

  ```
  a ^ a = 0
  ```
* Always remember:

  ```
  XOR → use ^
  ```

---

## 🚀 Related Problems

* Subarray XOR = K
* Count Subarrays with XOR
* Prefix Sum Problems

---

⭐ Master Prefix XOR — it's frequently asked in product-based companies!
