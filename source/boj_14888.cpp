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
1) 연산자를 조합해서 사용하는 모든 경우를 구합니다.
- 벡터를 사용해서 모든 조합을 구했으나
좋은 풀이에서는 벡터를 사용하지 않고 배열에서 가감하여 해결
2) 모든 경우에 대해 연산을 수행하고 최대 최소 구함.

2. 어려웠던 부분
1) visited개념 
- 모든 조건의 경우가 각각의 원소는 다르다는 조건을 위해 visited 가 필요함
2) dfs()의 initial node에 대한 depth_0와 depth_1
- 이 과정의 정립이 필요하기에 노트에 필기를 따로 했습니다.

3. 좋은 풀이
https://cryptosalamander.tistory.com/60
*/

int n;
int number[13];
int index_oper[13];
int answer_max = -2100000000; // ERROR : 0으로 했음.
int answer_min = 2100000000;
vector<char> v;

void Calculate()
{
    int cur = number[0];
    int index;
    for(int i=1; i<n; i++)
    {
        index = index_oper[i];
        if(v[index] == '+')
        {
            cur += number[i];
        }
        else if(v[index] == '-')
        {
            cur -= number[i];
        }
        else if(v[index] == '*')
        {
            cur *= number[i];
        }
        else if(v[index] == '/')
        {
            cur /= number[i];
        }
    }
    answer_max = max(answer_max , cur);
    answer_min = min(answer_min , cur);
}

void DfsOper(int depth)
{        
    bool is_visited;
    for(int i=0; i<v.size(); i++)
    {
        is_visited = false;
        for(int j=0; j<depth; j++)
        {
            if(index_oper[j] == i)
            {
                is_visited = true;
                break;
            }
        }
        if(is_visited == false)
        {
            index_oper[depth] = i;
            if(depth==n-1)
            {   
                Calculate();
                return;
            }
            DfsOper(depth+1);
        }
    }       
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    int num;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> number[i];
    }
    for(int i=0; i<4; i++)
    {
        cin >>num;
        for(int j=0; j<num; j++)
        {
            if(i==0)
            {
                v.push_back('+');
            }
            else if(i==1)
            {
                v.push_back('-');
            }
            else if(i==2)
            {
                v.push_back('*');
            }
            else if(i==3)
            {
                v.push_back('/');
            }
        }
    }
    memset(index_oper , -1 , sizeof(index_oper));
    DfsOper(1);
    cout << answer_max << "\n" << answer_min;

	return 0;
}


