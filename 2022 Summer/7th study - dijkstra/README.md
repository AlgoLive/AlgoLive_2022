# Dijskra Algorithm
---

## (Normal) Dijskra Algorithm

  - [영어 예제](https://www.youtube.com/watch?v=EFg3u_E6eHU&ab_channel=SpanningTree)
  - [한국어 강의](https://youtu.be/acqm9mM1P6o)

  - [인접 행렬 코드](https://gist.github.com/euije/84b5155422e90f82ace14bf37787d34b)
  - [인접 리스트 코드](https://github.com/ndb796/python-for-coding-test/blob/master/9/1.cpp)
  
  - 인접 리스트의 이해
    <img width="1454" alt="스크린샷 2022-07-19 오후 1 38 22" src="https://user-images.githubusercontent.com/12531340/179673982-93f4a92c-361d-4f0b-b52c-b304e2886f31.png">


## Modified Dijskra Algorithm (with Priority Queue)

  - [영어 강의](https://youtu.be/CerlT7tTZfY)
  - [한국어 강의](https://youtu.be/acqm9mM1P6o?t=1315)

  - `if (d[now] < dist) continue;` Case
    - `d[now]` : 갱신이 안되었을 때, INF 값을 지님
    -  if문 내의 조건이 false （>)가 될 수 밖에 없음.
    - 'now' 노드가 처리 되었다면, true 가능.


### 자료구조 공부 시 참고 하면 좋을 사이트

- [Visualgo.net](https://visualgo.net/en)
  - 자료구조 / 알고리즘을 시각화(Visualization)하여 제공.