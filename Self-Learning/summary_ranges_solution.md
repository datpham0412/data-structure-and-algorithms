# Summary Ranges

## Problem Description
Given a sorted unique integer array `nums`, return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of `nums` is covered by exactly one of the ranges, and there is no integer `x` such that `x` is in one of the ranges but not in `nums`.

Each range `[a,b]` in the list should be output as:
- `"a->b"` if `a != b`
- `"a"` if `a == b`

## Approach
This solution iterates through the input array once, keeping track of the start and end of each range. It uses a helper function to format the range as a string. The algorithm adds a sentinel value (None) at the end of the input list to simplify handling the last range. For each number, it checks if it's consecutive with the previous number. If not, it ends the current range and starts a new one.

## Complexity
- Time complexity: O(n), where n is the number of elements in the input array. We iterate through the array once.
- Space complexity: O(n) in the worst case, where each number forms its own range. The output list stores these ranges.

## Code