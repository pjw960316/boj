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
    //int* arr = (int*)malloc(sizeof(int) * 10);
    int* arr = new int[10];
    for(int i=0 ; i<10; i++)
    {
        arr[i] = i+10;
        cout << arr[i] << " ";
    }
    
    pair<int,int>* arr2 = new pair<int,int>[10];
    for(int i=0; i<10; i++)
    {
        arr2[i].first = i+10;
        arr2[i].second = i+20;
        cout << arr2[i].first << "/" << arr2[i].second << " ";    
    }
    delete[] arr2;

    
}


