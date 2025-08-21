class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        if len(s) == 1:
            return 1

        prev_char = set()
        max = 0
        counter = 0
        for index, c in enumerate(s):
            for char in s[index:]:
                if char in prev_char:
                    if counter > max:
                        print(max)
                        max = counter
                        print(max)
                
                    break
                counter += 1
                prev_char.add(char)

            if counter > max:
                return counter

            prev_char = set()
            counter = 0

        return max

        