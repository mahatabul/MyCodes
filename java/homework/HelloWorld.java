public class HelloWorld {

    public void greet(int x) {
        System.out.println("Starting greet method");

        if (x > 0) {
            System.out.println("x is positive");
        } else {
            System.out.println("x is zero or negative");
        }

        System.out.println("Looping with for-loop:");
        for (int i = 0; i < x; i++) {
            System.out.println("i = " + i);
        }

        int y = x;
        System.out.println("Looping with while-loop:");
        while (y > 0) {
            System.out.println("y = " + y);
            y--;
        }

        System.out.println("Ending greet method");
    }

    public int add(int a, int b) {
        return a + b;
    }

    public static void main(String[] args) {
        HelloWorld hw = new HelloWorld();
        hw.greet(3);
        System.out.println("Sum: " + hw.add(5, 7));
    }
}

