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

int arr[2][100002];
int dp[2][100002];
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    int tc,col;
    cin >> tc;
    for(int ii=0; ii<tc; ii++)
    {
        cin >> col;
        memset(arr , 0 ,sizeof(arr));
        memset(dp , 0 ,sizeof(dp));
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<col; j++)
            {
                cin >> arr[i][j];
            }
        }
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = arr[1][0] + arr[0][1];
        dp[1][1] = arr[0][0] + arr[1][1];
        if(col == 1)
        {
            cout << max(dp[0][1] , dp[1][1]) << "\n";
            continue;
        }
        for(int i=2; i<col; i++)
        {
            dp[0][i] = max(dp[1][i-1] , dp[1][i-2]) + arr[0][i];
            dp[1][i] = max(dp[0][i-1] , dp[0][i-2])+ arr[1][i];
        }
        
        cout << max(dp[0][col-1] , dp[1][col-1]) << "\n";
    }
	return 0;
}


