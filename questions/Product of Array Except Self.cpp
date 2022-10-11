class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> array;
       int prefix = 1, posfix =1 ;
        
        for(int cont = 0;cont<nums.size();cont++){
            array.push_back(prefix);
            prefix*= nums[cont];
        }
            
        for(int cont2 = nums.size()-1; cont2>= 0;cont2--){
            array[cont2] *= posfix;
            posfix *= nums[cont2];
        }
        
        return array;
    }
};