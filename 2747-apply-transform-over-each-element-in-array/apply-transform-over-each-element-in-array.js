/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const new_arr = []
    for(let i=0;i<arr.length; i++){
        let val = fn(arr[i], i);
        new_arr.push(val);
    }
    return new_arr;
};