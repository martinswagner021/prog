-- loader.lua

-- Step 1: Load the FFI library, which is built into LuaJIT.
local ffi = require("ffi")

-- Step 2: Define the C function's signature.
-- This is the LuaJIT equivalent of including a C header file (.h).
-- It tells LuaJIT what the function 'display_msg' looks like.
ffi.cdef[[
    /* You can put any C declarations here */
    void display_msg(const char *msg);
]]

-- Check for command-line argument
if #arg < 1 then
    print("Usage: luajit loader.lua <path_to_so_file>")
    os.exit(1)
end

-- Get the library path from the first command-line argument
local lib_path = arg[1]

-- Step 3: Load the shared library (.so file).
-- The 'false' parameter makes the symbols local to this library object.
local mydll = ffi.load(lib_path)

-- Step 4: Call the C function directly from Lua.
-- Lua strings are automatically converted to 'const char*'.
local message = "Hello from LuaJIT!"
mydll.display_msg(message)