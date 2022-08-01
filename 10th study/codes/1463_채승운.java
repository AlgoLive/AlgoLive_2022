import java.util.*;

public class Main {
	public static int[] DP;
	public static int N;

	public static int sol(int N) {
		   DP[1] = 0;
		   DP[2] = 1;
		   DP[3] = 1; // 기본 사항 설정
		   
		   for(int i=4; i<=N; i++) {
	        	if(i%2==0 && i%3==0) {
	        		DP[i] = Math.min(DP[i/3], DP[i/2])+1;
	        		// 6으로 나누어떨어지는 경우, 3으로 나눈경우 vs 2으로 나눈경우를 비교한다.
	        	} else if (i%3==0) {	        		
	        		DP[i] = Math.min(DP[i-1], DP[i/3])+1; 
	        		// 3으로 나누어떨어지는 경우, 3으로 나눈경우 vs 직전 경우를 비교한다.
	        	} else if(i%2==0) {
	        		DP[i] = Math.min(DP[i-1], DP[i/2])+1;
	        		// 2로 나누어떨어지는 경우, 2로 나눈경우 vs 직전 경우를 비교한다.
	        	} else {
	        		DP[i] = DP[i-1] + 1;
	        		// 2/3/6으로 모두 나누어지지 않는 경우(7, 11 등)는 직전 수에서 가져온다.
	        	}	        	
	        }
		   return DP[N];
	}
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        DP = new int[1000001]; // 연산 횟수를 담을 배열
         
        System.out.println(sol(N)); // 함수 호출
    }   
}
