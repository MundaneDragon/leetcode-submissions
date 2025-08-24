class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_num = 0
        for index, val in enumerate(nums):
            if val == 0 and (index > 0) and (index < (len(nums)-1)) and nums[index-1] == 1 and nums[index+1] == 1:
                temp = list(nums)
                temp.pop(index)
                max_num = max(self.longest1s(temp), max_num)
            elif index == 0 or  index == (len(nums)-1):
                temp = list(nums)
                temp.pop(index)
                max_num = max(self.longest1s(temp), max_num)

        for index, val in enumerate(nums):
            if val == 1:
                temp = list(nums)
                temp.pop(index)
                max_num = max(self.longest1s(temp), max_num)
                break
                
        return max_num

    def longest1s(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_num = 0
        counter = 0
        for val in nums:
            if val == 1:
                counter+= 1
            else:
                if counter > max_num:
                    max_num = counter
                counter = 0
        
        if counter > max_num:
            max_num = counter
        
        return max_num

        