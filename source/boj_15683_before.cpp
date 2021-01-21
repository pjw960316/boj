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

int arr[10][10];
int old_arr[10][10];
int flag[6];
int n,m;
pair<int,int> path[4] = {{-1,0},{0,1},{1,0},{0,-1}};

void Search(int r , int c)
{
    //while들을 쪼개면 될 것 같습니다.
    //일단 이런 문제를 보고 어떻게 사고가 갈지 다시 정립.
    int next_x,next_y,check;    
    if(arr[r][c] == 1)
    {
        check = 1;
        while(arr[r][c] != -1 || arr[r][c] != 6)
        {
            next_x = r+path[flag[1]].first*check;
            next_y = r+path[flag[1]].second*check;
            arr[next_x][next_y] = -2;
            check++;
        }        
    }
    else if(arr[r][c] == 2)
    {
        check = 1;
        while(arr[r][c] != -1 || arr[r][c] != 6)
        {
            next_x = r+path[flag[2]].first*check;
            next_y = r+path[flag[2]].second*check;
            arr[next_x][next_y] = -2;
            next_x = r+path[flag[2]+2].first*check;
            next_y = r+path[flag[2]+2].second*check;
            arr[next_x][next_y] = -2;
            check++;
        }  
    }
    else if(arr[r][c] == 3)
    {
        check = 1;
        while(arr[r][c] != -1 || arr[r][c] != 6)
        {
            next_x = r+path[(flag[3])%4].first*check;
            next_y = r+path[(flag[3])%4].second*check;
            arr[next_x][next_y] = -2;
            next_x = r+path[(flag[3]+1)%4].first*check;
            next_y = r+path[(flag[3]+1)%4].second*check;
            arr[next_x][next_y] = -2;
            next_x = r+path[(flag[3]+2)%4].first*check;
            next_y = r+path[(flag[3]+2)%4].second*check;
            arr[next_x][next_y] = -2;
            check++;
        }  
    }
    else if(arr[r][c] == -1)
    {
        return;
    }    
}

void MakeAllCase(int depth)
{
    if(depth==5)
    {
        flag[depth] = 0;
        memcpy(arr , old_arr , sizeof(arr));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(1<= arr[i][j] && arr[i][j] <=5)
                {
                    Search(i,j);
                }
            }
        }
        return;
    }
    if(depth==2)
    {
        for(int i=0; i<2; i++)
        {
            flag[depth] = i;
            MakeAllCase(depth+1);
        }
    }
    else
    {
        for(int i=0;i<4; i++)
        {
            flag[depth] = i;
            MakeAllCase(depth+1);
        }
    }   
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	   
    cin >> n >> m;
    memset(old_arr,-1,sizeof(arr));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> old_arr[i][j];
        }
    }
    MakeAllCase(1);
    return 0;
}


