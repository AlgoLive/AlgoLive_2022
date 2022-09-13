import java.util.*;
import java.io.*;

public class Main {
	public static int N, M, V, count;
	public static boolean[] visited;
	public static int[][] arr;
	public static int result;
	
	public static void BFS() {
		
		// 문제: 1번이 감염되었을 때 1번한테 바이러스 옮는 컴퓨터의 수는?
		
		Queue<Integer> q = new LinkedList<Integer>();
		q.offer(V);
		visited[V] = true; // V값, 즉 1번에서 출발하므로 true
		
		while(q.size()!=0) { // 큐가 0이 된다 = 더 이상 바이러스에 걸릴 컴퓨터가 없다. 
			int temp = q.poll(); // 큐에서 뽑힌 위치에서 바이러스 확산 시도
			
			for(int j=1; j<=N; j++) {
				if(arr[temp][j]==1 && !visited[j]) {
					// 두 컴퓨터가 연결되어 있고 아직 서로 방문하지 않았다면 
					q.offer(j);
					visited[j] = true;
					result++;
					// 전염됨.
				}	
			}	
		}	
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		count = sc.nextInt();
		
		V = 1;
		arr = new int[101][101];
		visited = new boolean[101];
		
		for(int i=0; i<count; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			arr[a][b] = arr[b][a] = 1; // 서로 이어져있음을 의미하는 1 삽입
		}
		
		BFS();
		System.out.println(result);
	}
	
}