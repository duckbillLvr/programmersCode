#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string, string> User;
    stringstream ss;
    for(auto re : record){
        ss.str(re);
        string ts, id, nickname;
        ss >> ts >> id >> nickname;
        ss.clear();
        
        if(ts!="Leave")
            User[id] = nickname;
    }
    for(auto re:record){
        ss.str(re);
        string ts, id;
        ss >> ts >> id;
        ss.clear();
        
        string order;
        if(ts=="Enter")
            order = "님이 들어왔습니다.";
        else if(ts=="Leave")
            order = "님이 나갔습니다.";
        else continue;
        
        order = User[id] + order;
        answer.push_back(order);
    }
    return answer;
}