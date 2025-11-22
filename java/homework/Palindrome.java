import java.util.Scanner;

public class Palindrome {

    public static void main(String[] args) {
        String s;
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter string: ");
        s = scanner.nextLine();

        int len = s.length();
        boolean isPalindrome = true;


        for (int i = 0; i < len / 2; i++) {
            if (s.charAt(i) != s.charAt(len - 1 - i)) {
                isPalindrome = false;
                break;
            }
        }

        if (isPalindrome) {
            System.out.println("It is a palindrome");
        } else {
            System.out.println("Not a palindrome"); // Fixed typo
        }

        scanner.close();
    }
}
