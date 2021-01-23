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

2. 어려웠던 부분

*/
int c,r,m,row_r,row_c;
pair<int,int> flag[4];
int arr[12][12];
int old_arr[12][12];
int visited[12][12];

void Laddar(int depth)
{    
    bool is_answer = true;
    int cur_r, cur_c;
    memcpy(arr , old_arr , sizeof(arr));  

    /*if(1 <= depth)
    {
        for(int i=1; i<=depth; i++)
        {            
            arr[flag[i].first][flag[i].second] = 1;
        }
    }*/
    for(int i=1; i<=c; i++)
    {
        memset(visited , 0 , sizeof(visited)); //ERROR : 초기화 안했음.
        cur_r = 1;
        cur_c = i;      
        while(cur_r != r)
        {            
            cout << cur_r << cur_c << " ";         
            if(arr[cur_r][cur_c-1] == 1 && visited[cur_r][cur_c-1] == 0) 
            {
                visited[cur_r][cur_c] = 1;
                cur_c--;
                continue; 
            }
            if(arr[cur_r][cur_c] == 1 && visited[cur_r][cur_c+1] == 0)
            {
                visited[cur_r][cur_c] = 1;
                cur_c++; 
            }     
            else //최강 ERROR : 캡쳐와 비교 -> 디버깅에 오래걸림.
            {               
                visited[cur_r][cur_c] = 1; 
                cur_r++;                
            }       
        }
        if(cur_c != i)
        {
            is_answer = false;
            break;
        }
    }
    if(is_answer == true)
    {
        cout << depth;
        exit(1);
    }
    cout << "end";
}
void Dfs(int depth , int max_depth)
{  
    for(int i=1; i<=r; i++)
    {        
        for(int j=1; j<c; j++)
        {          
            if(old_arr[i][j-1] == 1 || old_arr[i][j] == 1 || old_arr[i][j+1] == 1) //같은 줄 OR 이미 있음.
            {
                continue;
            }
            flag[depth].first = i;
            flag[depth].second = j;
            if(depth+1 < max_depth)
            {
                Dfs(depth+1 , max_depth);
            }
            else
            {
                Laddar(depth);
            }            
        }
    } 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    cin >> c >> m >> r;  
    for(int i=0; i<m; i++)
    {
        cin >> row_r >> row_c;
        old_arr[row_r][row_c] = 1; //1이면 우측으로 길 있음.
    }
    for(int i=0;i<4;i++)
    {
        flag[i].first = -999;
        flag[i].second = -999;
    }
    //가로선을 추가하지 않는 경우
    //Laddar(0);
    //가로선을 추가하는 경우 : 1~3개 추가
    //Dfs(1,1);
    //Dfs(1,2);
    //Dfs(1,3);
    /*old_arr[4][2] = 1;
    old_arr[1][3] = 1;
    old_arr[3][4] = 1;
    Laddar(3);*/	    
    return 0;
}


