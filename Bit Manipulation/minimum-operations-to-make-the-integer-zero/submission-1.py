class Solution(object):
    def makeTheIntegerZero(self, num1, num2):
        """
        :type num1: int
        :type num2: int
        :rtype: int
        """
        def count_bit(num):
            cnt = 0
            while num > 0:
                if num % 2 == 1:
                    cnt += 1
                num //= 2
            return cnt
        k = 1
        while True:
            x = num1 - k * num2
            if x < k:
                return -1
            if k >= count_bit(x):
                return k
            k += 1        