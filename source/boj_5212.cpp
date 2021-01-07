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

1) 시간복잡도가 작아서 매우 자유로웠습니다.
2) 50년뒤의 그래프 모양을 다른 배열에 저장합니다.
3) 작은 사각형 -> 이전에 풀어본 유형

2. 어려웠던 부분
- 0-1문제 , string은 0부터 세고 , arr[][]는 1부터 셉니다.
*/

char before_arr[12][12];
char after_arr[12][12];
pair<int,int> path[4] = {{-1,0},{0,1},{1,0},{0,-1}};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

    memset(before_arr , '.' , sizeof(before_arr));    
    int r,c;
    int sum,next_r,next_c;
    string str;
    cin >> r >> c;
    for(int i=1; i<=r; i++)
    {
        cin >> str;
        for(int j=1; j<=c; j++)
        {
            before_arr[i][j] = str[j-1]; //ERROR : 0-1
        }
    }
    memcpy(after_arr , before_arr , sizeof(after_arr));    
 
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            if(before_arr[i][j] == 'X')
            {
                sum=0;
                for(int k=0; k<4; k++)
                {
                    next_r = i+path[k].first;
                    next_c = j+path[k].second;
                    if(before_arr[next_r][next_c] == '.')
                    {
                        sum++;
                    }                      
                }
                if(sum==3 || sum==4)
                {
                    after_arr[i][j] = '.';
                }
            }
        }
    }

    int min_r=99 ,min_c=99 , max_r=-1, max_c=-1;
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            if(after_arr[i][j] == 'X')
            {
                min_r = min(min_r , i);
                min_c = min(min_c , j);
                max_r = max(max_r , i);
                max_c = max(max_c , j);
            }
        }
    }
    //cout << min_r << " " << min_c << " " << max_r << " " << max_c << "\n";
    for(int i=min_r; i<=max_r; i++)
    {
        for(int j=min_c; j<=max_c; j++)
        {
            cout << after_arr[i][j];
        }
        cout << "\n";
    }
	
	return 0;
}


