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

/*
1. 풀이 과정

1) 2가지 풀이 
- 보자마자 dp로 풀어야 한다는 생각과 동시에 완전탐색이 생각났습니다.
- 이전에 풀어 본 문제라 이전과 다른 풀이로 풀고 싶어서 dp를 선택했습니다.

2) 일을 하지 않음과 일을 함으로 구분하여 dp의 max를 구합니다.
- 일을 하지 않은 날은 반드시 이전까지의 max이므로 점화식을 구현하는데 용이했습니다.

2. 어려웠던 부분
- 오늘은 일을 하지 않음 / 일을 함으로 나눠서 2개의 dp로 고민했습니다. 그러다보니 예외가 발생함
- 하나의 dp로 합치고 역방향으로 점화식을 구현하기. 정방향만 생각했습니다.
*/

int arr[3][17];
int dp[17];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    int n,ttime,money;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> ttime >> money;
        arr[0][i] = ttime;
        arr[1][i] = money;
        arr[2][i] = ttime + i; //end
    }

    //마지막 날은 예외 케이스
    if(arr[2][n] > n+1)
    {
        dp[n] = 0;
    }   
    else
    {
        dp[n] = arr[1][n];
    }
    

    for(int i=n-1; i>=1; i--)
    {
        if(arr[2][i] > n+1)
        {
            dp[i] = dp[i+1];
        }
        else
        {
            dp[i] = max(dp[i+1] , dp[arr[2][i]]+arr[1][i]);
        }  
    }
    cout << dp[1];
   
	return 0;
}


