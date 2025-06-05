import ctypes
from sys import argv
import os

def call_function_from_dll(dll_path, function_name, msg):
    """
    Calls a function from a DLL with the given arguments.

    :param dll_path: Path to the DLL file.
    :param function_name: Name of the function to call.
    :param args: Arguments to pass to the function.
    :return: The return value from the function call.
    """
    # Load the DLL
    dll = ctypes.CDLL(dll_path)
    print(dll)

    # Get the function from the DLL
    func = getattr(dll, function_name)
    print(func)

    # Call the function with the provided arguments
    return func(msg)
y
if __name__ == "__main__":
    if os.uname().sysname != "Linux":
        print("This script is intended to run on Linux systems only.")
        exit(1)
    if len(argv) < 2:
        print("Usage: python calling.py <path_to_dll>")
        exit(1)
    
    call_function_from_dll(argv[-1], "display_msg", "Hello from Python!".encode('utf-8'))