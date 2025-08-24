class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        num_zero = 0
        end_window = 0
        prev_zero_index = -1
        start = 0
        longest = 0
        for index, value in enumerate(nums):
            if value == 0:
                if num_zero < 1:
                    prev_zero_index = index
                num_zero += 1
            end_window += 1

            if num_zero > 1:
                longest = max(longest, end_window-1-start-1)
                num_zero -= 1
                start = prev_zero_index+1
                prev_zero_index = index 
    
        longest = max(longest, end_window-start-1)

        return longest



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

        