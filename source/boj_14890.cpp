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
- 조건이 다양하지만 구현 가능한 범위
- struct를 이용하여 조건 3가지를 멤버 변수로 설정한 후
조건을 구현

2. 어려웠던 부분
1) 막혔을 때
- 막혔을 때(많은 조건문 + 0-1 offset) 생각을 정리하고 
문제를 처음부터 다시 풀어서 성공했습니다. 다시 푸는 과정에서
노트에서 긴 시간을 보내고 완벽히 정립한 후 코딩은 10분 컷.

2) 다중 for문 탈출
- 매우 좋은 새로운 방법 발견 -> 필기

3) 가로 , 세로
- 배열을 2개 만들어서 세로 검사를 가로로 변경

4) Solve에서 예외 조건을 만드는 것이 옳은지
- 모든 라인이 같은지와 , 2이상 차이나는 땅이 존재하면 해당 줄은 검사하지 않음
위의 조건을 먼저 돌려보는 것이 과연 옳은지 고민입니다.

*/

struct str
{
    int ht;
    bool has_slope;
    bool can_road;
};
str arr1[103][103];
str arr2[103][103];
int n,l;
int answer = 0;
   
void Solve(str arr[][103])
{
    bool is_line_success;
    bool can_answer;
    for(int i=1; i<=n; i++)
    {
        is_line_success = true;
        for(int j=1; j<=n; j++)
        {
            if(j==n)
            {
                arr[i][j].can_road = true;
            }
            //case_1 : --
            if(arr[i][j].ht-1 == arr[i][j+1].ht)
            {
                for(int k=1; k<=l; k++)
                {
                    if(arr[i][j].ht-1 != arr[i][j+k].ht || arr[i][j+k].has_slope == true) 
                    {
                        j=n;
                        is_line_success = false;
                        break;
                    }
                }
                if(is_line_success == false)
                {
                    break;
                }
                arr[i][j].can_road = true;
                for(int k=1; k<=l; k++)
                {
                    arr[i][j+k].can_road = true;
                    arr[i][j+k].has_slope = true;
                }
            }
            //case_2 : ++
            else if(arr[i][j].ht+1 == arr[i][j+1].ht)
            {
                for(int k=0; k<l; k++)
                {
                    if(arr[i][j].ht != arr[i][j-k].ht || arr[i][j-k].has_slope == true) 
                    {
                        j=n;
                        is_line_success = false;
                        break;
                    }
                }
                if(is_line_success == false)
                {
                    break;
                }
                arr[i][j].can_road = true;
                for(int k=0; k<l; k++)
                {
                    arr[i][j-k].can_road = true;
                    arr[i][j-k].has_slope = true;
                }                
            }
            //case_3 : ==
            else if(arr[i][j].ht == arr[i][j+1].ht)
            {
                arr[i][j].can_road = true;
            }         
            else
            {
                continue;
            }
            
        } 

        can_answer = true;       
        for(int j=1; j<=n; j++)
        {
            if(arr[i][j].can_road == false)
            {
                can_answer = false;
                break;
            }
        }  
        if(can_answer == true)
        {
            answer++;
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    cin >> n >> l; 
    for(int i=0; i<=102; i++)
    {
        for(int j=0; j<=102; j++)
        {
            arr1[i][j].ht = -999;
            arr1[i][j].can_road = false;
            arr1[i][j].has_slope = false;
        }
    }
    memcpy(arr2,arr1,sizeof(arr2));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> arr1[i][j].ht; 
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            arr2[i][j].ht = arr1[j][i].ht;
        }
    }
    Solve(arr1);
    Solve(arr2);
    cout << answer;

	return 0;
}
