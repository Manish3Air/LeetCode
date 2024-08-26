class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        k = len(nums)
        for i in range(0,k):
            ans = ans ^ nums[i]
        return ans