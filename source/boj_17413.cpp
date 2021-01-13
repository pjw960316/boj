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
- 스택과 큐를 사용하여 경우를 나누어서 해결합니다.

2. 어려웠던 부분

1) 아스키코드의 공백문자를 ' '로 인식하는지 헷갈림. 0x20

2) 공백포함 문자열 받기
*/

stack<char> s;
queue<char> q;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    bool is_tag = false;
    string str;
    getline(cin,str);
    int index=0;
  
    for(auto i : str)
    {        
        if(is_tag == true)
        {
            if(i == '>')
            {
                q.push(i);
                while(q.empty() == false)
                {
                    cout << q.front();
                    q.pop();
                }
                is_tag = false; 
            }
            else
            {
                q.push(i);
            }            
        }
        else
        {
            if(i == '<')
            {
                while(s.empty() == false)
                {                   
                    cout << s.top();
                    s.pop();
                }               
                is_tag = true;
                q.push(i);
            }
            else if(i == ' ')
            {                                  
                while(s.empty() == false)
                {                   
                    cout << s.top();
                    s.pop();
                }
                cout << " ";
            }
            else if(index == str.size()-1) // end_point
            {           
                s.push(i);        
                while(s.empty() == false)
                {
                    cout << s.top();
                    s.pop();
                }                
                return 0;
            }
            else
            {  
                s.push(i);
            }            
        }      
        index++; 
    }
	return 0;
}


