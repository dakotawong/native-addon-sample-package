const assert = require( 'assert' );
const addon = require( '..' ); // loads ../index.js

describe( 'Test greet API', () => {
    it( 'should return `blue` 3 times', () => {
        const result = addon.triple( 'Blue' ); 
        assert.equal( 'Blue Blue Blue', result );
    } );
} );