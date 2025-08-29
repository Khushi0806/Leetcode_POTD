class Solution(object):
    def flowerGame(self, n, m):
        c=0
        for i in range(1,n+1): 
            if i%2==0:
                c+=(m+1)//2 
                
            else:
                c+=m//2
                
        return c 
        
