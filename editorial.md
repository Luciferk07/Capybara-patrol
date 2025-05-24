
# 🐾 Editorial: Capybara Friends

## 🧩 Problem Summary

You are given a 2D grid of size \( n \times m \), where each cell is either:
- `'C'` → a capybara,
- `'.'` → an empty cell.

You may place **exactly one** new capybara on any empty cell **if and only if** it has **at least one friend**.  
A *friend* is defined as **another capybara in the same row or column**.

Your goal is to count how many such **valid empty cells** exist.

---

## 🧠 Observations & Definitions

Let:
- Grid \( G \in \{\text{'.'}, \text{'C'}\}^{n \times m} \)
- Cell \( G[i][j] \): row \( i \in [1, n] \), column \( j \in [1, m] \)

Define:
- A row \( i \) is **active** if \( \exists \, j \text{ such that } G[i][j] = 'C' \)
- A column \( j \) is **active** if \( \exists \, i \text{ such that } G[i][j] = 'C' \)

A cell \( G[i][j] = '.' \) is a **valid placement** if:
- \( i \) is an active row **or** \( j \) is an active column.

---

## 🧮 Mathematical Formulation

Let \( A \) be the set of all valid placements:
\[
A = \{(i, j) \mid G[i][j] = '.' \text{ and } (R[i] = 1 \lor C[j] = 1)\}
\]
Where:
- \( R[i] = 1 \iff \exists \, j : G[i][j] = 'C' \)
- \( C[j] = 1 \iff \exists \, i : G[i][j] = 'C' \)

We want to compute:
\[
|A| = \text{Total number of such valid } (i, j)
\]

---

## ⚙️ Step-by-Step Algorithm

### Step 1: Mark Active Rows and Columns
- Traverse the entire grid.
- For each capybara cell \( G[i][j] = 'C' \), mark:
  - `hasRow[i] = true`
  - `hasCol[j] = true`

### Step 2: Count Valid Cells
- For each cell \( G[i][j] = '.' \), if `hasRow[i]` or `hasCol[j]` is `true`, increment answer.

---

## 💻 Pseudocode

```cpp
bool hasRow[n] = {false};
bool hasCol[m] = {false};

// Step 1: Preprocessing
for (int i = 0; i < n; ++i)
  for (int j = 0; j < m; ++j)
    if (grid[i][j] == 'C')
      hasRow[i] = hasCol[j] = true;

int count = 0;
// Step 2: Count valid placements
for (int i = 0; i < n; ++i)
  for (int j = 0; j < m; ++j)
    if (grid[i][j] == '.' && (hasRow[i] || hasCol[j]))
      count++;
```

---

## ⏱ Complexity Analysis

- **Time Complexity**:  
  - Step 1: \( O(n \cdot m) \)  
  - Step 2: \( O(n \cdot m) \)  
  ➤ **Total:** \( O(n \cdot m) \)

- **Space Complexity**:  
  - \( O(n + m) \) for the `hasRow` and `hasCol` arrays

---

## ✅ Correctness Proof

### ▶ Necessity
If a cell \( (i, j) \) is valid, then **some capybara** must exist in row \( i \) or column \( j \).  
So either `hasRow[i] = true` or `hasCol[j] = true`.  
**→ Necessary condition holds.**

### ▶ Sufficiency
If `hasRow[i] = true` or `hasCol[j] = true`, then a capybara is reachable by the new one via row or column.  
**→ Sufficient condition holds.**

Hence, the condition is **necessary and sufficient**. ✅

---

## 🧪 Example Walkthrough

### 🔸 Input:
```
3 3
C..
...
..C
```

Visual grid:

|   | 0 | 1 | 2 |
|---|---|---|---|
| 0 | C | . | . |
| 1 | . | . | . |
| 2 | . | . | C |

### 🔸 Step 1: Mark Active Rows and Columns
- Capybaras at (0,0) and (2,2)
- Active rows: `hasRow[0] = true`, `hasRow[2] = true`
- Active cols: `hasCol[0] = true`, `hasCol[2] = true`

### 🔸 Step 2: Check Each Cell

We now check each cell \( G[i][j] = '.' \) and whether it lies in any active row/column:

- Row 0:
  - (0,1): `hasRow[0] = true` → ✅
  - (0,2): `hasRow[0] = true` → ✅

- Row 1:
  - (1,0): `hasCol[0] = true` → ✅
  - (1,1): `hasRow[1] = false`, `hasCol[1] = false` → ❌
  - (1,2): `hasCol[2] = true` → ✅

- Row 2:
  - (2,0): `hasRow[2] = true` → ✅
  - (2,1): `hasRow[2] = true` → ✅

### 🔸 Total Valid Placements:  
Count of ✅: **6**

### 🔸 Final Answer: `6`

---

## 🧊 Edge Cases

- All empty grid: answer is `0` (no active rows/cols)
- Full capybara grid: answer is `0` (no empty cells)
- Only one capybara: row and column it’s in are active — other empty cells may be valid
- Only one row or one column: answer can still be valid if there's at least one 'C'

---

## 🪄 Tips & Tricks

- Don't re-scan rows/columns for each query; use preprocessed flags (`hasRow`/`hasCol`).
- This is a classic example of **fast filtering using auxiliary arrays**.

---

## 🧠 Final Thoughts

This problem is a nice exercise in:
- Translating logical conditions to simple boolean tracking
- Using preprocessing for fast decision-making
- Verifying conditions with both necessity and sufficiency logic

It also introduces foundational ideas in **grid manipulation**, **friendship networks**, and **2D condition checks** — useful patterns in competitive programming.

---

## 🔚 The End
