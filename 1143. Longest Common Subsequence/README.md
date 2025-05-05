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
## 🧠 Approches utilisées

### 🔹 Solution : Récursion avec Mémoization
- Utilise une fonction récursive pour explorer toutes les possibilités de sous-séquences.
- Applique la **programmation dynamique top-down** (mémoization) pour éviter les recalculs.
- La complexité est **O(n * m)**, avec `n` et `m` les tailles des deux chaînes.

📚 Inspiration: Cette solution suit l'approche décrite dans *The Algorithm Design Manual*, chapitre sur la programmation dynamique (chapitre 8), notamment la section sur l’alignement de séquences. Page (707)

