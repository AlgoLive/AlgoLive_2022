import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  
	    int n = sc.nextInt();
	    int m = sc.nextInt();
        
	    int[][] arr = new int[n+1][m+1];
	    int max = 0;
	    	    
	    for(int i=1; i<=n; i++)
	    {
	    	char[] str = sc.next().toCharArray();
	    	for(int j=1; j<=m; j++) {
	    		arr[i][j] = str[j-1] - '0';
	    		
				// 가장 큰 정사각형은, 현재 위치 기준 왼쪽, 위, 왼쪽위 대각선에 해당하는 수 중 가장 작은 수에 하나 더한 값이 된다.
				// max를 통해 가장 큰 정사각형을 갱신한다.

	    		if(arr[i][j] != 0) {
	    			arr[i][j] = Math.min(arr[i-1][j-1], Math.min(arr[i][j-1],  arr[i-1][j])) + 1;
	    			max = Math.max(max, arr[i][j]);
	    		}
	    	}
	    }
	    System.out.println(max * max);
    } 
}