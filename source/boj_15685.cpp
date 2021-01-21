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
1) 드래곤 커브의 규칙을 스택의 개념을 활용해서 해결합니다.

2) 모든 드래곤 커브를 그리고 네모 모양을 찾습니다.

2. 어려웠던 부분

1) 카트라이더 대마왕
- x와 y 헷갈리는데 언제나 r과 c로 씁시다.

2) 익숙함의 단점
- 방향 변경이 0->3 , 3->2가 익숙해서 0->1 , 1->2인 것을 찾지 못해서
오랜 시간 소요.

*/

int dragon_curve[102][102];
int arr[102][102];
vector<int> v;
pair<int,int> path[4] = {{0,1},{-1,0},{0,-1},{1,0}};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

    int next_r , next_c;
	int test_case , cur_r , cur_c, d , g;
    cin >> test_case;
    for(int i=0; i<test_case; i++)
    {
        cin >> cur_c >> cur_r >> d >> g; //ERROR              
        dragon_curve[cur_r][cur_c] = 1;
        v.push_back(d);       
        cur_r += path[d].first;
        cur_c += path[d].second;
        dragon_curve[cur_r][cur_c] = 1;
        
        //0일 때
        if(g==0)
        {
            v.clear();
            continue;
        }
        
        //1부터
        //스택의 개념을 사용하지만 스택은 빼야 하므로 vector에서 스택이용
        int end_path;
        for(int j=1;j<=g;j++)
        {
            int cur_max_v_length = v.size()-1;
            for(int k=0; k<pow(2,j-1); k++)
            {
                end_path = v[cur_max_v_length-k];    
                v.push_back((end_path+1)%4);              
                cur_r += path[(end_path+1)%4].first;
                cur_c += path[(end_path+1)%4].second;
                dragon_curve[cur_r][cur_c] = 1;
            }
        }        
        v.clear();
    }
    int sum=0;
    for(int i=0; i<=100; i++)
    {
        for(int j=0; j<=100; j++)
        {
            if(dragon_curve[i][j] == 1 && dragon_curve[i+1][j] == 1 && dragon_curve[i][j+1] == 1 && dragon_curve[i+1][j+1] == 1)
            {
                sum++;
            }
        }
    }
    
    cout << sum;
	return 0;
}


