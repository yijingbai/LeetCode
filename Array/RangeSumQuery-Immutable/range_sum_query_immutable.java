public class NumArray {

    int[] opt;

    public NumArray(int[] nums) {
        if (nums.length == 0) {
            opt = null;
        } else {
            opt = new int[nums.length];
            opt[0] = nums[0];
            for (int i = 1; i < nums.length; i++) {
                opt[i] = opt[i - 1] + nums[i];
            }
        }
    }

    public int sumRange(int i, int j) {
        if (opt == null) {
            return 0;
        }
        if (i == 0) {
            return opt[j];
        }
        return opt[j] - opt[i - 1];
    }
}

