class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        res = []
        path = []
        visited = [False] * len(nums)

        def backtrack():
            if len(path) == len(nums):
                res.append(path[:])
                return

            for i in range(len(nums)):
                # bo qua neu phan tu o vi tri i da duoc dung trong nhanh hien tai
                if visited[i]:
                    continue
                
                # tia nhanh trung lap
                if i > 0 and nums[i] == nums[i - 1] and not visited[i - 1]:
                    continue

                # chon
                visited[i] = True
                path.append(nums[i])

                # kham pha 
                backtrack()

                # backtrack
                path.pop()
                visited[i] = False

        backtrack()
        return res        