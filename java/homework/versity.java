import java.util.Scanner;

public class versity {
    public static void main(String[] args) {
        String str;
        System.out.print("Write:");
        Scanner scanner = new Scanner(System.in);
        str = scanner.nextLine();

        str = str.toLowerCase();
        int len = str.length();
        int vowel = 0;

        for (int i = 0; i < len; i++) {

            if (str.charAt(i) == 'a' || str.charAt(i) == 'e' || str.charAt(i) == 'i' || str.charAt(i) == 'o'
                    || str.charAt(i) == 'u') {
                vowel++;
            }

        }

        System.out.print("Total Character: ");
        System.out.println(str.length());
        System.out.print("Total Vowel: ");
        System.out.println(vowel);
        System.out.println("AFter converting uppercase to lowercase:");

        System.out.println(str);
        System.out.println("AFter converting Lowercase to uppercase:");
        str = str.toUpperCase();
        System.out.println(str);

    }
}
