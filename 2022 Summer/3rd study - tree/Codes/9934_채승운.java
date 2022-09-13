import java.util.*;
import java.math.*;

public class Main {
	static int height;
	static int[] tree;
	static StringBuilder[] SB;
	
	public static void findtree(int start, int end, int level) {	
		if(level == height) {
			return;
		} // 재귀의 규칙: 종료 조건을 설정해야 한다.
		int center = (start+end)/2;
		SB[level].append(tree[center]+ " ");
		
		findtree(start, center-1, level+1); // 이분 탐색처럼 생각하면 된다.
		findtree(center+1, end, level+1);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		height = sc.nextInt();
		SB = new StringBuilder[height];
		for(int i=0; i<height; i++) {
			SB[i] = new StringBuilder();
		}
		// 상근이는 중위 순회의 규칙을 유지하면서 움직인다.
		int range = (int)Math.pow(2, height)-1;
		tree = new int[range];	
		for(int i=0; i<range; i++) {
			tree[i] = sc.nextInt();
		}
		
		findtree(0, tree.length-1, 0);
		
		for(int i=0; i<height; i++) {
			System.out.println(SB[i].toString());
		}
	}
}