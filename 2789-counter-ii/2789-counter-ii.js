/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let count  = init;
    return {
        increment : ()=>{
            return count  = count +1;
        },
        decrement : ()=>{
            return count = count - 1;
        },
        reset : ()=>{
            return (count = init); 
        }
    }
};

