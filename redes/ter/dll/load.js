const ffi = require('ffi-napi');
const ref = require('ref-napi');
const path = require('path');

// --- 1. Define the library name and path ---
// IMPORTANT: Adjust 'mydll' if your library base name is different.
const libBaseName = 'mydll';
let libPath = '';

// Construct the full path to the library, assuming it's in the same directory as the script.
// You might need to adjust this if your library is elsewhere.
libPath = path.join(__dirname, `lib${libBaseName}.so`);

// --- 2. Load the library and define the function signature ---
// ffi.Library takes the library path and an object mapping function names
// to their signatures: [return_type, [arg_type1, arg_type2, ...]]
const myLib = ffi.Library(libPath, {
    'display_msg': [ref.types.void, [ref.types.CString]]
    // 'ref.types.void' means the C function returns void.
    // 'ref.types.CString' means the C function expects a 'char*'.
    // node-ffi-napi will handle the conversion from a JavaScript string
    // to a null-terminated C string.
});

// --- 3. Prepare the message and call the function ---
const message = "Hello from Node.js using ffi-napi!";

myLib.display_msg(message); // Call the C function