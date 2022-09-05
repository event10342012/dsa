package sorts;

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
        int i = p;
        int j = q + 1;
        int k = 0;

        int[] tmp = new int[r - p + 1];

        // merge two sequences
        while (i <= q && j <= r) {
            if (arr[i] < arr[j]) {
                tmp[k++] = arr[i++];
            } else {
                tmp[k++] = arr[j++];
            }
        }

        // add rest of sequence to tmp array
        int start = i;
        int end = q;
        if (j <= r) {
            start = j;
            end = r;
        }
        while (start <= end) {
            tmp[k++] = arr[start++];
        }

        // copy to arr
        for (i = 0; i < tmp.length; i++) {
            arr[p + i] = tmp[i];
        }
    }

    public static void sort(int[] arr) {
        mergeSort(arr, 0, arr.length - 1);
    }

    public static void main(String[] args) {
        int[] arr = utils.generateRandomArray(5);
        utils.printList(arr);
        sort(arr);
        utils.printList(arr);
    }
}
