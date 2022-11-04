#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'numberOfItems' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY startIndices
 *  3. INTEGER_ARRAY endIndices
 */

vector<int> numberOfItems(string s, vector<int> startIndices, vector<int> endIndices) {
    vector<int> compartmentIndex, ret;
    // set the positions of containers
    for(int cont = 0; cont<s.size(); cont++){
        if(s[cont]=='|')
            compartmentIndex.push_back(cont);
    }

    for(int cont = 0; cont<startIndices.size(); cont++){
        // look for the first index in compartmentIndex that is less than or equal to startIndices. I took -1 because the index of array start with 1
        int start = lower_bound(compartmentIndex.begin(), compartmentIndex.end(), startIndices[cont]-1) - compartmentIndex.begin();
        // look for the first index in compartmentIndex that is more than or equal to endIndices. I took -1 because the index of array start with 1
        int end   = upper_bound(compartmentIndex.begin(), compartmentIndex.end(), endIndices[cont]-1) - compartmentIndex.begin() - 1;
        
        if(start<end)
        {
            // (end-start) -> tratment of the case than dont have any items betwen '|'
            int items = (compartmentIndex[end] - compartmentIndex[start]) - (end-start);
            ret.push_back(items);

            // exemplo 
            // array of compartmentIndex = [2,5]
            // startIndices = [2]
            // endIndices = [5]
            // start = 0
            // end = 1
            // intems = 5 - 2 - (1-0) -> 2
        }
        else
            ret.push_back(0);
    }
    return ret;
}

