// Entry point for the package

// Import the library (using bindings in case path to triple.node changes)
const addon = require('bindings')('triple');

// Export the methods
exports.triple = addon.tripleWord;
exports.twice = addon.twiceWord;
exports.once = addon.onceWord;