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
          queue1.push_back(queue2[index2++]); // 큐를 직접 옮기면 시간초과, "옮긴 것"처럼 보이도록 유도한다.
          /* 예를 들어 3 2 7 2 / 4 6 5 1이라고 하면,
             최초에는 14 vs 16이므로 4가 넘어가고(큐1 배열 끝에 4가 추가되고), 3 2 7 2 4 / 6 5 1에서 18 vs 12이므로 3이 넘어가고(큐2 배열 끝에 3이 추가되고),
             2 7 2 4 / 6 5 1 3에서 15 vs 15이므로 성립한다. 이때 이를 두 큐 사이에서 직접적으로 변화가 생기는 게 아니라, 
             그냥 새로운 인덱스의 변수가 배열 끝에 추가된다고 생각하자. 그렇지 않으면 erase의 시간복잡도인 o(n)에 의한 시간초과가 발생한다.
          */
          count++;
      } else if(sum1 > sum2) { // 왼쪽 큐에서 오른쪽으로 값을 줘야 함.
          sum1 -= queue1[index1];
          sum2 += queue1[index1];
          queue2.push_back(queue1[index1++]);
          count++;
      } else return count;
    }
    return -1;
}