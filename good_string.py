
from typing import List

class Solution:
    
    def noOfPairs(self, box: List[str]) -> int:
        # Write your code here
        maps = [[0]*26 for _ in range(len(box))]
        for i in range(len(box)):
            for j in box[i]:
                maps[i][ord(j)-97] += 1
        count=0
        for i in range(len(box)):
            for j in range(i+1, len(box)):
                odd = 0
                for k in range(26):
                    if ((maps[i][k]+maps[j][k])%2) == 1:
                        if odd == 1:
                            odd+=1
                            break
                        else: 
                            odd += 1
                if odd<=1:
                    count+=1
        return count

#{ 
 # Driver Code Starts

for _ in range(int(input())):
# f = open("fileinput.txt", 'r')
# print(f)
# lines = f.readlines()
# print(lines)
    n = int(input())
    box = [input() for _ in range(n)]
    ob = Solution()
    res = ob.noOfPairs(box)
    print(res)
    
# } Driver Code Ends