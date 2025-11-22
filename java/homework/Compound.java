import java.util.Scanner;

public class Compound {
    public static void main(String[] args) {
        double principal,rate;
        
        int time;
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter Principal: ");
        principal = scan.nextDouble();
        System.out.print("Enter Rate: ");
        rate = scan.nextDouble();
        System.out.print("Enter time: ");
        time = scan.nextInt();

        rate = rate/100.0;
        rate+=1.0;

        rate = Math.pow(rate, time);

        double amount;
        amount = principal*rate;

        System.out.printf("Compund Interest= %f",amount-principal);
        // System.out.println(amount-principal);

        scan.close();


    }
}
