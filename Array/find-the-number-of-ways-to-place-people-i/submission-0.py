class Solution(object):
    def numberOfPairs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        points.sort(key=lambda point:(-point[1],point[0]))
        res = 0
        for index1,p1 in enumerate(points):
            maxX = float('inf')
            for index2,p2 in enumerate(points[index1+1:]):
                x1,y1 = p1
                x2,y2 = p2
                # print(p1,p2,maxX,'|',res)
                if x1 <= x2:
                    # print('> p2 is right or on side of p1')
                    if x2 < maxX:
                        res += 1
                    #     print('> p2 is left side of maxX encountered : counting',res)
                    # else:
                    #     print('> p2 is right or on side of maxX encountered')
                    maxX = min(x2,maxX)
                else:
                    # print('> p2 is left side of p1')
                    continue
        return res
        