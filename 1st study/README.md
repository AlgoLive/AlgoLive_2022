# 1회차

## ❤️‍🔥 추상 자료형, ADT

> 어떤 동작이 있는지 까지만 정의하고 구현

```
Data - Power, LeftButton, RightButton
Operation - PowerOn(), PowerOff(), leftButtonClick(), RightButtonClick()
```

- 왜 필요한가?
  - 구현자와 사용자 분리
  - 사용자는 내부 구현에 대해 알 필요가 없다.
  - 추상 자료형의 구현은 외부로 부터 숨겨짐 : `정보 은닉`

## ❤️‍🔥 Stack

- Last In, First Out
- 마지막에 들어간 데이터가 나올 때 처음으로 나오는 Data Structure

- 언제 필요한가?
  - 수직적으로 쌓이는 Stack 형 상황일 때
    - 후위 표기법 계산
    - 문자열 역행
    - 실행 취소
    - 웹 브라우저 뒤로가기 등

- `Java`
    ```Java
    Stack<Integer> stack = new Stack<>();
    stack.push(1);
    stack.push(3);
    System.out.println(stack.isEmpty());
    System.out.println(stack.size());
    System.out.println(stack.pop());
    stack.pop();
    System.out.println(stack.isEmpty());
    ```

## ❤️‍🔥 Queue

- First In, First Out
- 먼저 들어간 데이터가 먼저나오는 Data Structure

- 언제 필요한가?
  - 먼저 요청된 작업이 먼저 처리되어야 하는 상황에서
    - 은행 업무
    - 대기열 순서
    - 서비스 센터의 대기시간
    - 프로세스 관리 등

- `Java`
    ``` Java
    Queue<String> queue = new LinkedList<>();
    queue.add("우리 좀");
    queue.add("알고 삽시다");
    System.out.println(queue.remove());
    System.out.println(queue.isEmpty());
    queue.remove();
    System.out.println(queue.size());
    ```

---

|💖오늘의 예제|문제 번호|난이도|링크|
|:-:|:-:|-|-|
|___<괄호>___|_#9012_|![실버 4](https://camo.githubusercontent.com/64671b5a244ad70dc11665f1293bdde51747df3d9cd4bfe2c36b1e5e1a78872b/68747470733a2f2f7374617469632e736f6c7665642e61632f746965725f736d616c6c2f372e737667)|[문제](https://www.acmicpc.net/problem/9012)|
|___<요세푸스 문제>___|_#1158_|![실버 4](https://camo.githubusercontent.com/64671b5a244ad70dc11665f1293bdde51747df3d9cd4bfe2c36b1e5e1a78872b/68747470733a2f2f7374617469632e736f6c7665642e61632f746965725f736d616c6c2f372e737667)|[문제](https://www.acmicpc.net/problem/1158)|

## 💕 문제

### <괄호>, #9012

### <요세푸스 문제>, #1158

