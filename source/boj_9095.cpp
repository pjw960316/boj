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

int dp[12];
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    int tc,num;
    cin >> tc;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4; i<=11; i++)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    
    for(int i=0; i<tc; i++)
    {
        cin >> num;
        cout << dp[num] << "\n";
    }
	return 0;
}


