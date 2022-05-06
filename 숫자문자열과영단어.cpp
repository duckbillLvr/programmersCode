#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(string s)
{
    int answer = 0;
    queue<char> q;
    string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            q.push(s[i]);
        else
        {
            for (int j = 0; j < sizeof num / sizeof num[0]; j++)
            {
                if (s.compare(i, num[j].size(), num[j]) == 0)
                {
                    q.push(j + '0');
                    break;
                }
            }
        }
    }

    while (!q.empty())
    {
        answer += q.front() - '0';
        q.pop();
        if (!q.empty())
            answer *= 10;
    }
    return answer;
}

int main()
{
    string s;
    cin >> s;

    int answer = solution(s);
    cout << answer;

    /*
    ex)
    s	result
    "one4seveneight"	1478
    "23four5six7"	234567
    "2three45sixseven"	234567
    "123"	123
    */
}