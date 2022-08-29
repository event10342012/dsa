public class QuickSort {

    public static void sort(int[] arr) {
        quickSort(arr, 0, arr.length - 1);
    }

    private static int partition(int[] arr, int p, int r) {
        int pivot = arr[r];

        int i = p;
        // r is the position of pivot, so j < r
        for (int j = p; j < r; j++) {
            if (arr[j] < pivot) {
                if (i != j) {
                    utils.swap(arr, i, j);
                }
                i++;
            }
        }

        utils.swap(arr, i, r);
        return i;
    }

    private static void quickSort(int[] arr, int p, int r) {
        if (p < r) {

            int q = partition(arr, p, r);

            quickSort(arr, p, q - 1);
            quickSort(arr, q + 1, r);
        }
    }

    public static void main(String[] args) {
        int[] arr = {5, 6, 4, 3, 7, 5};
        utils.printList(arr);
        sort(arr);
        utils.printList(arr);
    }
}
