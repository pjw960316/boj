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

1) 첫 번째 제출 : 시간 초과
- 테스트 케이스의 개수가 주어지지 않았습니다.
- 이전의 풀이는 요즘 brute force를 많이 하다 보니 , 시간복잡도만 괜찮다면 최고의 방법이어서 일부로 최적화 하지 않고 풀어보았습니다.
- 1000*1000 = 100만이고 테스트 케이스 100개 까지는 여유로워서 brute force가 될 줄 알았습니다.

2) 두 번째 제출 : 시간 초과
- vector를 사용하여 모든 노드를 검사하지 않고 , 1인 노드만 검사합니다.
- 이 또한 시간이 많이 걸리지 않지만 문제에서 test_Case의 개수를 매우 tight하게 준 듯 합니다.
- sort부분의 적은 시간 조차 허용하지 않는듯?

2. 어려웠던 부분
- 시간복잡도 -> 문제에서 복잡도를 구할 수 없는 문제일 때 다른 문제가 나오면 고려.
*/

int arr[1001][1001];
pair<int,int> path[4] = {{-1,0},{0,1},{1,0},{0,-1}};
vector<int> row_vec;
vector<int> col_vec;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	
    int test_case,flag=0;
    string str;
    cin >> test_case;
    for(int i=0; i<test_case;i++)
    {
        cin >> str;
        memset(arr,0,sizeof(arr));
        flag = 0;
        int row=500 , col=500; 
        int min_x=500, min_y=500 , max_x =500 , max_y=500;      

        for(auto j: str)
        {
            if(j=='F')
            {    
                row += path[flag].first;
                col += path[flag].second;
                min_x = min(min_x , row);
                min_y = min(min_y , col);
                max_x = max(max_x , row);
                max_y = max(max_y , col);
            }
            else if(j=='B')
            {
                row -= path[flag].first;
                col -= path[flag].second; 
                min_x = min(min_x , row);
                min_y = min(min_y , col);
                max_x = max(max_x , row);
                max_y = max(max_y , col);                            
            }
            else if(j=='L')
            {                
                if(flag!=0)
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
                if(flag!=3)
                {
                    flag++;
                }
                else
                {
                    flag = 0;
                }                
            }
        }   
        cout << (max_x-min_x) * (max_y - min_y) <<"\n";  
    }

	return 0;
}


