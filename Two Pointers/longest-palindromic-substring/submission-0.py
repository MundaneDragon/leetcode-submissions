class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        
        maxLen = 0
        result = ""
        for i in range(len(s)):
            # Odd
            l,r = i,i
            while l > -1 and r < len(s) and s[l] == s[r]:
                if len(s[l:r+1]) > maxLen:
                    result = s[l:r+1]
                    maxLen = len(s[l:r+1])
                l = l - 1
                r = r + 1

            # Even
            l,r = i, i+1
            while  l > -1 and r < len(s) and s[l] == s[r]:
                if len(s[l:r+1]) > maxLen:
                    result = s[l:r+1]
                    maxLen = len(s[l:r+1])
                l = l - 1
                r = r + 1



        return result