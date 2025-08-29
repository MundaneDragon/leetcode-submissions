class Solution(object):
    def flowerGame(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        n_even = n // 2
        n_odd = (n+1) // 2
        m_even = m // 2
        m_odd = (m+1) // 2
        return n_even * m_odd + n_odd * m_even
        