#include <string>
#include <vector>
#include <cctype>
#include <iostream>
using namespace std;

string solution(string new_id)
{
    string answer = "";
    vector<char> s;

    // Step 1 소문자 치환
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] = new_id[i] + 'a' - 'A';
    }

    // Step 2 문자 제외
    for (int i = 0; i < new_id.size(); i++)
    {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            s.push_back(new_id[i]);
    }
    // Step 3 중복된 마침표 삭제
    for (int i = 1; i < s.size();)
    {
        if (s[i] == '.' && s[i - 1] == '.')
            s.erase(s.begin() + i);
        else
            i++;
    }
    // Step 4 문자열 처음과 마지막 위치의 마침표 삭제
    if (*s.begin() == '.')
        s.erase(s.begin());
    if (*(s.end() - 1) == '.')
        s.erase(s.end() - 1);
    // Step 5 new_id가 빈 문자열이라면, new_id에 "a"를 대입한다.
    if (s.size() == 0)
        s.push_back('a');
    // Step 6 문자열 길이 조절
    if (s.size() >= 16)
        s.resize(15);
    if (*(s.end() - 1) == '.')
        s.erase(s.end() - 1);
    // Step 7 문자열의 길이가 2자 이하라면, 마지막 문자를 길이가 3이 될 때까지 반복
    while (s.size() < 3)
        s.push_back(s[s.size() - 1]);

    for (int i = 0; i < s.size(); i++)
        answer.push_back(s[i]);
    return answer;
}
int main()
{
    string s;
    cin >> s;

    string result = solution(s);
    cout << result;
}