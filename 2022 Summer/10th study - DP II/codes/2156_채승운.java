import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);    
        int N = sc.nextInt();
        int[] v = new int[N+1];
        int[] dp = new int[N+1];
        // dp 배열의 의미는 N개 잔 중 포도주를 가장 많이 마실 수 있는 경우 계산되는 포도주의 양임.
        
        for(int i=1; i<=N; i++) {
        	v[i] = sc.nextInt(); 	
        }
        
        for(int i=1; i<=N; i++) {        	
        	if(i==1) {
        		dp[i] = v[i];
        		// 1인 경우: 첫번째 잔
        	}
        	if(i==2) {
        		dp[i] = dp[i-1] + v[i];
        		// 2인 경우: 첫번째 잔 + 두번째 잔
        	}     	
        	if(i>=3) {
        		dp[i] = Math.max(dp[i-1], Math.max(dp[i-3]+v[i]+v[i-1], dp[i-2]+v[i]));
        		// 총 3가지 경우 중 가장 큰 값을 저장함.
        		/*
        		 1. i번쨰 잔을 선택하지 않아도 최댓값이 튀어나오는 경우 dp[i-1]
        		 2. i번째 잔을 선택하고, i-1번째 잔도 선택하며, i-3번째 최댓값을 가져오는 경우 
        		 3. i번째 잔을 선택하고, i-2번째 최댓값을 확보하는 경우
        		 
        		 3을 예로 들어
        		 1-3(세번째 인자) / 1-2(첫번째 인자) / 2-3(두번째 인자) 으로 선택할 수 있음.
        		 */
        	}	    	       	
        }               
        System.out.println(dp[N]);
    } 
}