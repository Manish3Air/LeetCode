/**
 * @return {Function}
 */
var createHelloWorld = function() {
    const hell = 'Hello World';
    return function (...args) {
        return hell;
    }
    
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */