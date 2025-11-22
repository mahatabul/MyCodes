import java.time.YearMonth;
import java.util.Scanner;

public class Month {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String arr[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September",
                "October", "November", "December" };

        int month, year;
        System.out.print("Enter Month Num:");
        month = scanner.nextInt();
        System.out.print("Enter Year Num:");
        year = scanner.nextInt();

        scanner.close();

        if (month <= 0 || month > 12) {
            System.out.println("Invalid Month.");
            return;
        }

        YearMonth y = YearMonth.of(year,month);


        int daysInMonth = y.lengthOfMonth();
        System.out.println(arr[month - 1] + " " + year + " has " + daysInMonth + " Days");
    }

    private static int cal(int year, int month) {
        switch (month) {
            case 2:
                if (isLeapYear(year)) {
                    return 29;
                } else {
                    return 28;
                }
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            default:
                return 31;
        }
    }

    private static boolean isLeapYear(int year) {

        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
}