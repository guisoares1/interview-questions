class Solution {
public:
 vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> A, res;
     
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == '|')
                A.push_back(i);
     
        for (int q = 0; q < queries.size(); ++q) {
            int initialPosition = lower_bound(A.begin(), A.end(), queries[q][0]) - A.begin();
            int endPosition = upper_bound(A.begin(), A.end(), queries[q][1]) - A.begin() - 1;
            
            if(initialPosition < endPosition)
            {
                int numPlates = (A[endPosition] - A[initialPosition]) - (endPosition - initialPosition);
                res.push_back(numPlates);
            }
                
            else
                res.push_back(0);
        }
        return res;
    }
};