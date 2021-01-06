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

list<int> l;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    l.push_back(3);
    l.push_back(2);
    l.push_back(5);
    l.push_back(4);
    l.remove(2);
    for(auto i : l)
    {
        cout << i;
    }
    
	return 0;
}


