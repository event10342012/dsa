public class MergeSort {
    private static void mergeSort(int[] arr, int p, int r) {
        if (p >= r) {
            return;
        }
        int q = p + (r - p) / 2;

        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);

        merge(arr, p, q, r);
    }

    private static void merge(int[] arr, int p, int q, int r) {
        int i = p, j = q + 1, k = 0;

        int[] tmp = new int[r - p + 1];

        while (i <= q && j <= r) {
            if (arr[i] < arr[j]) {
                tmp[k++] = arr[i++];
            } else {
                tmp[k++] = arr[j++];
            }
        }

        int start = i, end = q;
        if (j <= r) {
            start = j;
            end = r;
        }

        while (start <= end) {
            tmp[k++] = arr[start++];
        }

        for (i = 0; i <= r - p; i++) {
            arr[p + i] = tmp[i];
        }
    }

    public static void sort(int[] arr) {
        mergeSort(arr, 0, arr.length - 1);
    }

    public static void main(String[] args) {
        int[] arr = utils.generateRandomArray(10);
        utils.printList(arr);
        sort(arr);
        utils.printList(arr);
    }
}
