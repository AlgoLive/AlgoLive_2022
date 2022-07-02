import java.util.PriorityQueue;
import java.util.Scanner;
import java.lang.Math;

class Main{
    public static void main(String[] args) {
        int N, input;
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>((o1, o2) -> {
            if(Math.abs(o1) < Math.abs(o2)){
                return -1;
            }else if(Math.abs(o1) > Math.abs(o2)){
                return 1;
            }
            if(o1 < o2){
                return -1;
            }else if(o1 > o2){
                return 1;
            }
            return 0;
        });
        for(int i = 0 ; i < N ; i++){
            input = scanner.nextInt();
            if(input == 0){
                if(priorityQueue.isEmpty()){
                    System.out.println(0);
                }else{
                    System.out.println(priorityQueue.poll());
                }
            }else{
                priorityQueue.add(input);
            }
        }

    }
}