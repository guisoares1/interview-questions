// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         unordered_set<int> appers;
         
        for(int data: nums){
            if(appers.find(data)!=appers.end())
                return true;
            
            appers.insert(data);
        }
        
        return false;
    }
};