# Time Complexity: O(n log n)
# Space Complexity: O(n)

import heapq

class Solution:
    def minGroups(self, intervals: list[list[int]]) -> int:
        # Sort intervals based on start time
        # Sort the intervals list based on the start time of each interval
        # x[0] refers to the first element of each sublist, which is the start time
        # The lambda function creates a key for sorting, where each interval is sorted by its start time
        # This ensures that intervals are processed in order of their start times
        intervals.sort(key=lambda x: x[0])
        print(intervals)
        
        # Initialize a min-heap to store end times of groups
        groups = []
        
        for start, end in intervals:
            # This condition checks two things:
            # 1. If there are any existing groups (groups is not empty)
            # 2. If the earliest end time (groups[0]) is less than the current interval's start time
            # If both conditions are true, it means we can reuse an existing group
            if groups and groups[0] < start:
                # If the current interval doesn't overlap with the earliest ending group,
                # update that group's end time
                heapq.heapreplace(groups, end)
            else:
                # Otherwise, create a new group
                heapq.heappush(groups, end)
        
        # The number of elements in the heap is the minimum number of groups needed
        print(groups)
        return len(groups)

# Test case
intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
solution = Solution()
result = solution.minGroups(intervals)
print(f"Minimum number of groups for {intervals}: {result}")