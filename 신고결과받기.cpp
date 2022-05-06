#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    map<string, int> idIdx;
    for(int i=0; i<id_list.size(); i++)
        idIdx[id_list[i]] = i;
    for(auto id : idIdx)
        cout << "ID Map: " << id.first << " " << id.second << '\n';
    
    
    map<string, set<string>> reportTable;
    stringstream ss;
    for(auto rep:report){
        ss.str(rep);
        string s, e;
        ss >> s >> e;
        reportTable[e].insert(s);
        ss.clear();
    }
    for(auto rep : reportTable)
    {
        cout << "report " << rep.first << " from ";
        for(auto se : rep.second)
            cout << se << ", ";
        cout << '\n';
    }
    for(auto rep:reportTable){
        if(rep.second.size() >= k)
            for(auto se : rep.second){
                int idx = idIdx[se];
                answer[idx]++;
            }
    }
    return answer;
}