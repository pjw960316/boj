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
int n,tree_cnt,year;
pair<int,vector<int>> arr[12][12];
int winter_plus[12][12];
pair<int,int> path[8] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

void SpringAndSummer()
{
    int age , tree_to_energy;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {                    
            tree_to_energy = 0;   
            if(arr[i][j].second.empty() == true)
            {
                continue;
            }            
            sort(arr[i][j].second.begin() , arr[i][j].second.end()); //정렬은 여기서만 하면 충분
            for(int k=0; k<arr[i][j].second.size(); k++)
            {                
                age = arr[i][j].second[k];
                if(arr[i][j].first >= age)
                {
                    arr[i][j].first -= age;
                    arr[i][j].second[k] += 1; //ERROR_1 : age += 1 했었음.
                }
                else
                {                    
                    for(int l=arr[i][j].second.size()-1; l >= k; l--)//엄청난 ERROR_2 : l은 auto type이었는데 출력해보니까 이상해서 int로 바꿈
                    {
                        tree_to_energy += (arr[i][j].second[l])/2;
                        arr[i][j].second.pop_back();                     
                    }                    
                    arr[i][j].first += tree_to_energy; 
                    //k=arr[i][j].second.size(); 위에서 pop_back()을 하고 계산하므로 예상치 못한 결과
                    break; 
                }                
            }            
        }
    }   
}

void Fall()
{
    int next_r , next_c;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(auto k : arr[i][j].second)
            {
                if(k%5 == 0 && k != 0)
                {
                    for(int l=0; l<8; l++)
                    {                        
                        next_r = i+path[l].first;
                        next_c = i+path[l].second;
                        arr[next_r][next_c].second.push_back(1);
                    }
                }
            }
        }
    }
}

void Winter()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            arr[i][j].first += winter_plus[i][j];
        }
    }
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    int x,y,z;
    cin >> n >> tree_cnt >> year;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            arr[i][j].first = 5;
            cin >> winter_plus[i][j];
        }
    }
    for(int i=0; i<tree_cnt; i++)
    {
        cin >> x >> y >> z;
        arr[x][y].second.push_back(z);
    }
    for(int i=0; i<year; i++)//연도
    {
        SpringAndSummer();        
        Fall();
        Winter();
    }
    int answer = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(arr[i][j].second.empty() == true)
            {
                continue;
            }
            else
            {
                answer += arr[i][j].second.size();
            }            
        }
    }
    cout << answer;
	return 0;
}


