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
1) 치킨집을 놓을 수 있는 모든 경우를 구합니다.
2) 모든 경우에 대해서 거리의 조합을 구합니다.

2. 어려웠던 부분
-조합에 대한 정석적인 최적화 코드를 구현하지 않아서 시간복잡도가 발생
지금까지 1부터 전체 탐색을 해도 문제가 없었던 적이 많았습니다.

*/
vector<pair<int,int>> v;
vector<pair<int,int>> house;
int arr[52][52];
pair<int,int> saved_chicken[15];
int n,m;
int answer = 99999999;

void Search(int saved_chicken_cnt)
{    
    int distance;
    int sum=0;     
    
    for(auto i : house)
    {
        distance = 99999999;
        for(int j=1; j<=saved_chicken_cnt; j++)
        {
            distance = min(distance , abs(i.first-saved_chicken[j].first) + abs(i.second-saved_chicken[j].second));
        }
        sum += distance;
    }
    answer = min(sum,answer);
}

void Dfs(int index , int depth)
{
    if(depth > m)
    {
        Search(m);
        return;
    }
    for(int i=index; i<v.size(); i++)//ERROR : index가 아닌 depth부터 탐색.
    {
        saved_chicken[depth].first = v[i].first;
        saved_chicken[depth].second = v[i].second;
        Dfs(i+1 , depth+1);        
    }
}   
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n >> m; 
    memset(arr,-1,sizeof(arr));
    memset(saved_chicken,-1,sizeof(saved_chicken));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(arr[i][j] == 1)
            {
                house.push_back({i,j});
            }
            if(arr[i][j] == 2)
            {
                v.push_back({i,j});                
            }
        }
    }    
    Dfs(0,1);
    cout << answer;
	return 0;
}


