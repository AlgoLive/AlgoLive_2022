/**
 * @file 2110.cpp
 * @author euije (exitfill1234@naver.com)
 * @brief 이분 탐색을 언제 써야할까????
 * @version 0.1
 * @date 2022-10-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int C;
vector<int> position;

int getCount(int mid)
{
    int count = 1;

    int last = position[0];
    for (int i = 1; i < N; i++)
    {
        if (position[i] - last >= mid)
        {
            count++;
            last = position[i];
        }
    }

    return count;
}

int solution()
{
    int left = 1;
    int right = position[N - 1] - position[0] + 1; // 이해 안돼...
    int mid;
    int count;

    // left와 right가 같으면 탈출
    while (left < right)
    {
        mid = (left + right) / 2;
        count = getCount(mid);
        // cout << "left : " << left << " right : " << right << "mid : " << mid << "count : " << count << '\n';
        if(count < C){
            // 설치할 수 있는 공유기의 갯수가 작으면
            // 거리를 줄여 공유기의 갯수를 늘려본다
            right = mid;
        }
        else if(count >= C){
            // on the other way
            // plus, 같아도 거리를 늘려본다.
            left = mid + 1;
        }
    }

    return left - 1; // Upper Bound ??? help me,,
}

int main()
{
    ios::sync_with_stdio(true);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> C;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        position.push_back(x);
    }

    sort(position.begin(), position.end());

    cout << solution();

    return 0;
}