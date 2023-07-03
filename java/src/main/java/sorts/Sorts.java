package sorts;

public class Sorts {
    public static void insertionSort1(int[] arr) {
        if (arr.length <= 1) {
            return;
        }

        for (int i = 1; i < arr.length; i++) {
            int key = arr[i];
            int j = i - 1;
            for (; j >= 0; j--) {
                if (arr[j] > key) {
                    arr[j + 1] = arr[j];
                } else {
                    break;
                }
            }
            arr[j + 1] = key;
        }
    }

    public static void insertionSort2(int[] arr) {
        if (arr.length <= 1) {
            return;
        }

        for (int i = 1; i < arr.length; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    public static void selectionSort(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            utils.swap(arr, i, minIdx);
        }
    }

    public static void bubbleSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 1; j < arr.length; j++) {
                if (arr[j] < arr[j - 1]) {
                    utils.swap(arr, j, j - 1);
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = utils.generateRandomArray(5);
        utils.printList(arr);
        bubbleSort(arr);
        utils.printList(arr);
    }
}
