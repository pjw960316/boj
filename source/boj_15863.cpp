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
- 연구소 문제와 매우 유사합니다.
- 모든 카메라 방향 조합을 DFS로 구하고 
그 때 마다 감시 지역을 검사합니다.

2. 어려웠던 부분

1) N과M조합
- N과M조합이 아직도 익숙하지 않아서
백준의 관련 문제집을 풀고나니 할만 했습니다.

2) 확실한 구현 그러나 긴 코드
- 브루트 포스다 보니 확실한 구현 방법이 있으나
코드가 길어져 두려움을 계속 느낍니다.

3) 문제이해 실패
- 1번 카메라가 오른쪽을 보면 모든 1번이 오른쪽을 보는 방식으로 이해함.

4) 잦은 ERROR -> 아래의 주석

3. 토론점
- Search()의 코드 길이를 줄이고 싶어.
*/

int n , m;
int arr[10][10];
int old_arr[10][10];
int flag[10];
int result = 9999999;
int cctv=0;
pair<int,int> path[4] = {{-1,0},{0,1},{1,0},{0,-1}};

//기존의 Dfs , Bfs가 아닌 반복문 완전 탐색
void Search()
{
    int next_x , next_y , check;
    int index=0;
    int cctv_cnt=1;

    for(int i=1; i<=n; i++)//flag에 해당 반복문의 탐색순서로 저장했기 때문에 cctv_cnt를 더해가면서 계산합니다.
    {
        for(int j=1; j<=m; j++)
        {
            if(arr[i][j] == 1)
            {                
                check = 1;
                while(1)
                {
                    next_x = i+(path[flag[cctv_cnt]].first)*check;
                    next_y = j+(path[flag[cctv_cnt]].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y || arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    if(arr[next_x][next_y] == 0) //ERROR_1 : if문이 없이 모두 7로 바꿨는데, 이러면 다른 cctv를 없애버립니다.
                    {
                        arr[next_x][next_y] = 7;
                    }
                    check++;
                }
                cctv_cnt++;   
            }
            else if(arr[i][j] == 2)
            {
                check = 1;
                while(1)
                {
                    next_x = i+(path[flag[cctv_cnt]].first)*check;
                    next_y = j+(path[flag[cctv_cnt]].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y || arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    if(arr[next_x][next_y] == 0)
                    {
                        arr[next_x][next_y] = 7;
                    }
                    check++;
                }
                check = 1;
                while(1)
                {                    
                    next_x = i+(path[(flag[cctv_cnt]+2)%4].first)*check;
                    next_y = j+(path[(flag[cctv_cnt]+2)%4].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y || arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    if(arr[next_x][next_y] == 0)
                    {
                        arr[next_x][next_y] = 7;
                    }  
                    check++;   
                }    
                cctv_cnt++;           
            }
            else if(arr[i][j] == 3)
            {
                check = 1;
                while(1)
                {                    
                    next_x = i+(path[flag[cctv_cnt]%4].first)*check;
                    next_y = j+(path[flag[cctv_cnt]%4].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y || arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    if(arr[next_x][next_y] == 0)
                    {
                        arr[next_x][next_y] = 7;
                    }   
                    check++;  
                }
                check = 1;
                while(1)
                {                    
                    next_x = i+(path[(flag[cctv_cnt]+1)%4].first)*check;
                    next_y = j+(path[(flag[cctv_cnt]+1)%4].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y ||arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    if(arr[next_x][next_y] == 0)
                    {
                        arr[next_x][next_y] = 7;
                    } 
                    check++;  
                } 
                cctv_cnt++; 
            }
            else if(arr[i][j] == 4)
            {
                check = 1;
                while(1)
                {                    
                    next_x = i+(path[flag[cctv_cnt]%4].first)*check;
                    next_y = j+(path[flag[cctv_cnt]%4].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y ||arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    if(arr[next_x][next_y] == 0)
                    {
                        arr[next_x][next_y] = 7;
                    }  
                    check++;  
                }
                check = 1;
                while(1)
                {                    
                    next_x = i+(path[(flag[cctv_cnt]+1)%4].first)*check;
                    next_y = j+(path[(flag[cctv_cnt]+1)%4].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y || arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    if(arr[next_x][next_y] == 0)
                    {
                        arr[next_x][next_y] = 7;
                    }  
                    check++;  
                }
                check = 1;
                while(1)
                {                    
                    next_x = i+(path[(flag[cctv_cnt]+2)%4].first)*check;
                    next_y = j+(path[(flag[cctv_cnt]+2)%4].second)*check;
                    if(next_x < 1 || next_y < 1 || n < next_x || m < next_y || arr[next_x][next_y] == 6)
                    {
                        break;
                    }
                    if(arr[next_x][next_y] == 0)
                    {
                        arr[next_x][next_y] = 7;
                    }  
                    check++;  
                }  
                cctv_cnt++;               
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
                    if(arr[next_x][next_y] == 0)
                    {
                        arr[next_x][next_y] = 7;
                    }  
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
                    if(arr[next_x][next_y] == 0)
                    {
                        arr[next_x][next_y] = 7;
                    }  
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
                    if(arr[next_x][next_y] == 0)
                    {
                        arr[next_x][next_y] = 7;
                    }   
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
                    if(arr[next_x][next_y] == 0)
                    {
                        arr[next_x][next_y] = 7;
                    }   
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
    if(depth==cctv)
    {        
        for(int i=0; i<4; i++)
        {
            flag[depth]=i;
            memcpy(arr , old_arr , sizeof(arr)); //ERROR_2 : 초기화            
            Search();
            Answer();
        }
        return;
    }
    for(int i=0; i<4; i++)
    {
        flag[depth] = i;
        Dfs(depth+1);
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
    if(cctv==0) //ERROR_3 : CCTV가 1개일 때 Dfs(1)에서 depth=1이므로 런타임에러가 발생합니다.
    {
        int plz_give_answer= 0 ;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(old_arr[i][j] == 0)
                {
                    plz_give_answer++;
                }
            }
        }
        cout << plz_give_answer;
        return 0;
    }
    Dfs(1);

    cout << result;
    
	return 0;
}


