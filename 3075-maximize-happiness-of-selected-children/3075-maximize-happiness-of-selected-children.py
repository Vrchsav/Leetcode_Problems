class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(reverse = True) 
        res , i = 0 , 0

        while k and happiness[i] - i > 0 : 
            res += happiness[i] - i 
            k , i = k - 1 , i + 1 
            
        return res 