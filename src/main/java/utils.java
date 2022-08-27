import java.util.Random;

public class utils {
    public static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    public static void printList(int[] arr) {
        for (int x : arr) {
            System.out.print(x + ", ");
        }
        System.out.println();
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
