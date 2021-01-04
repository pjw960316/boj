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
1) 개미 그룹 합치기
- 두 개미 그룹을 하나의 string으로 만들어 줍니다.
2) string flag
- string에 flag를 추가하여 pair 형태로 만들고 
right와 left를 찾아서 바꿔줍니다.
- 단 , 해당 반복문에서 한 번 위치 변환한 개미는 다시 바꾸지 않도록 예외처리
2. 어려웠던 부분
1) pair 바꾸기
= pair도 일반 변수처럼 tmp로 값을 변경 할 수 있습니다.
2) string 정형화
= 아직도 string을 사용할 때 정형화 되지 않고 이런 저런 함수를 사용합니다.
= string을 언제나 vector처럼 사용합시다.
*/

int change[100];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

	int n1 , n2 , time_after=0;	
	cin >> n1 >> n2;
	char word;
	vector<pair<string,char>> str;	
	pair<string,char> tmp;	
	str.resize(n1+n2);

	//합친 개미 문자열 제조
	for(int i=n1-1; i>=0; i--)
	{
		cin >> word;
		str[i].first = word;
		str[i].second = 'r';
	}
	for(int i=n1; i<n1+n2; i++)
	{
		cin >> word;
		str[i].first = word;
		str[i].second = 'l';
	}
	cin >> time_after;

	//개미 위치 변경
	if(time_after == 0)
	{
		for(auto i : str)
		{
			cout << i.first;			
		}
		return 0;
	}
	for(int i=0; i<time_after; i++)
	{
		memset(change , 0 , sizeof(change));
		for(auto j=0; j<str.size()-1; j++)
		{
			//HARD : 한 번 점프한 개미 제외
			if(str[j].second == 'r' && str[j+1].second == 'l' && change[j] == 0 && change[j+1]==0)
			{
				tmp = str[j];
				str[j] = str[j+1];
				str[j+1] = tmp;
				change[j] = 1;
				change[j+1] = 1;
			}
		}
	}
	for(auto i : str)
	{
		cout << i.first;			
	}
	return 0;
}