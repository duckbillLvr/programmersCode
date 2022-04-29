#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int solution(vector<int> priorities, int location) {
    queue<P> q;
    for(int i=0; i<priorities.size(); i++)
        q.push({priorities[i], i});

    sort(priorities.begin(), priorities.end(), greater<>());

    int cnt = 0;
    while(!q.empty())
    {
        P tmp = q.front();
        if(priorities[cnt]==tmp.first)
        {
            cnt++;
            q.pop();

            if(tmp.second==location)
                return cnt;
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
}
