#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int _queue1[1200001];
int _queue2[1200001];
int size1;
int size2;

long long sum(int* q, int size, int start){
    long long result = 0;
    
    for(int i = start; i < size; i++)
        result += q[i];
    
    return result;
}

int solution(vector<int> queue1, vector<int> queue2)
{
    int answer = -2;

    size1 = queue1.size();
    size2 = size1;

    for(int i = 0; i < size1; i++)
        _queue1[i] = queue1[i];
    
    for(int i = 0; i < size2; i++)
        _queue2[i] = queue2[i];


    if ((sum(_queue1, size1, 0) + sum(_queue2, size2, 0)) % 2 != 0)
        return -1;

    int tail = 0; // for queue1
    int head = 0; // for queue2
    int count = 0;

    while (sum(_queue1, size1, tail) != sum(_queue2, size2, head))
    {
        if (sum(_queue1, size1, tail) < sum(_queue2, size2, head))
        {
            int temp;
            temp = _queue2[head++];
            _queue1[size1++] = temp;
        }
        else if (sum(_queue1, size1, tail) > sum(_queue2, size2, head))
        {
            int temp;
            temp = _queue1[tail++];
            _queue2[size2++] = temp;
        }

        if (count >= queue1.size() * 4)
            return -1;

        count++;
    }

    return count;
}
