import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;


class TrieNode {
    TrieNode[] next;
    int index;
    List<Integer> list;

    TrieNode() {
        next = new TrieNode[26];
        index = -1;
        list = new ArrayList<>();
    }
}

public class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        List<List<Integer>> res = new ArrayList<>();
        TrieNode root = new TrieNode();
        for (int i = 0; i < words.length; i++) {
            addWord(root, words[i], i);
        }
        for (int i = 0; i < words.length; i++) {
            search(words, i, root, res);
        }
        return res;
    }

    public static void main(String[] args) {
        System.out.println("Hello world");
    }
    private void addWord(TrieNode root, String word, int index) {
        for (int i = word.length() - 1; i >= 0; i--) {
            if (root.next[word.charAt(i) - 'a'] == null) {
                root.next[word.charAt(i) - 'a'] = new TrieNode();
            }

            if (isPalindrome(word, 0, i)) {
                root.list.add(index);
            }

            root = root.next[word.charAt(i) - 'a'];
        }

        root.list.add(index);
        root.index = index;
    }
    private void search(String[] words, int i, TrieNode root, List<List<Integer>> list) {
        for (int j = 0; j < words[i].length(); j++) {
            if (root.index >= 0 && root.index != i && isPalindrome(words[i], j, words[i].length() - 1)) {
                 list.add(Arrays.asList(i, root.index));
            }

            root = root.next[words[i].charAt(j) - 'a'];
            if (root == null) return;
        }

        for (int j : root.list) {
            if (i == j) continue;
            list.add(Arrays.asList(i, j));
        }
    }

    private boolean isPalindrome(String word, int i, int j) {
        while (i < j) {
            if (word.charAt(i++) != word.charAt(j--)) return false;
        }
        return true;
    }
}
