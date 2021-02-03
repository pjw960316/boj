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
int dp[10000002];
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin >> n;
    
	dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++)
    {
        dp[i] = (dp[i-2] + dp[i-1])%10;
    }
    cout << dp[n];
	return 0;
}


