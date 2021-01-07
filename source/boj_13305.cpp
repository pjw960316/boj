#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
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

/*
1. 풀이 과정
- 가장 저렴한 주유소에서 기름을 넣고 종료시점까지 가는 행위를 그리디하게 반복합니다.
- 저렴한 주요소 순으로 정렬하고 index를 저장하는 vector를 사용합니다.

2. 어려웠던 부분
- 두 개의 vector를 처음에 int형으로 하였습니다. 
- 'cost += (i.first * dis[j]);'에서 cost가 long long 임에도 불구하고 
우측의 수식이 int*int이므로 cost에는 오버플로우가 발생된 값이 더해집니다.
*/

vector<long long> dis;
vector<pair<long long , long long>> v;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

    long long n, num;
    cin >> n;
    for(int i=0; i<n-1; i++)
    {
        cin >> num;
        dis.push_back(num);
    }
    for(long long i=0; i<n; i++)
    {
        cin >> num;
        v.push_back({num,i});
    }
	sort(v.begin() , v.end());
    
    long long cost = 0;
    long long cur_city = n-1;
    for(auto i : v)
    {        
        if(i.second == n-1) // 마지막 도시
        {
            continue;
        }
        if(i.second < cur_city)
        {
            for(int j=i.second; j<cur_city; j++)
            {
                cost += (i.first * dis[j]); //ERROR : 자료형
            }
            if(i.second == 0) //첫 도시
            {
                cout << cost;
                return 0;
            }
            cur_city = i.second;
        }
    }
	return 0;
}


