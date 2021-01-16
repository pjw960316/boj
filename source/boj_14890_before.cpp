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

struct str
{
    int ht;
    bool has_slope;
    bool can_road;
};
str arr[200][200];
int answer;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    int n,l;
    bool can_build_slope;
    cin >> n >> l;
    //initialize
    for(int i=0; i<=n+1; i++)
    {
        for(int j=0; j<=n+1; j++)
        {
            arr[i][j].ht = -999;
            arr[i][j].can_road = false;
            arr[i][j].has_slope = false;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> arr[i][j].ht;
        }
    }

    for(int i=1; i<=n; i++)
    {        
        //2가지 예외케이스를 일단은 만들지 않습니다. 
        //이론상 시간초과가 발생하지 않으므로 진행.
        for(int j=1; j<=n; j++)
        {                       
            //case_1 : --
            if(arr[i][j].ht-1 == arr[i][j+1].ht)
            {
                can_build_slope = true;
                for(int k=1; k<=l; k++)
                {
                    if(arr[i][j].ht-1 != arr[i][j+k].ht || arr[i][j+k].has_slope == true)
                    {
                        arr[i][j].can_road = false;
                        can_build_slope = false;
                        break;
                    }
                }
                if(can_build_slope == true)
                {
                    arr[i][j].can_road = true;
                    for(int k=1; k<=l; k++)
                    {               
                        arr[i][j+k].has_slope = true;    
                        arr[i][j].can_road = true;                              
                    }
                }
                else //길을 만들지 못하는 경우가 한 번이라도 발생하면 break;
                {
                    break;
                }
                
            }
            //case_2 : ++
            else if(arr[i][j].ht+1 == arr[i][j+1].ht)
            {
                can_build_slope = true;
                for(int k=0; k<l; k++)
                {
                    if(arr[i][j].ht != arr[i][j-k].ht || arr[i][j-k].has_slope == true)
                    {
                        arr[i][j].can_road = false;
                        can_build_slope = false;
                        break;
                    }
                }
                if(can_build_slope == true)
                {
                    arr[i][j].can_road = true;
                    for(int k=1; k<=l; k++)
                    {               
                        arr[i][j-k].has_slope = true;
                        arr[i][j-k].can_road = true;          
                    }
                }
                else
                {
                    break;
                }
                
            }    
            //case_3 : ==
            else
            {
                arr[i][j].can_road = true;  
            }
                                
        }

        int sum=0;
        for(int j=1; j<=n; j++)
        {            
            if(arr[i][j].can_road == true)
            {   
                sum++;
            }
        }
        if(sum==n)
        {
            cout << i << " ";
            answer++;
        }        
        for(int j=1; j<=n; j++)//다음 검사를 위한 초기화
        {
            arr[i][j].has_slope = false;
            arr[i][j].can_road = false;
        }
    }
    
    cout << answer;
	return 0;
}


