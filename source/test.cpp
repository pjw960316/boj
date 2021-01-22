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
#include <windows.h>

using namespace std;

/*
1. 풀이 과정

2. 어려웠던 부분

*/

vector<int> v;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
    

    //1. 정상적인 포인터
    int a = 77;
    int *ptr = &a;
    printf("%d" , *ptr);
    
    //2. NULL-Pointer에서 발생하는 2가지 Segmentation Fault
    int *ptr_null; //same as int *nullptr = NULL;
    
        //1) 널 포인터에 어떤 값 할당하기.
        *ptr_null = 7;
        
        //2) 널 포인터가 가리키는(사실은 아무것도 가리키지 않음) 변수 값 출력. 
        printf("%d" , *ptr_null);
    
	return 0;
}


