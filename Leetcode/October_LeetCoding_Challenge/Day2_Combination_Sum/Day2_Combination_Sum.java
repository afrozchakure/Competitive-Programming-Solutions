class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
 	  List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        helper(candidates, 0, target, 0, temp, res);
        return res;

    }

    void helper(int[] candidates, int start, int target, int sum, List<Integer> list, List<List<Integer>> result) {
        if (sum > target)
            return;
        if (sum == target) {
            result.add(new ArrayList<>(list));
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            list.add(candidates[i]);
            helper(candidates, i, target, sum + candidates[i], list, result);
            list.remove(list.size() - 1);
        }       
    }
}
