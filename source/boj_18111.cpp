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

1) 예전에는 이런 문제를 보면 어떤 로직으로 몇 개의 경우를 찾아서 비교해야 하지 였다면
지금은 모든 경우를 얼마만의 시간안에 검사할 수 있지? 부터 사고가 시작됩니다.
2) 모든 경우가 500x500의 공간에서 높이가 0 ~ 256이므로 시간복잡도는 충분합니다.
3) 모든 경우를 구한 후 최소 노동 시간을 찾고 같은 경우에는 높이를 갱신합니다.

2. 어려웠던 부분
1) 반복문과 일반 조건문을 섞어 쓸 때 조건문도 반복문 처럼 생각하고 실수 합니다.
2) 이제 시간복잡도를 잘 고려하지만 아직도 두려운 경우가 존재합니다. 이번에는 여유로워서 통과했지만
블록을 추가하는 과정에서 남은 블록보다 많은 경우를 찾으면 break 가능

*/
long long arr[502][502];
long long min_labor_time = 99999999999; 
long long max_ht;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    long long n,m,b,num,labor_time,remaining_block_cnt;
    bool is_block_smaller_than_zero = false;
    cin >> n >> m >> b;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> num;
            arr[i][j] = num;
        }
    }

    for(long long ht = 0; ht<=256; ht++)
    {
        labor_time = 0;
        remaining_block_cnt = b;
        is_block_smaller_than_zero = false;
        //case 1 : 블록 제거 부터해서 블록 확보
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(arr[i][j] > ht)
                {
                    labor_time += 2 * (arr[i][j] - ht);
                    remaining_block_cnt += (arr[i][j] - ht);                    
                }
            }
        }
        //case 2 : 블록 위에 놓기
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(arr[i][j] < ht)
                {
                    labor_time += (ht - arr[i][j]);    
                    remaining_block_cnt -= (ht - arr[i][j]);//ERROR : remaining_block_cnt--     
                }
                if(remaining_block_cnt < 0)
                {
                    is_block_smaller_than_zero = true;
                    break;
                }
            }  
            if(is_block_smaller_than_zero == true)
            {
                break;
            }          
        }   
        if(is_block_smaller_than_zero == false)
        {
            if(labor_time <= min_labor_time)
            {
                min_labor_time = labor_time;
                max_ht = ht;
            }
        } 
    }

    cout << min_labor_time << " " << max_ht;
	return 0;
}


