import java.util.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.*;

class Node implements Comparable<Node> { // 인접리스트 클래스 Node
   int end, weight;

   public Node(int end, int weight) { // 간선의 도착 방향과 가중치를 확보
      this.end = end;
      this.weight = weight;
   }
   
   @Override
   public int compareTo(Node o) { // 비교 기능을 위한 인터페이스 도입
      return weight - o.weight;
   }
}

public class Main {
   static int V, E, K;
   static int[] dis;
   static List<Node>[] list; // 인접 리스트의 배열
   static final int INF = 100_000_000; // 매우 큰 수 표현 (두 정점이 만날 수 없는 경우)

   
   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      StringTokenizer st = new StringTokenizer(br.readLine());
      
      V = Integer.parseInt(st.nextToken());
      E = Integer.parseInt(st.nextToken());   
      K = Integer.parseInt(br.readLine());
      dis = new int[V+1];
      list = new ArrayList[V+1];
      Arrays.fill(dis, INF);   
      
      for(int i=1; i<=V; i++) {
         list[i] = new ArrayList<>(); // 리스트 배열 초기화
      }
      
      for(int i=1; i<=E; i++) {
         st = new StringTokenizer(br.readLine());
         int start = Integer.parseInt(st.nextToken()); // 간선의 방향 시작점
         int end = Integer.parseInt(st.nextToken()); // 간선의 방향 도착점
         int weight = Integer.parseInt(st.nextToken()); // 간선의 가중치
         list[start].add(new Node(end, weight));   // 리스트 안에 들어가는 것은? 특정 인덱스 정점에서 출발하는 간선들의 도착점과 가중치
      }
      StringBuilder sb = new StringBuilder();
      movegraff(K);   
      
      for(int i=1; i<=V; i++) {
         if(dis[i] == INF) {
            sb.append("INF\n");
         } else {
            sb.append(dis[i] + "\n");
         }
      }
      
      bw.write(sb.toString());
      bw.close();
      br.close();
   }
   
   public static void movegraff(int start) { // 다익스트라 알고리즘 개시
      // 이제 어떻게 처리해야 하는가?
      dis[start] = 0;
      PriorityQueue<Node> q = new PriorityQueue<Node>();
      boolean[] check = new boolean[V+1]; // 정점의 순회 여부를 따지기 위한 배열
      q.add(new Node(start, 0)); // 시작점 돌입
      while(!q.isEmpty()) {
         Node current = q.poll(); // 최초 상황은 start를 가리키는 그리고 0의 가중치를 가진 간선이라 가정
         int curend = current.end; // 다음 방향 설정을 위해 end를 확보
         
         if(check[curend]) continue; // 이미 순회했으면 이 노드의 시행은 이탈
         check[curend] = true;
         
         for(Node node: list[curend]) { // 현재 리스트에서 노드들을 순회하기 시작함
            if(dis[node.end] > dis[curend] + node.weight) {
               dis[node.end]= dis[curend] + node.weight;
               q.add(new Node(node.end, dis[node.end])); // 다음 순회를 위한 새로운 노드 삽입
            }
         }
         
      }   
   }
   
}