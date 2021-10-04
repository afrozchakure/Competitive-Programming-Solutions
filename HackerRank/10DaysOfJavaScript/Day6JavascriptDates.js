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

// The days of the week are: "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
function getDayName(dateString) {
    let dayName;
    let days = new Array();
    days = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'];
    // Write your code here
    let date = new Date(dateString);
    for (let i = 0; i <= 6; i++) {
        if (date.getDay() === i)
            dayName = days[i];

    }
    return dayName;
}


function main() {
    const d = +(readLine());

    for (let i = 0; i < d; i++) {
        const date = readLine();

        console.log(getDayName(date));
    }
}