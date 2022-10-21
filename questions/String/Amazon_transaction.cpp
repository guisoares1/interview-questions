vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
}

void addElemList(string key){
    auto it = user_transaction.find(key);
    if(it != user_transaction.end()){
        it->second += 1;
    }
    else
    {
        user_transaction.insert(make_pair(key,1));
    }
}

vector<string> processLogs(vector<string> logs, int threshold) {

    vector<string> arrayRet;
    vector<string> logSplited;

    for(string log: logs){
       logSplited =  split(log, ' ');
       if (logSplited[0] == logSplited[1])
            addElemList(logSplited[0]);
        else {
            addElemList(logSplited[0]);
            addElemList(logSplited[1]);
        }
    }
    
    for(auto s: user_transaction){
        if(s.second >= threshold){
            arrayRet.push_back(s.first);
        }
    }
    sort(arrayRet.begin(), arrayRet.end(), [] (const string& s1, const string& s2) {
                return s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2);
        });
    return arrayRet;
}
