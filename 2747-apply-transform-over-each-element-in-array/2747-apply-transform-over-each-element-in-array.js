/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
//   const transformedArr = [];
//   let index = 0;
//   for (const element of arr) {
//     transformedArr[index] = fn(element, index);
//     index++;
//   }
//   return transformedArr;

// const transformedArr = [];
//   arr.forEach((element, index) => {
//     transformedArr[index] = fn(element, index);
//   });
//   return transformedArr;

const transformedArr = [];
  for(let i=0;i<arr.length; i++){
    transformedArr[i] = fn(arr[i],i);
  }
  return transformedArr;

};