class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        if len(nums1) > len(nums2):
                    nums1, nums2 = nums2, nums1
        
        m, n = len(nums1), len(nums2)
        left, right = 0, m
        
        while left <= right:
            # Partition points
            i = (left + right) // 2  # Partition in nums1
            j = (m + n + 1) // 2 - i  # Corresponding partition in nums2
            
            # Get left and right elements for both arrays
            left1 = nums1[i-1] if i > 0 else float('-inf')
            right1 = nums1[i] if i < m else float('inf')
            left2 = nums2[j-1] if j > 0 else float('-inf')
            right2 = nums2[j] if j < n else float('inf')
            
            # Check if this is the correct partition
            if left1 <= right2 and left2 <= right1:
                # Found the correct partition
                if (m + n) % 2 == 0:
                    # Even total length: average of max of left and min of right
                    return (max(left1, left2) + min(right1, right2)) / 2.0
                else:
                    # Odd total length: max of left side
                    return max(left1, left2)
            elif left1 > right2:
                # Too many elements in nums1's left partition, move left
                right = i - 1
            else:
                # Too few elements in nums1's left partition, move right
                left = i + 1
        
        # If binary search fails (should not happen given constraints), handle edge cases
        if m == 0 and n == 0:
            return 0.0
        if m == 0:
            if n % 2 == 0:
                return (nums2[n//2-1] + nums2[n//2]) / 2.0
            else:
                return nums2[n//2]
        if n == 0:
            if m % 2 == 0:
                return (nums1[m//2-1] + nums1[m//2]) / 2.0
            else:
                return nums1[m//2]

        