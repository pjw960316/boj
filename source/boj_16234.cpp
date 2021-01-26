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
1) 배열을 한 번 완전탐색 할 때 한번이라도 이동이 있으면 is_move = true
2) 전체 배열에서 부분적으로 bfs해서 이동시키기
3) 이동시킬 때 마다 값을 vector에 넣어서 평균치 구하기

2. 어려웠던 부분
- 노트에서 이론을 전개하고 , 검증을 자주하다 보니 코딩 시간이 매우 줄어들었습니다.

3. 토론 거리
- 50*50개를 탐색할 때 visited가 0일 때 bfs를 하는 방식보다 훌륭한 것이 있는가?
*/
struct str
{
    int r;
    int c;
    int population;
};

bool is_move;
int arr[52][52];
int visited[52][52];
int n,limit_l,limit_r,move_cnt;
queue<pair<int,int>> q;
vector<str> v;
pair<int,int> path[4] = {{-1,0},{0,1},{1,0},{0,-1}};

void Bfs(int r , int c)
{
    int cur_r,cur_c,next_r,next_c;
    while(q.empty() == false)
    {
        cur_r = q.front().first;
        cur_c = q.front().second;
        for(int i=0; i<4; i++)
        {            
            next_r = cur_r+path[i].first;
            next_c = cur_c+path[i].second;            
            if(visited[next_r][next_c] == 0 && limit_l <= abs(arr[cur_r][cur_c] - arr[next_r][next_c]) && abs(arr[cur_r][cur_c] - arr[next_r][next_c]) <= limit_r)
            {
                visited[next_r][next_c] = 1;
                q.push({next_r,next_c});
                v.push_back({next_r,next_c,arr[next_r][next_c]});                
                is_move = true;                
            }                    
        }
        q.pop();       
    }
    int sum=0 , avg = 0;     
    for(auto i : v)
    {
        sum += i.population;
    }
    avg = sum/v.size();
    for(auto i : v)
    {
        arr[i.r][i.c] = avg;
    }
    v.clear();
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    cin >> n >> limit_l >> limit_r;
    memset(arr , -1 , sizeof(arr));
    memset(visited , -1 , sizeof(visited));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> arr[i][j];
        }
    }

    while(1)
    {
        is_move = false;        
        for(int i=1; i<=n;i++)
        {
            for(int j=1; j<=n; j++)
            {
                visited[i][j] = 0;
            }
        }
        v.clear();

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(visited[i][j] == 0)
                {
                    visited[i][j] = 1;
                    q.push({i,j});
                    v.push_back({i,j,arr[i][j]});                   
                    Bfs(i,j);
                }
            }
        }       
        if(is_move == false)
        {            
            cout << move_cnt;
            return 0;
        }
        move_cnt++;
    }
    
	return 0;
}


