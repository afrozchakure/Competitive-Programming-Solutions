let elem = document.getElementById("res");

function checkOperator() {
    if (elem.innerHTML.endsWith('+') || elem.innerHTML.endsWith('-') ||
        elem.innerHTML.endsWith('*') || elem.innerHTML.endsWith('/')) {
        return true;
    }
}

function clickZero() {
    elem.innerHTML += '0';
}

function clickOne() {
    elem.innerHTML += '1';
}
console.log(elem);

function clickSum() {
    if (elem.innerHTML.length != 0 && !checkOperator()) {
        elem.innerHTML += '+';
    }
}

function clickMul() {
    if (elem.innerHTML.length != 0 && !checkOperator()) {
        elem.innerHTML += '*';
    }
}

function clickDiv() {
    if (elem.innerHTML.length != 0 && !checkOperator()) {
        elem.innerHTML += '/';
    }
}

function clickSub() {
    if (elem.innerHTML.length != 0 && !checkOperator()) {
        elem.innerHTML += '-';
    }
}

function clickClr() {
    elem.innerHTML = "";
}

function clickEql() {
    if (!checkOperator()) {
        // re is used to get the NUMBERS 
        // re2 is used to get the OPERATORS
        let re = /\d+/g
        let re2 = /[\+\-\*\/]+/g
        let numbers = elem.innerHTML.match(re);
        let operations = elem.innerHTML.match(re2);
        while (operations.length > 0) {
            if (operations.includes("*")) {
                let indexOfMul = operations.indexOf('*');

                // if index of Mul != 0, then simply convert number to decimal the previous number
                // else multiply the present value at indexOfMul with next value
                let mul = (indexOfMul != 0 ? parseInt(numbers[indexOfMul - 1], 2) : parseInt(numbers[indexOfMul], 2)) * parseInt(numbers[indexOfMul + 1], 2);
                numbers.splice(indexOfMul, 2); // splicing elementes with indexOfMul
                numbers.splice(indexOfMul, 0, mul.toString(2)); // Add item in indexOfMul and remove 1 item
                operations.splice(indexOfMul, 1); // remove 1 element from position indexOf
            } else if (operations.includes('/')) {
                let indexOfDiv = operations.indexOf('/');

                let div = (indexOfDiv != 0 ? parseInt(numbers[indexOfDiv - 1], 2) : parseInt(numbers[indexOfDiv], 2)) / parseInt(numbers[indexOfDiv + 1], 2);
                numbers.splice(indexOfDiv, 2);
                numbers.splice(indexOfDiv, 0, div.toString(2)); // Add items at indexofdiv and remove 1 item from position 0
                operations.splice(indexOfDiv, 1); // remove 1 element from position indexof 
            } else if (operations.includes('+')) {
                let indexOfAdd = operations.indexOf('+');

                let add = (indexOfAdd != 0 ? parseInt(numbers[indexOfAdd - 1], 2) : parseInt(numbers[indexOfAdd], 2)) + parseInt(numbers[indexOfAdd + 1], 2);
                numbers.splice(indexOfAdd, 2); // splicing the elements on indexOfAdd
                numbers.splice(indexOfAdd, 0, add.toString(2)); // add.toString(2) at indexOfAdd
                operations.splice(indexOfAdd, 1); // remove element from indexOfAdd
            } else if (operations.includes('-')) {
                let indexOfSub = operations.indexOf('-');

                let sub = (indexOfSub != 0 ? parseInt(numbers[indexOfSub - 1], 2) : parseInt(numbers[indexOfSub], 2)) - parseInt(numbers[indexOfSub + 1], 2);
                numbers.splice(indexOfSub, 2);
                numbers.splice(indexOfSub, 0, sub.toString(2)); // Add sub.toString(2) - which coverts sub to a binary number
                operations.splice(indexOfSub, 1); // remove 1 elemenet from position indexof
            }
        }
        elem.innerHTML = numbers[0].toString(2);
    } else {
        alert("line must end with number.");
    }
}