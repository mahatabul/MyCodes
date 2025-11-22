
import java.util.Arrays;


public class Array {

    public static void main(String[] args) {
        int[] array = {1, 6, 3, 6, 2};


        System.out.println(Arrays.toString(array));

        array = Arrays.stream(array).sorted().toArray();

        for (int i = 0; i < array.length - 1; i++) {
            if (array[i] == array[i + 1]) {
                System.out.println(array[i]);
            }
        }

    }
}