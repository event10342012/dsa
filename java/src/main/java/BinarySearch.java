public class BinarySearch {
    public static int search(int[] arr, int value) {
        int low = 0;
        int high = arr.length - 1;

        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (arr[mid] == value) {
                return mid;
            } else if (arr[mid] < value) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {4, 6, 2, 7, 8, 5, 9, 1, 3};
        int res = search(arr, 9);
        System.out.println(res);
    }
}
