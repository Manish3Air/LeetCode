/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let count  = init;
    return {
        increment : function(){
            return count  = count +1;
            
        },
        decrement : function(){
            return count = count - 1;
        },
        reset : function(){
            return (count = init); 
        }
    }
};

