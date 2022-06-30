import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class _11279 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        //StringBuilder result = new StringBuilder();

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        int N = Integer.parseInt(st.nextToken());
        int input;

        for(int i = 0; i < N; i++){
            input = Integer.parseInt(st.nextToken());
            if(input == 0){
                if(pq.isEmpty())
                    System.out.println(0);
                else {
                    pq.peek();
                    cout << heap.top() << "\n";
                    heap.pop();
                }
            }
            else {
                heap.push(input[i]);
            }
        }
        
    }
}
