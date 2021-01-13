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
- 문제 자체는 매우 쉬우나 , 구현 과정에서 잔실수로 오래걸렸습니다.
1) 모든 팀 구성 조합 만들기 20C10 : 18만
2) 조합들마다의 합 능력치 차이를 갱신 : 100개+20개+20개 : 140개
시간복잡도 : 18만 * 140 < 1억

2. 어려웠던 부분
1) 시간복잡도
- 20C10은 당연히 엄청 큰 수라 생각했음
- MakeTeamA()에서 i=team_member_cnt-1 대신에
i=1부터 계산하여 온전히 18만개를 계산하면 시간초과가 나옵니다. -> 이거 중요

2) 재귀식에서는 자료구조의 초기화를 유심히 보아야 합니다.

3) int arr[10] = {1,2,3,4,5,6,7,8,9,10} 에서
값이 3 , 5 , 8인 원소를 제거한 배열 구하기를 정립해야 합니다.

4) 예전에는 백트래킹 문제에서 반드시 bool promising()을 만들었지만
간단한 promising은 만들지 않는 것이 가독성에 좋습니다.
*/

int arr[22][22];
int team_a[11];
int team_b[11];
int n,team_a_power,team_b_power;
int answer = 2000000000;

void SubTwoTeam();

void MakeTeamA(int team_member_cnt)
{
    if(team_member_cnt == n/2)
    {
        for(int i=team_a[team_member_cnt-1]+1; i<=n; i++)
        {           
            team_a[team_member_cnt] = i;
            SubTwoTeam();  
        }
        return;         
    }
    for(int i=team_a[team_member_cnt-1]+1; i<=n; i++)
    {       
        team_a[team_member_cnt] = i;
        MakeTeamA(team_member_cnt+1);     
    }
}

void SubTwoTeam()
{
    //애시당초 MakeTeamA()에서 조건에 맞지 않으면 SubTwoTeam()을 호출하지도 않음.
    /*for(int i=1; i<= n/2; i++)
    {
        if(team_a[i] == 0)
        {
            return;
        }
    }*/  
    
    //team에서 team_a의 수를 빼는 건데 이 부분을 좀 공부해서 정형화 시키자. L81 ~ L98
    int team[22];
    memset(team , -1 , sizeof(team));
    memset(team_b , -1 , sizeof(team_b)); // ERROR_1 : 계속 초기화 해주어야 함.
    team_a_power = 0; team_b_power = 0;
    int index = 1;
     
    for(int i=1; i<=n; i++)
    {
        team[team_a[i]] = 1;
    }
    for(int i=1; i<=n; i++)
    {
        if(team[i] == -1)
        {
            team_b[index] = i;
            index++; // ERROR_2 : 이걸 if 밖에 써서 계속 답이 나오지 않음.
        }        
    }
  
    for(int i=1; i<=n/2; i++)
    {
        for(int j=1; j<=n/2; j++)
        {
            if(i!=j)
            {
                team_a_power += arr[team_a[i]][team_a[j]];
                team_b_power += arr[team_b[i]][team_b[j]];
            }
        }
    }
    answer = min(answer , abs(team_a_power - team_b_power));
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> arr[i][j];
        }
    }
    memset(team_a , 0 , sizeof(team_a));
    memset(team_b , 0 , sizeof(team_b));
    MakeTeamA(1);
    cout << answer;

	return 0;
}


