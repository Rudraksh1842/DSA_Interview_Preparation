# 190. Reverse Bits

### 🔗 Problem Link
LeetCode - 190. Reverse Bits

---

## 🧠 Problem Statement

Reverse bits of a given 32-bit unsigned integer.

Note:
- The input is treated as a 32-bit unsigned integer.
- You must reverse all 32 bits, including leading zeros.

---

## 💡 Approach

1. Initialize a variable `result` as 0.
2. Iterate exactly 32 times (since integer is 32-bit).
3. In each iteration:
   - Extract the last bit of `n` using `(n & 1)`.
   - Shift `result` left by 1 position.
   - Add the extracted bit to `result`.
   - Right shift `n` to process the next bit.
4. Return the final reversed number.

---

## 🔍 Key Concepts Used

- Bitwise AND (`n & 1`) → Extract last bit
- Left Shift (`<<`) → Make space for next bit
- Right Shift (`>>`) → Move to next bit
- Unsigned 32-bit integer (`uint32_t`)

---

## 🧾 Implementation

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        for(int i = 0; i < 32; i++) {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }

        return result;
    }
};
