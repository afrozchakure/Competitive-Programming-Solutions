package Hard;

import java.util.*;

public class RestaurantReviews {

// Alternative approach
    /*
    *    Time Complexity: O(n * |word length|)
    Space Complexity: O(n)
    * */
    // We can construct a Trie on the Good Words, and by traversing on our Trie,
// we can check if the review string has some good word in it and keep its count.
// Finally we sort the result using a custom comparator, and return the output.
    class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    class TrieNode {
        TrieNode[] children = new TrieNode[26];
        boolean isEnd = false;
        public boolean hasWord(String w) {
            TrieNode nextNode = this;
            for (int i = 0; i < w.length(); i++) {
                int nextIndex = w.charAt(i) - 'a';
                nextNode = nextNode.children[nextIndex];
                if (nextNode == null) {
                    return false;
                }
                if (i == w.length() - 1) {
                    return nextNode.isEnd;
                }
            }
            return false;
        }
        public void addWord(String w) {
            TrieNode nextNode = this;
            for (int i = 0; i < w.length(); i++) {
                int nextIndex = w.charAt(i) - 'a';
                if (nextNode.children[nextIndex] == null) {
                    nextNode.children[nextIndex] = new TrieNode();
                }
                // important ::
                nextNode = nextNode.children[nextIndex];

                if (i == w.length() - 1) {
                    nextNode.isEnd = true;
                    return;
                }
            }
        }
    }

    String[] orderReviewsII(String[] reviews, String[] goodWords) {
        String[] output = new String[reviews.length];
        TrieNode root = new TrieNode();
        for (int i = 0; i < goodWords.length; i++) {
            root.addWord(goodWords[i]);
        }
        Pair[] goodness = new Pair[reviews.length];
        int goodnessIndx = 0;
        for (int i = 0; i < reviews.length; i++) {
            String review = reviews[i];
            int numGoodWords = 0;
            int s = 0;
            for (int j = 0; j < review.length(); j++) {
                if (review.charAt(j) == ' ') {
                    if (root.hasWord(review.substring(s, j))) {
                        numGoodWords++;
                    }
                    s = j + 1;
                }
            }
            // for last word
            if (root.hasWord(review.substring(s, review.length()))) {
                numGoodWords++;
            }
            // store the goodness array with each review strings index and num of good words found.
            goodness[goodnessIndx++] = (new Pair(numGoodWords, i));
        }

        //
        Arrays.sort(goodness, new Comparator<Pair> () {
            public int compare(Pair a, Pair b) {
                if(a.first < b.first) {
                    return 1;
                }
                if(a.first == b.first && a.second > b.second) {
                    return 1;
                }
                return - 1;
            }
        });

        // output the review string indexes
        for (int i = 0; i < reviews.length; i++) {
            output[i] = reviews[goodness[i].second];
        }
        return output;
    }

    public static void main(String[] args) {
        RestaurantReviews r = new RestaurantReviews();
        r.orderReviewsII(new String[]{"good restaurant", "tasty food nice ambience","nice place",
                "good lovely nice tasty"}, new String[] {"good", "lovely", "nice", "tasty"});
    }
}

