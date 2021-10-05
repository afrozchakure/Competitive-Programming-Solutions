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

function getMaxLessThanK(n, k) {
    let max = 0;
    let cur = -1;
    for(let i = 1; i < n; i++) {
        for(let j = i+1; j <= n; j++) {
            cur = i & j;
            if(cur < k && cur > max) {
                max = cur;
            }
        }
    }
    return max;
}

/*
Method - 2

function getMaxLessThanK( n,  k)
{
    let result = 0;
    let k_String = k.toString(2); // converting number to binary
    k_String = k_String.charAt(k_String.length - 1);  // To get the rightmost element
    if(k_String == '1')
    {
        k = k - 1;
        return k;
    }
    else{
        for(let i=1; i<n; i++)
        {
            for(let j=i+1; j<n+1; j++)
            {
                let diff = i&j;
                if(diff >= k) 
                {
                    return result;
                }
                if(diff > result)
                {
                    result = diff;
                }
            }
        }
    }
    return result;
}
*/
function main() {
    const q = +(readLine());
    
    for (let i = 0; i < q; i++) {
        const [n, k] = readLine().split(' ').map(Number);
        
        console.log(getMaxLessThanK(n, k));
    }
}
