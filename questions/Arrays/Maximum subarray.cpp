class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int max=INT_MIN;

        for(int num: nums){
            currentSum+=num;

            if(currentSum>max)
                max = currentSum;
            
            if(currentSum<0){
               currentSum = 0; 
            }
        }
        return max;    
    }
};