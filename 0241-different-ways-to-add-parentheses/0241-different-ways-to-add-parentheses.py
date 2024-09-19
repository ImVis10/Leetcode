# NEETCODE
class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        ops = {
            "+": lambda x, y: x + y,
            "-": lambda x, y: x - y,
            "*": lambda x, y: x * y
        }
        
        def backtrack(left, right):
            res = []
            for i in range(left, right + 1):
                op = expression[i]
                if op in ops:
                    num1 = backtrack(left, i - 1)
                    num2 = backtrack(i + 1, right)
                    for n1 in num1:
                        for n2 in num2:
                            res.append(ops[op](n1, n2))
            if res == []:
                res.append(int(expression[left:right + 1]))
            return res
        
        return backtrack(0, len(expression) - 1)