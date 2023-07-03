package sorts;

import java.util.Arrays;
import java.util.Random;

public class utils {
    public static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    public static void printList(int[] arr) {
        System.out.println(Arrays.toString(arr));
    }

    public static int[] generateRandomArray(int n) {
        Random random = new Random();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = random.nextInt(50);
        }
        return arr;
    }
}
