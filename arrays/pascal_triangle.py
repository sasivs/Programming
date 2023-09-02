class Solution:
    def generate(self, numRows: int):
        rows = []
        if numRows>=1:
            rows.append([1])
        if numRows>=2:
            rows.append([1,1])
        for i in range(3, numRows+1):
            rows.append([1])
            for j in range(1, i-1):
                rows[i-1].append(rows[i-2][j]+rows[i-2][j-1])
            rows[i-1].append(1)
        return rows