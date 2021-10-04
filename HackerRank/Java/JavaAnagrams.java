/*
Two strings, and , are called anagrams if they contain all the same characters in the same frequencies.
For example, the anagrams of CAT are CAT , ACT , TAC , TCA , ATC , and CTA .

Complete the function in the editor. If and are case-insensitive anagrams, print "Anagrams";
otherwise, print "Not Anagrams" instead.

Input Format
The first line contains a string denoting a.
The second line contains a string denoting b.

Constraints
Strings a and b consist of English alphabetic characters.
The comparison should NOT be case sensitive.

Output Format
Print "Anagrams" if a and b are case-insensitive anagrams of each other; otherwise, print "Not Anagrams"
instead.

Sample Input 0
anagram
margana

Sample Output 0
Anagrams

Explanation 0
CharacterFrequency: anagram Frequency: margana
A or a 3 3
G or g 1 1
N or n 1 1
M or m 1 1
R or r 1 1
The two strings contain all the same letters in the same frequencies, so we print "Anagrams".

Sample Input 1
anagramm
marganaa

Sample Output 1
Not Anagrams

Explanation 1
CharacterFrequency: anagramm Frequency: marganaa
A or a 3 4
GN or gn 11 11
M or m 2 1
R or r 1 1
CharacterFrequency: anagramm Frequency: marganaa
The two strings don't contain the same number of a 's and m 's, so we print "Not Anagrams".
*/

import java.util.Scanner;

public class Solution {

    static boolean isAnagram(String a, String b) {
        if (a.length() != b.length()) {
            return false;
        }
        a = a.toLowerCase();
        b = b.toLowerCase();
        int sum = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            for (int i=0; i<a.length(); i++) {
                if (a.charAt(i) == c) {
                    sum++;
                }
                if (b.charAt(i) == c) {
                    sum--;
                }
            }
            if (sum != 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}
