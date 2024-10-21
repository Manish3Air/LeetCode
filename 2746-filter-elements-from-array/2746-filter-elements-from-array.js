/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    //return arr.filter(fn);
    let filteredarray = [];
    let j=0;
    for(let i=0;i<arr.length;i++){
        if(fn(arr[i],i)){
        filteredarray[j++] = arr[i];
        }
    }
    return filteredarray;
};