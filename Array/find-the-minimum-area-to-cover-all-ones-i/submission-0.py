class Solution(object):
    def minimumArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        min_row, max_row = 5000, -1
        min_col, max_col = 5000, -1

        for row_index, row in enumerate(grid):
            for col_index, col in enumerate(row):
                if col == 1:
                    if min_col > col_index:
                        min_col = col_index
                    if max_col < col_index:
                        max_col = col_index
                    if min_row > row_index:
                        min_row = row_index
                    if max_row < row_index:
                        max_row = row_index


        row_length = 0
        if min_row == max_row:
            row_length = 1
        else:
            row_length = (1 + max_row - min_row)


        col_length = 0
        if min_col == max_col:
            col_length = 1
        else:
            col_length = (1 + max_col - min_col)

        return row_length * col_length