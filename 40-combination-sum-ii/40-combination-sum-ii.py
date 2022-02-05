class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res, curr = [], []
        
        def backtrack(curr, pos, remain):
            
            if remain == 0:
                return res.append(curr[:])
            
            prev = -1
            for i in range(pos, len(candidates)):
                if prev == candidates[i]:
                    continue
                elif remain - candidates[i] < 0:
                    break
                curr.append(candidates[i])
                backtrack(curr, i + 1, remain - candidates[i])
                curr.pop()
                prev = candidates[i]
                
        backtrack(curr, 0, target)
        return res