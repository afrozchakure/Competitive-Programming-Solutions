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
 * Complete the vowelsAndConsonants function.
 * Print your output using 'console.log()'.
 */
function vowelsAndConsonants(s) {
    var vowels = 'aeiou';
    var consonants = 'bcdfghjklmnpqrstvwxyz';
    for (var j = 0; j < s.length; j++) {
        for (var i = 0; i < vowels.length; i++) {
            if (s[j] === vowels[i]) {
                console.log(vowels[i]);
            }

        }
    }
    for (var j = 0; j < s.length; j++) {
        for (var i = 0; i < consonants.length; i++) {
            if (s[j] === consonants[i]) {
                console.log(consonants[i]);
            }

        }
    }


}


function main() {
    const s = readLine();

    vowelsAndConsonants(s);
}