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

2. 어려웠던 부분

*/

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    int n;
    cin >> n;
    
    int answer = 99999999;
    int cnt;
    for(int i=1; i<=n/5; i++)
    {
        cnt = 0;
        cnt += i;
        if((n-(5*i))%2 == 1)
        {
            continue;
        }
        cnt += (n-(5*i))/2;
        answer = min(answer , cnt);
    }
    if(n%2 == 0)
    {
        answer = min(answer , n/2);
    }
    if(answer == 99999999)
    {
        cout << -1;
        return 0;
    }
    cout << answer;
	return 0;
}


