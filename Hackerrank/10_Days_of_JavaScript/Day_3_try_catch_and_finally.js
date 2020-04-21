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

/*
 * Complete the reverseString function
 * Use console.log() to print to stdout.
 */
function reverseString(s) {
    try {
        var list_s = s.split("").reverse().join("");
        console.log(list_s)
    }
    // var reverse_list = list_s.reverse();
    // var joined_list = reverse_list.join("");
    // console.log(joined_list);
    catch (err) {
        console.log(err.message);
        console.log(s);
    }

}