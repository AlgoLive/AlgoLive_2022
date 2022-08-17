import java.util.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.*;
import java.math.*;

public class Main {
		
	public static void main(String[] args) throws Exception {	
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		PriorityQueue<int[]> q = new PriorityQueue<>(new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				// TODO Auto-generated method stub
				if(o1[0] == o2[0]) {
					return o1[1]-o2[1];
				}
				return o1[0]-o2[0];
			}
		});
		
		while(N!=0) {
			int input = sc.nextInt();
			if(input == 0) {
				if(q.peek() == null) {
					System.out.println(0);
				} else {
					System.out.println(q.poll()[1]);
				}
			} else {
				q.add(new int[] {Math.abs(input), input});	
			}
			N--;
		}
	}
}