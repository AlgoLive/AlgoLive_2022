import java.util.*;

class Node implements Comparable<Node> {

    public int index;
    public int distance;

    public Node(int index, int distance) {
        this.index = index;
        this.distance = distance;
    }

    @Override
    public int compareTo(Node other) { // 최소힙(오름차순 정렬)을 위한 오버라이딩
       return this.distance - other.distance;
    }
}

public class Main {
    public static final int INF = 100000000; // 무한을 의미하는 값으로 10억을 설정
    // 노드/간선 개수(M), 시작 노드 지정(Start)
    public static int V, E, start;
    // 각 노드에 연결되어 있는 노드에 대해 다루는 인접리스트
    public static ArrayList<ArrayList<Node>> graph = new ArrayList<ArrayList<Node>>();
    // 최단 거리 배열, 개수는 V개의 최대개수
    public static int[] d = new int[20001];

    public static void dijkstra(int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start, 0));
        // 시작 노드니까 당연히 최단경로 0으로 설정
        d[start] = 0; // 당연히 자기자신과의 거리는 0
        
        while(!pq.isEmpty()) { // 큐가 비어있지 않다면
            Node node = pq.poll();
            
            int dist = node.distance; // 현재 노드까지의 비용 
            int now = node.index; // 현재 노드
            
            if (d[now] < dist) continue;
            // 원래 d는 무한대, 그러므로 이 조건문은 d[now]에 간선이 도달하지 않았다면 절대 성립할 수 없음.
            // 즉 다시 말해, 간선이 도달했다면 d가 무한대가 아니기 때문에 위 조건문이 발현, 즉 "이 노드 방문하였다"를 의미함.
            
       
            for (int i = 0; i < graph.get(now).size(); i++) { // 현재 노드 주변 연결된 노드들을 순회
            	
                int cost = d[now] + graph.get(now).get(i).distance;
                
                // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우 갱신하고 큐에 담음.
                if (cost < d[graph.get(now).get(i).index]) {
                    d[graph.get(now).get(i).index] = cost;
                    pq.offer(new Node(graph.get(now).get(i).index, cost));
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        V = sc.nextInt();
        E = sc.nextInt();
        start = sc.nextInt();

        // 그래프 정점(V) 초기화
        for (int i = 0; i <= V; i++) {
            graph.add(new ArrayList<Node>());
        }
        
        // 모든 간선(E개) 정보를 입력받기
        for (int i = 0; i < E; i++) {
            int begin = sc.nextInt();
            int end = sc.nextInt();
            int value = sc.nextInt();
            // begin 노드에서 end 노드로 가는 비용이 value라는 의미 (인접 리스트)
            graph.get(begin).add(new Node(end, value));
        }

        // 최단 거리 테이블을 모두 무한으로 초기화해둠 (도착할 수 없는 노드면 INF상태로 남아 있을 것임)
        Arrays.fill(d, INF);
        
        // 다익스트라 실행
        dijkstra(start);

        for (int i = 1; i <= V; i++) {
            if(d[i] == INF) { // 도달할 수 없는 노드
            	System.out.println("INF");
            } else { // INF가 아니라면 어찌됐든 최단거리가 계산되었다는 의미
            	System.out.println(d[i]);
            }
        } 
    }
}