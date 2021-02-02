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

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    string str;
    getline(cin , str);
    
    int cnt = 0;    
    if(str.size() == 1 && str[0] == ' ')
    {
        cout << 0;
        return 0;
    }
    for(int i = 0; i<str.size(); i++)
    {
        if(str[i] == ' ' && i==0)
        {
            continue;
        }
        if(str[i] == ' ' && i==str.size()-1)
        {
            continue;
        }
        if(str[i] == ' ')
        {
            cnt++;
        }        
    }

    cout << cnt+1;
	return 0;
}


