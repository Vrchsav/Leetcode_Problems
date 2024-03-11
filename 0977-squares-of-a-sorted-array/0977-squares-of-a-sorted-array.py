class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            a=nums[i]**2
            nums[i]=a
        nums.sort()
        return(nums)