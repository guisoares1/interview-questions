class Solution {
int value =0;
public:
    int findMin(vector<int>& nums) {
        binarySearch(nums, 0, nums.size()-1);
        return value;
    }
    
    void binarySearch(vector<int>& nums, int low, int high){
        if (low > high)
             return;
        // base case
        if (low == high){
            value = nums[high];
             return ;
        }
    
        
         int midInd = (low + high) / 2; 
           /// case of 2 elements betwen low and high
           if (nums[midInd] < nums[midInd+1] && low==high-1){
               value = nums[midInd];
               return ;
           }
          // case of more than 2 elements betwen low and high, verity two position, left and right
            else if (low!=high-1 && nums[midInd] < nums[midInd+1] && nums[midInd] < nums[midInd-1]){
               value = nums[midInd];
               return ;
           }
           // the element is on the right side if the element on midle index is bigger than the first element on right or the element on high index is less than the element on low index and element on high index is less than the element on midle index 
           else if (nums[high]<nums[midInd] || (nums[high]<nums[low]&&nums[high]<nums[midInd]))       
               return binarySearch(nums,  midInd + 1, high);

           else                      
               return binarySearch(nums,  low, midInd - 1) ;

        }
};