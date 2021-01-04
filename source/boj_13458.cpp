#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int person[1000001];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	int room,person_cnt,major,minor;
    long long answer=0;
    cin >> room;
    for(int i=0; i<room; i++)
    {
        cin >> person_cnt;
        person[i] = person_cnt;
    }
    cin >> major >> minor;

    for(int i=0; i<room; i++)
    {
        answer += 1;

        //오류 : person[i] - major가 음수인 경우 에러가 발생합니다. 
        if(person[i]-major<=0) //예외 처리
        {
            continue;
        } 
        if((person[i]-major) % minor == 0)
        {
            answer += (person[i]-major) / minor;
        }
        else 
        {
            answer += (person[i]-major) / minor + 1;
        }  
    }

    cout << answer;
	return 0;
}


