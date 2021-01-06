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

struct str
{
    int north;
    int east;
    int south;
    int west;
    int top;
    int down;
};
int arr[22][22];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    int n,m,r,c,test_case,num;
    cin >> n >> m >> r >> c >> test_case;
    memset(arr,-1,sizeof(arr));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> num;
            arr[i][j] = num;
        }
    }

    str dice;
    str tmp;
    dice.top=0;
    dice.down=0;
    dice.north=0;
    dice.east=0;
    dice.south=0;
    dice.west=0;

    for(int i=0; i<test_case;i++)
    {
        tmp = dice;     
        cin>>num;
        if(num==1) //east
        {     
            if(r==-1 || c+1 == -1 || r == n || c+1 == m)
            {
                continue;
            }       
            c++;            
            if(arr[r][c]!=0)
            {
                tmp.east = arr[r][c];
            }
            else
            {
                arr[r][c] = tmp.east;
            }            
            dice.top = tmp.west;
            dice.down = tmp.east;
            dice.east = tmp.top;
            dice.west = tmp.down;
        }
        else if(num==2) //west
        {
            if(r==-1 || c-1 == -1 || r == n || c-1 == m)
            {
                continue;
            }
            c--;            
            if(arr[r][c]!=0)
            {
                tmp.west = arr[r][c];
            }
            else
            {
                arr[r][c] = tmp.west;
            }            
            dice.top = tmp.east;
            dice.down = tmp.west;
            dice.east = tmp.down;
            dice.west = tmp.top;
        }
        else if(num==3) //north
        {
            if(r-1==-1 || c == -1 || r-1 == n || c == m)
            {
                continue;
            }
            r--;            
            if(arr[r][c]!=0)
            {
                tmp.north = arr[r][c];
            }
            else
            {
                arr[r][c] = tmp.north;
            }            
            dice.top = tmp.south;
            dice.down = tmp.north;
            dice.north = tmp.top;
            dice.south = tmp.down;
        }
        else //south
        {
            if(r+1== -1 || c == -1 || r+1 == n || c == m)
            {
                continue;
            }
            r++;           
            if(arr[r][c]!=0)
            {
                tmp.south = arr[r][c];
            }
            else
            {
                arr[r][c] = tmp.south;
            }            
            dice.top = tmp.north;
            dice.down = tmp.south;
            dice.north = tmp.down;
            dice.south = tmp.top;
        }
        cout << dice.top <<"\n";
    }
    
	return 0;
}


