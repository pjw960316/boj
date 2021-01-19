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

1) 현재 백준의 모든 테스트케이스 + 질의응답 테스트케이스 모두 통과한 상태.
*/
int saw[5][9];
int path[5];
int is_circulate[5];

void ChangeSaw(int saw_num)
{
    int tmp[8];
    for(int i=0;i<8;i++)
    {
        tmp[i] = saw[saw_num][i];
    }

    if(path[saw_num]==-1)//반시계
    {        
        for(int i=0; i<8; i++)
        {
            saw[saw_num][i] = tmp[(i+1)%8];
        }
    }
    else//시계
    {
        for(int i=0; i<8; i++)
        {
            saw[saw_num][i] = tmp[(i+7)%8];
        }        
    }
}

int ChangePath(int before_saw_num)
{
    if(path[before_saw_num] == 1)
    {        
        return -1;
    }
    else
    {
        return 1;
    }
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    string str;
    int test_case,saw_num,clock_path;
    int sum=0;
    for(int i=1; i<=4; i++)
    {
        cin >> str;
        for(int j=0; j<str.size(); j++)
        {
            saw[i][j] = str[j] -'0';
        }
    }
    cin >> test_case;
    for(int i=0; i<test_case; i++)
    {
        cin >> saw_num >> clock_path;
        memset(path , 0 , sizeof(path));
        memset(is_circulate , 0 , sizeof(is_circulate));
        path[saw_num] = clock_path;
        is_circulate[saw_num] = 1;
        if(saw_num == 1)
        {
            if(saw[1][2] != saw[2][6])
            {
                is_circulate[2] = 1;
                path[2] = ChangePath(1);
                if(saw[2][2] != saw[3][6])
                {
                    is_circulate[3] = 1;
                    path[3] = ChangePath(2);
                    if(saw[3][2] != saw[4][6])
                    {
                        is_circulate[4] = 1;
                        path[4] = ChangePath(3);
                    }
                }
            }
        }
        else if(saw_num == 2)
        {
            if(saw[2][6] != saw[1][2])
            {
                is_circulate[1] = 1;
                path[1] = ChangePath(2);                
            }
            if(saw[2][2] != saw[3][6])
            {
                is_circulate[3] = 1;
                path[3] = ChangePath(2);
                if(saw[4][2] != saw[3][6])
                {
                    is_circulate[4] = 1;
                    path[4] = ChangePath(3);
                }
            }
        }
        else if(saw_num == 3)
        {
            if(saw[3][6] != saw[2][2])
            {
                is_circulate[2] = 1;
                path[2] = ChangePath(3);   
                if(saw[2][6] != saw[1][2])
                {
                    is_circulate[1] = 1;
                    path[1] = ChangePath(2);
                }             
            }
            if(saw[3][2] != saw[4][6])
            {
                is_circulate[4] = 1;
                path[4] = ChangePath(3);                
            }
        }
        else
        {
            if(saw[4][6] != saw[3][2])
            {
                is_circulate[3] = 1;
                path[3] = ChangePath(4);
                if(saw[3][6] != saw[2][2])
                {
                    is_circulate[2] = 1;
                    path[2] = ChangePath(3);
                    if(saw[2][6] != saw[1][2])
                    {
                        is_circulate[1] = 1;
                        path[1] = ChangePath(2);                        
                    }
                }
            }
        }
        for(int j=1; j<=4; j++)
        {
            if(is_circulate[j] == 1)
            {
                ChangeSaw(j);
            }
        }    
    }    
    for(int i=1; i<=4; i++)
    {
       sum += saw[i][0] * pow(2,i-1);
    }
    cout << sum;
	return 0;
}


