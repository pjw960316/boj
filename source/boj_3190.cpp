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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    //문제 해결을 위한 자료구조
    char arr[101][101];
    memset(arr , 'x' , sizeof(arr));
    arr[1][1] = 'o';
    
    queue<pair<int,int>> q;
    q.push({1,1});
    int snake_length = 1;
    pair<int,int> path[4] = {{0,1} , {1,0} , {0,-1}, {-1,0}};
    int flag = 0; //path's flag
    vector<pair<int,char>> v;
    int game_time = 0;

    //입력
    int n,apple_cnt,row,col,change_path_cnt,x;
    char c;
    cin >> n;
    cin >> apple_cnt;
    for(int i=0; i<apple_cnt; i++)
    {
        cin >> row >> col;
        arr[row][col] = 'a';
    }
    cin >> change_path_cnt;
    for(int i=0; i<change_path_cnt; i++)
    {
        cin >> x >> c;
        v.push_back({x,c});
    }
       
    //탐색 시작
    while(1)
    {   
        //방향 설정
        for(auto i : v)
        {            
            if(i.first == game_time)
            {                       
                if(i.second == 'L')
                {
                    if(flag != 0)
                    {
                        flag--;
                    }
                    else
                    {   
                        flag = 3;                        
                    }                    
                }
                else
                {
                    if(flag != 3)
                    {
                        flag++;
                    }
                    else
                    {
                        flag = 0;
                    }                    
                }                           
            }           
        }
        
        //이동하면서 검사              
        int next_x = q.back().first + path[flag].first;
        int next_y = q.back().second + path[flag].second;
        
        //ERROR 1
        if(next_x == 0 || next_x == n+1 || next_y == 0 || next_y == n+1)
        {      
            cout << game_time+1;
            return 0;
        }

        //ERROR 2
        if(arr[next_x][next_y] == 'o')
        {                  
            cout << game_time+1;
            return 0;
        }     
                                   
        if(arr[next_x][next_y] == 'a')
        {
            arr[next_x][next_y] = 'o'; 
            q.push({next_x,next_y});   
            snake_length++;              
        }
        else
        {                      
            arr[next_x][next_y] = 'o'; 
            q.push({next_x,next_y});          
            arr[q.front().first][q.front().second] = 'x';
            q.pop(); 
        }    
        /* 
        for(int i=0; i<=n+1;i++)
        {
            for(int j=0; j<=n+1; j++)
            {
                cout << arr[i][j];
            }
            cout <<"\n";
        }     
        cout <<"\n\n";   */
        game_time++; 
    }
	return 0;
}
