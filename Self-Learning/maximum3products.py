
import sys
class Solution:
    def maximumProduct(self, nums: list[int]) -> int:
        result = -sys.maxsize - 1
        for i in range(len(nums)):
            for j in range(1, len(nums)):
                for k in range(2, len(nums)):
                    result = max(result, nums[i]*nums[j]*nums[k])
        return result

solution = Solution()
print(solution.maximumProduct([1,2,3,4])) # output: 24