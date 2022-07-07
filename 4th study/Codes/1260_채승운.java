import java.util.*;
import java.io.*;

public class Main {
	public static int N, M, V;
	public static boolean[] visited;
	public static int[][] arr;
	
	public static void DFS(int V) {
		int w;
		visited[V] = true;
		System.out.print(V + " ");
		for(w=1; w<=N; w++) {
			if(arr[V][w]==1 && !visited[w]) { 
				// 이동할 수 있는 정점이 남아있다면 그곳으로 이동
				DFS(w);
			}
		}
	}
	
	public static void BFS() {
		
		Queue<Integer> q = new LinkedList<Integer>();
		q.offer(V);
		visited[V] = true;
		System.out.print(V + " ");
		
		while(q.size()!=0) {
			int temp = q.poll();
			
			for(int j=1; j<=N; j++) {
				if(arr[temp][j]==1 && !visited[j]) {
					q.offer(j);
					visited[j] = true;
					System.out.print(j + " ");
				}	
			}	
		}	
	}
	
	public static void main(String[] args) throws IOException {
		// 단순무식하게 BFS DFS 구현하는 가장 기초적인 문제
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		V = sc.nextInt();
		arr = new int[1001][1001];
		visited = new boolean[1001];
		
		for(int i=0; i<M; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			arr[a][b] = arr[b][a] = 1; // 바이러스 문제가 거의 동일함.
		}
		DFS(V);
		System.out.println();
		visited = new boolean[1001];
		
		BFS();
		
	}
	
}