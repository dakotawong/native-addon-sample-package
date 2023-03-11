const assert = require( 'assert' );
const addon = require( '..' ); // loads ../index.js

describe('Test Suitefor the API', () => {
    it('should return `cat` 1 times', () => {
        const result = addon.once('cat'); 
        assert.equal('cat', result);
    } );
    it('should return `dog` 2 times', () => {
        const result = addon.twice('dog'); 
        assert.equal('dog dog', result);
    } );
    it('should return `bird` 3 times', () => {
        const result = addon.triple('bird'); 
        assert.equal('bird bird bird', result);
    } );
} );