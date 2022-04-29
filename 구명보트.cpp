#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());

    int head = 0, tail = people.size()-1;

    int answer = 0;
    while(head <= tail)
    {
        if(people[head] + people[tail] <= limit)
        {
            head++;
            tail--;
        }
        else
        {
            tail--;
        }
        answer++;
    }
    return answer;
}