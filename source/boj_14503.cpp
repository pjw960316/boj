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

1) 절대적으로 문제를 그대로 따라가서 구현했습니다.
- 기존의 dfs , bfs는 4방향을 모두 검사하고 각각의 case를 모두 수행하지만
이 문제는 4방향 중에 1방향의 case만 존재해서 시간적으로도 매우 여유롭습니다.

2) 문제의 요구는 이동 -> 청소 지만 청소 -> 이동에 문제가 없음을 검증하고 바꿔서
해결했습니다.

2. 어려웠던 부분

1) 전역변수와 지역변수
- MoveLeftFlag() 함수에서 지역변수 , 전역변수가 flag를 공유해서
전역변수의 flag가 값이 변하지 않았고 그로 인해
flag의 값이 이상해져서 MoveRobot에서 무한루프에 빠지게 되었습니다.

2) 문제를 제대로 읽지 않아서 배열을 (0,0) 시작으로 할 지 (1,1)로 할지 고민함

3) 설명 2-b에서 청소된 지역은 이동하는지 이동하지 않는지 고민.

4) flag 설정에 정형화 된 풀이가 반드시 필요합니다.
*/

int arr[52][52];
int cleaned_room = 0;
pair<int,int> path[4] = {{-1,0},{0,1},{1,0},{0,-1}};
int flag;

void MoveLeftFlag() //ERROR : 처음에 void MoveLeftFlag(int flag)로 함.
{
    if(flag == 0)
    {
        flag = 3;
    }
    else
    {
        flag--;
    }
}

void MoveRobot(int r , int c)
{       
    bool can_move = false;
    for(int j=0; j<4; j++)
    {
        if(arr[r+path[j].first][c+path[j].second] == 0)
        {
            can_move = true;
            break; 
        }
    }
    if(can_move == true)
    {
        if(flag == 0)
        {
            //case 1
            if(arr[r+path[3].first][c+path[3].second] == 0)
            {
                MoveLeftFlag();
                arr[r+path[flag].first][c+path[flag].second] = 2;
                cleaned_room++;
                MoveRobot(r+path[flag].first,c+path[flag].second);
            }
            //case 2
            else
            {
                MoveLeftFlag();   
                MoveRobot(r,c);            
            }        
        }     
        else
        {
            //case 1
            if(arr[r+path[flag-1].first][c+path[flag-1].second] == 0)
            {
                MoveLeftFlag();
                arr[r+path[flag].first][c+path[flag].second] = 2;
                cleaned_room++;
                MoveRobot(r+path[flag].first,c+path[flag].second);
            }
            //case 2
            else
            {
                MoveLeftFlag();
                MoveRobot(r,c);            
            }   
        }
    }
    else
    {
        int flag_2; //이거 좀 정형화 되게 공부해야함
        if(flag <2)
        {
            flag_2 = flag+2;
        }
        else
        {
            flag_2 = flag-2;
        }
        int back_r = r+path[flag_2].first;
        int back_c = c+path[flag_2].second;

        //case 3
        if(arr[back_r][back_c] == 2)
        {            
            MoveRobot(back_r , back_c);
        }

        //case 4
        else
        {
            cout << cleaned_room;
            return;
        }
    }        
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    for(int i=0; i<52; i++)
    {
        for(int j=0; j<52; j++)
        {
            arr[i][j] = 1;
        }
    }
    int n,m,num,init_r,init_c;
    cin >> n >> m;
    cin >> init_r >> init_c >> flag;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> num;
            arr[i][j] = num;
        }
    }
    arr[init_r][init_c] = 2;
    cleaned_room++;
    MoveRobot(init_r , init_c);

	return 0;
}


