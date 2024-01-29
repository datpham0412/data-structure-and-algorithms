class Solution:
    def dailyTemperatures(self, temperatures):
        res = [0] * len(temperatures)
        stack = []
        print(res)
        print(stack)
        for i, t in enumerate(temperatures):
            while stack and t > stack[-1][0]:
                print(stack)
                stackT, stackInd = stack.pop()
                res[stackInd] = i - stackInd
            stack.append((t, i))
        return res

def main():
    solution = Solution()

    # Example 1
    temperatures1 = [73,74,75,71,69,72,76,73]
    result1 = solution.dailyTemperatures(temperatures1)
    print("Example 1 Output:", result1)  # Expected output: [1,1,4,2,1,1,0,0]

if __name__ == "__main__":
    main()
