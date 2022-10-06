// quais valores que somados dao o valor enviado por parametro?

class Solution {

public:

    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_set<int> listNumsTry;

        vector<int> vect;

        for(int data:nums){

            if(listNumsTry.find(data)!=listNumsTry.end()){

                

                vect.push_back(target - data);

                vect.push_back(data);

                return vect;

            }

            listNumsTry.insert(target - data);

        }

        

        return vect;

    }

};