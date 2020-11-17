package com.codewars.julesnuggy;

import java.util.Arrays;

public class BingoOrNot {
    public static String bingo(int[] numberArray) {
        int counter = 0;
        int[] bingoArr = new int[] { 2, 9, 14, 7, 15 };
        for (int a : bingoArr) {
            if (Arrays.stream(numberArray).anyMatch(i -> i == a))
                counter++;
        }
        return counter == 5 ? "WIN" : "LOSE";
    }
}