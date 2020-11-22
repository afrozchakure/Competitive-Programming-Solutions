'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });

    main();
});

function readLine() {
    return inputString[currentLine++];
}

/**
 *   Return the second largest number in the array.
 *   @param {Number[]} nums - An array of numbers.
 *   @return {Number} The second largest number in the array.
 **/
function getSecondLargest(nums) {
    // Complete the function
    for (var i = 0; i < nums.length; i++) {
        for (var j = 0; j < nums.length - i; j++)
            if (nums[j] < nums[j + 1]) {
                var temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
    }
    var temp1 = nums[0];
    // console.log(nums)
    for (var i = 1; i < nums.length; i++) {
        if (temp1 > nums[i]) {
            temp1 = nums[i];
            break;
        }
    }
    return temp1;


}