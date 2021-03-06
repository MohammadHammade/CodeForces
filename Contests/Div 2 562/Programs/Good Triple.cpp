#include <iostream>
#include <string>

using namespace std;

int is_good(string &S)
{
    for(int x = 0; x < S.size(); x++)
    {
        for(int k = 1; x + 2*k < S.size(); k++)
        {
            if(S[x] == S[x + k] && S[x + k] == S[x + 2*k])
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    string S;
    cin >> S;

    long long answer = 0;
    for(int left = 0; left < S.size(); left++)
    {
        for(int length = 2; length <= 9 && left + length - 1 < S.size(); length++)
        {
            string substring = S.substr(left, length);

            if(is_good(substring))
            {
                int right = left + length - 1;

                answer += (S.size() - 1) - (right - 1);

                break;
            }
        }
    }

    cout << answer;
    return 0;
}
