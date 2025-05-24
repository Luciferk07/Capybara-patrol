# Royal Guard Formation

## Problem Statement

In the kingdom of Capy, the royal chess master is organizing a special guard formation on a standard 8×8 chessboard. Currently, there are already three pieces on the board: a **queen**, a **bishop**, and a **rook**, positioned such that none of them can capture any other.

The chess master wants to place exactly **two additional knights** on the board to complete the royal guard formation. However, there's a special rule: the two new knights must be able to **protect each other** (i.e., each knight must be able to capture the other in one move), but neither of the knights should be able to capture any of the existing three pieces, nor should any existing piece be able to capture either of the new knights.

Your task is to find the number of ways to place these two knights on the board following these conditions.

## Movement Rules Reminder

- **Queen**: Can move any number of squares horizontally, vertically, or diagonally
- **Bishop**: Can move any number of squares diagonally  
- **Rook**: Can move any number of squares horizontally or vertically
- **Knight**: Moves in an "L" shape: 2 squares in one direction and 1 square perpendicular to that

## Input

The first line contains the position of the queen on the board as a string of length 2 (e.g., "d4").
The second line contains the position of the bishop on the board in the same format.
The third line contains the position of the rook on the board in the same format.

Positions are given in standard chess notation: the first character is a lowercase letter from 'a' to 'h' (columns), and the second character is a digit from '1' to '8' (rows).

It is guaranteed that all three initial pieces are on different squares and none can capture another.

## Output

Print a single integer representing the number of ways to place two knights such that:
1. Both knights are on empty squares
2. The two knights can capture each other (are a knight's move apart)
3. Neither knight can capture any of the existing pieces
4. None of the existing pieces can capture either knight

## Examples

### Example 1
```
Input:
d4
f6
a1

Output:
12
```

### Example 2
```
Input:
h8
c3
e1

Output:
8
```

## Constraints

- The board is always 8×8
- All piece positions are valid and distinct
- It is guaranteed that the initial three pieces cannot capture each other
- Time limit: 2 seconds
- Memory limit: 256 megabytes

## Explanation

### Example 1:
With queen at d4, bishop at f6, and rook at a1, we need to find pairs of squares where:
- Two knights can be placed such that they attack each other
- Neither knight is attacked by queen (d4), bishop (f6), or rook (a1)
- Neither knight attacks any of the existing pieces

The answer is 12 such valid pairs of positions.
