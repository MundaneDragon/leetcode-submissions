class Solution(object):
    def sortMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(grid)

        def sort_diag(x,y,sort=True):
            start_x = x
            start_y = y
            temp = []
            for i in range(min(n-x,n-y)):
                temp.append(grid[start_x][start_y])
                start_x += 1
                start_y += 1
            
            temp.sort(reverse=sort)
            start_x = x
            start_y = y
            for i in range(min(n-x,n-y)):
                grid[start_x][start_y] = temp[i]
                start_x += 1
                start_y += 1
        # Bottom
        for i in range(n):
            sort_diag(i,0)

        for i in range(1,n):
            sort_diag(0,i,False)
        
        return grid
            
