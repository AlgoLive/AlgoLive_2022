import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

// https://m.blog.naver.com/ka28/221850826909
// https://docs.oracle.com/javase/7/docs/api/java/util/PriorityQueue.html
// https://coding-factory.tistory.com/603

public class _11279 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder result = new StringBuilder();

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        int N = Integer.parseInt(st.nextToken());
        int input;

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            input = Integer.parseInt(st.nextToken());

            if(input == 0){
                if(pq.isEmpty())
                    result.append(String.valueOf(0) + "\n");
                else {
                    result.append(String.valueOf(pq.poll()) + "\n");
                }
            }
            else {
                pq.add(input);
            }
        }

        bw.write(result.toString());
        bw.close();
        br.close();
    }
}
