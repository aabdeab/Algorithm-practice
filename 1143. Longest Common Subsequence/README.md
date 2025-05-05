# 🧩 Problem: 1143. Longest Common Subsequence

## 📜 Description

Given two strings `text1` and `text2`, return *the length of their longest common subsequence*.  

A **subsequence** of a string is a sequence that can be derived from the string by deleting some or no characters without changing the order of the remaining characters.

- **Example:**
    ```text
    Input: text1 = "abcde", text2 = "ace"
    Output: 3
    Explanation: The LCS is "ace"
    ```

- **Constraints:**
  - `1 <= text1.length, text2.length <= 1000`
  - `text1` and `text2` consist of only lowercase English letters.
## 🧠 Approaches Used

### 🔹 Solution: Recursion with Memoization
- Uses a recursive function to explore all possible subsequences between the two strings.
- Applies **top-down dynamic programming (memoization)** to cache intermediate results and avoid redundant computations.
- Time complexity is **O(n × m)**, where `n` and `m` are the lengths of the input strings.

#### 🔁 Recursive Function
```cpp
int LCS(const string &word1, const string &word2, int i, int j, vector<vector<int>> &dp) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (word1[i] == word2[j])
        return dp[i][j] = 1 + LCS(word1, word2, i - 1, j - 1, dp);
    return dp[i][j] = max(
        LCS(word1, word2, i - 1, j, dp),
        LCS(word1, word2, i, j - 1, dp)
    );
}

📚 Inspiration: Cette solution suit l'approche décrite dans *The Algorithm Design Manual* Page (707)

