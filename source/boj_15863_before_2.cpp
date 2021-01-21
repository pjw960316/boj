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

1) N과M조합
= N과M조합 에 대한 문제를 풀고나니 할만 했습니다.
*/

int n , m;
int arr[10][10];
int old_arr[10][10];
int flag[100];
int result = 9999999;
int cctv=0;
pair<int,int> path[4] = {{-1,0},{0,1},{1,0},{0,-1}};

//기존의 Dfs , Bfs가 아닌 반복문 완전 탐색
void Search()
{
    int next_x , next_y , check;
    int index=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(arr[i][j] == 1)
            {
                check = 1;
                while(1)
                {
                    next_x = i+(path[flag[1]].first)*check;
                    next_y = j+(path[flag[1]].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y || arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    arr[next_x][next_y] = 7;
                    check++;
                }   
            }
            else if(arr[i][j] == 2)
            {
                check = 1;
                while(1)
                {
                    next_x = i+(path[flag[2]].first)*check;
                    next_y = j+(path[flag[2]].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y || arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    arr[next_x][next_y] = 7;
                    check++;
                }
                check = 1;
                while(1)
                {                    
                    next_x = i+(path[flag[2]+2].first)*check;
                    next_y = j+(path[flag[2]+2].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y || arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    arr[next_x][next_y] = 7;   
                    check++;   
                }               
            }
            else if(arr[i][j] == 3)
            {
                check = 1;
                while(1)
                {                    
                    next_x = i+(path[flag[3]%4].first)*check;
                    next_y = j+(path[flag[3]%4].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y || arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    arr[next_x][next_y] = 7;   
                    check++;  
                }
                check = 1;
                while(1)
                {                    
                    next_x = i+(path[(flag[3]+1)%4].first)*check;
                    next_y = j+(path[(flag[3]+1)%4].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y ||arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    arr[next_x][next_y] = 7;   
                    check++;  
                }  
            }
            else if(arr[i][j] == 4)
            {
                check = 1;
                while(1)
                {                    
                    next_x = i+(path[flag[4]%4].first)*check;
                    next_y = j+(path[flag[4]%4].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y ||arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    arr[next_x][next_y] = 7;   
                    check++;  
                }
                check = 1;
                while(1)
                {                    
                    next_x = i+(path[(flag[4]+1)%4].first)*check;
                    next_y = j+(path[(flag[4]+1)%4].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y || arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    arr[next_x][next_y] = 7;   
                    check++;  
                }
                check = 1;
                while(1)
                {                    
                    next_x = i+(path[(flag[4]+2)%4].first)*check;
                    next_y = j+(path[(flag[4]+2)%4].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y || arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    arr[next_x][next_y] = 7;   
                    check++;  
                }                 
            }
            else if(arr[i][j] == 5)
            {
                check = 1;
                while(1)
                {                    
                    next_x = i+(path[0].first)*check;
                    next_y = j+(path[0].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y || arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    arr[next_x][next_y] = 7;   
                    check++;  
                }
                check = 1;
                while(1)
                {                    
                    next_x = i+(path[1].first)*check;
                    next_y = j+(path[1].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y || arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    arr[next_x][next_y] = 7;   
                    check++;  
                }
                check = 1;
                while(1)
                {                    
                    next_x = i+(path[2].first)*check;
                    next_y = j+(path[2].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y || arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    arr[next_x][next_y] = 7;   
                    check++;  
                }
                check = 1;
                while(1)
                {                    
                    next_x = i+(path[3].first)*check;
                    next_y = j+(path[3].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y || arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    arr[next_x][next_y] = 7;   
                    check++;  
                }                 
            }
        }
    }
}

void Answer()
{
    int sum = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(arr[i][j] == 0)
            {
                sum++;
            }
        }
    }
    result = min(result , sum);
}

void Dfs(int depth)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(old_arr[i][j] == 2)
            {
                for(int i=0; i<2; i++)
                {
                    flag[index] = i;
                    Dfs(depth+1);
                }
            }
            else if(old_arr[i][j] == cctv)
            {
                
            }            
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
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(1<= old_arr[i][j] && old_arr[i][j] <=5)
            {
                cctv++;
            }
        }
    }
    Dfs(1);
    cout << result;
    cout << "\n";
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout <<"\n";
    }
	return 0;
}


