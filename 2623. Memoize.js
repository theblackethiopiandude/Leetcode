/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    let umap = {};
    return function(...args) {
        if(!(args in umap))
            umap[args] = fn(...args);

        return umap[args];
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
