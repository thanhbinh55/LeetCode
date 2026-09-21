class Solution(object):
    def permute(self, nums):
        res = []
        path = []
        visited = [False] * len(nums)

        def backtrack():
            # base case
            if len(path) == len(nums):
                res.append(path[:])
                return
            
            # duyet cac kha nang con lai
            for i in range(len(nums)):
                if visited[i]:
                    continue
                
                # chon
                visited[i] = True
                path.append(nums[i])

                # kham pha 
                backtrack()

                # bo chon
                path.pop()
                visited[i] = False
                
        backtrack()
        return res
        