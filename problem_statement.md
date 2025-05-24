# Capybara Friends

## Problem Statement

In a small zoo, there are capybaras placed on a rectangular grid of size **n × m**. Some cells already have capybaras, and you want to place exactly **one more capybara** on an empty cell.

However, capybaras are social animals and follow a simple friendship rule:
- **Two capybaras are friends if they are in the same row OR the same column**
- **A new capybara must have at least one friend among the existing capybaras**

Your task is to count how many empty cells can accommodate a new capybara such that it will have at least one friend.

## Input

The first line contains two integers **n** and **m** (1 ≤ n, m ≤ 100) — the dimensions of the grid.

The next **n** lines contain **m** characters each, where:
- '.' represents an empty cell
- 'C' represents a cell with a capybara

It is guaranteed that there is at least one capybara initially and at least one empty cell.

## Output

Print a single integer — the number of empty cells where you can place a new capybara such that it will have at least one friend.

## Examples

### Example 1
**Input:**
```
3 3
C..
...
..C
```

**Output:**
```
6
```

### Example 2
**Input:**
```
2 4
C...
....
```

**Output:**
```
4
```

## Explanation

In Example 1:
- There are capybaras at (1,1) and (3,3)
- A new capybara can be placed at:
  - (1,2), (1,3) - same row as capybara at (1,1)
  - (2,1) - same column as capybara at (1,1)
  - (2,3) - same column as capybara at (3,3)
  - (3,1), (3,2) - same row as capybara at (3,3)
- Total: 6 valid positions

In Example 2:
- There is a capybara at (1,1)
- A new capybara can be placed at:
  - (1,2), (1,3), (1,4) - same row as existing capybara
  - (2,1) - same column as existing capybara
- Total: 4 valid positions (not 6 as initially stated)

## Constraints

- 1 ≤ n, m ≤ 1000
- At least one capybara exists initially
- At least one empty cell exists
- Grid contains only '.' and 'C' characters
