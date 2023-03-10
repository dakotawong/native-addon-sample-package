#include <napi.h>
#include <string>
#include "triple.h"

// native C++ function that is assigned to `greetHello` property on `exports` object
Napi::String tripleWord(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    // call `helloUser` function from `greeting.cpp` file
    std::string word = (std::string) info[0].ToString();
    std::string result = triple( word );

    // return new `Napi::String` value
    return Napi::String::New(env, result);
}

// callback method when module is registered with Node.js
Napi::Object Init(Napi::Env env, Napi::Object exports) {

    // set a key on `exports` object
    exports.Set(
        Napi::String::New(env, "tripleWord"), // property name => "greetHello"
        Napi::Function::New(env, tripleWord) // property value => `greetHello` function
    );

    // return `exports` object (always)
    return exports;
}

// register `greet` module which calls `Init` method
NODE_API_MODULE(triple, Init)