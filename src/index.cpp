#include <napi.h>
#include <string>
#include "triple.h"

// Native C++ function that is assigned to `tripleWord` property on `exports` object
Napi::String tripleWord(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    // Call `triple` function from the `tripple.h` file using the info input
    std::string word = (std::string) info[0].ToString();
    std::string result = triple(word);

    // Return output as a new `Napi::String` value
    return Napi::String::New(env, result);
}

// Native C++ function that is assigned to `twiceWord` property on `exports` object
Napi::String twiceWord(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    // Call `twice` function from the `triple.h` file using the info input
    std::string word = (std::string) info[0].ToString();
    std::string result = twice(word);

    // Return output as a new `Napi::String` value
    return Napi::String::New(env, result);
}

// Native C++ function that is assigned to `onceWord` property on `exports` object
Napi::String onceWord(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    /// Call `once` function from the `triple.h` file using the info input
    std::string word = (std::string) info[0].ToString();
    std::string result = once(word);

    // Return output as a new `Napi::String` value
    return Napi::String::New(env, result);
}



// Initialization method when module is registered with Node.js
Napi::Object Init(Napi::Env env, Napi::Object exports) {

    // Set the functions on the export object
    exports.Set(
        Napi::String::New(env, "tripleWord"), // property name => "tripleWord"
        Napi::Function::New(env, tripleWord) // property value => `tripleWord` function
    );
    exports.Set(
        Napi::String::New(env, "twiceWord"), // property name => "twiceWord"
        Napi::Function::New(env, twiceWord) // property value => `twiceWord` function
    );
    exports.Set(
        Napi::String::New(env, "onceWord"), // property name => "onceWord"
        Napi::Function::New(env, onceWord) // property value => `onceWord` function
    );

    // Return `exports` object
    return exports;
}


// register `triple` module which will call the `Init` method
NODE_API_MODULE(triple, Init)