import java.util.Scanner;

class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int k = input.nextInt();
        int[] cities = new int[(int)Math.pow(2,k)];
        for(int i = 0 ; i < Math.pow(2,k)-1; i++){
            cities[i] = input.nextInt();
        }

        int i = 0;
        for(int j = k ; j >0; j--){
            i = (int)Math.pow(2,j-1)-1;
            while(i< cities.length){
                System.out.print(cities[i]+" ");
                i+=Math.pow(2,(j));
            }
            System.out.println();

        }

    }
}