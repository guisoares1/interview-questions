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
    for(int cont = 0; cont<s.size(); cont++){
        if(s[cont]=='|')
            compartmentIndex.push_back(cont);
    }
    // [2 , 5 , 7, 10]
    // (5, 7) -> 1, 2
    for(int cont = 0; cont<startIndices.size(); cont++){
        int start = lower_bound(compartmentIndex.begin(), compartmentIndex.end(), startIndices[cont]-1) - compartmentIndex.begin();
        int end   = upper_bound(compartmentIndex.begin(), compartmentIndex.end(), endIndices[cont]-1) - compartmentIndex.begin() - 1;
        
        if(start<end)
        {
            // (end-start) -> tratment of the case than dont have any items betwen '|'
            int items = (compartmentIndex[end] - compartmentIndex[start]) - (end-start);
            ret.push_back(items);
        }
        else
            ret.push_back(0);
    }
    return ret;
}

