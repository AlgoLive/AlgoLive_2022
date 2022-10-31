#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long sum(vector<int> queue, long long start){
    long long result = 0;
    
    for(int i = start; i < queue.size(); i++)
        result += queue[i];
    
    return result;
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    int size = queue1.size();
    
    if ((sum(queue1,0) + sum(queue2,0)) % 2 != 0)
        return -1;
    
    int tail = 0;
    int head = 0;
    int count = 0;
    
    while(sum(queue1, tail) != sum(queue2, head)){
        if(sum(queue1, tail) < sum(queue2, head)){
            int temp;
            temp = queue2[head++];
            queue1.push_back(temp);
        }
        else if(sum(queue1, tail) > sum(queue2, head)){
            int temp;
            temp = queue1[tail++];
            queue2.push_back(temp);
        }
            
        if(head + size == tail){
            count = -1;
            break;
        }
            
        count++;
    }
    
    
    return count;
}

