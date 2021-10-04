"use strict";
const reverseArr = (s) => s.split("").reverse();

function sumStrings(a, b) {
  [a, b] = [reverseArr(a), reverseArr(b)];
  let carry = 0;
  const arr = [];
  const [mx, mn] = a.length >= b.length ? [a, b] : [b, a];
  mx.forEach((itm, idx) => {
    let sm = Number(itm) + (Number(mn[idx]) || 0) + carry;
    [sm, carry] = sm > 9 ? [sm % 10, 1] : [sm, 0];
    arr.unshift(sm);
  });
  if (carry) arr.unshift(carry);
  return arr.join("").replace(/^(0+)/, "");
}
