class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSubarray = 0, productToRight = 1, productToLeft = 1, max = INT_MIN, localMax = 0 ;
        int cont2 = nums.size()>1? nums.size()-1 : 0;
        
        //  -> [1, 3, 4, -6, 1] <-
        for(int cont=0;cont<nums.size();cont++){
            productToRight *= nums[cont];
            productToLeft *= nums[cont2];
            localMax = productToRight > productToLeft? productToRight : productToLeft;
            
            if(localMax> max)
                max = localMax;
            
            if(productToRight == 0)
                productToRight = 1;
            
            if(productToLeft == 0)
                productToLeft =1;
                
            cont2--;
        }
        
        return max;       
    
    }
};