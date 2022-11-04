// Valores que somados o resultado é o valor enviado por parâmetro target.

class Solution {

public:

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> listNumsTry;
        vector<int> vect;

        for(int data:nums){
            // when you find a data number equal to a number on hash, you get the correct number. Example: data = 2, complement on hash 2 (6 - 8), 6 + 2 = 8.		
            if(listNumsTry.find(data)!=listNumsTry.end()){
                vect.push_back(target - data);
                vect.push_back(data);

                return vect;

            }
            // complement of this number less the target, for exemple, Taget = 8, data = 2, complement is 6		 
            listNumsTry.insert(target - data);

        }
  
        return vect;
    }

};