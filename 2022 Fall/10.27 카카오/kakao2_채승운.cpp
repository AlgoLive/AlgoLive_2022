#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int sizes = queue2.size();
    int count = 0;
    long long sum1 = 0;
    long long sum2 = 0;
    int index1 = 0;
    int index2 = 0;
    sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    sum2 = accumulate(queue2.begin(), queue2.end(), 0);
    
    if((sum1 + sum2) % 2 != 0) // 전체 합이 홀수면 무조건 실패
        return -1;
    while(count <= 4 * sizes){
      if(sum1 < sum2) { // 오른쪽 큐에서 왼쪽으로 값을 줘야 함.
          sum2 -= queue2[index2];
          sum1 += queue2[index2];
          queue1.push_back(queue2[index2++]); // 큐를 직접 옮기면 시간초과
          count++;
      } else if(sum1 > sum2) { // 왼쪽 큐에서 오른쪽으로 값을 줘야 함.
          sum1 -= queue1[index1];
          sum2 += queue1[index1];
          queue2.push_back(queue1[index1++]); // 큐를 직접 옮기면 시간초과, 인덱스를 옮겨서 대신 표현하자.
          count++;
      } else return count;
    }
    return -1;
}