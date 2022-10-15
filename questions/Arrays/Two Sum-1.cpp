// Two Sum , leetcode

class Solution {

public:

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vect, resul;
        int cont = 0;


        for(int data:nums){
            auto search =  find(vect.begin(), vect.end(), data);
   
            if(search!=vect.end()){
                resul.push_back(search - vect.begin());
                resul.push_back(cont);
                return resul;

            }

            vect.push_back(target - data);
            cont++;
        }
        return vect;
    }

};