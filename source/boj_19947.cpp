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
	
    double h;
    int y;
    cin >> h >> y;
    dp[0] = h;
    dp[1] = floor(h*1.05);
    dp[2] = floor(dp[1]*1.05);
    dp[3] = max(floor(dp[2]*1.05) , floor(h*1.2));
    dp[4] = max(floor(dp[3]*1.05) , floor(dp[1]*1.2));
    for(int i=5; i<=y; i++)
    {
        dp[i] = max(max(floor(dp[i-1]*1.05) , floor(dp[i-3]*1.2)) , floor(dp[i-5]*1.35));
    }
    cout << dp[y];
	return 0;
}


