import ctypes

def hostname_py(buffer, source):
    lib = ctypes.CDLL('../libs/libcore.so')

    src_buffer = ctypes.create_string_buffer(str.encode(buffer))
    src_new_hostname = ctypes.create_string_buffer(str.encode(source))

    lib.hostname(src_buffer, src_new_hostname)

    return bytes.decode(src_new_hostname.value) 

# Test 1
buffer = "mambo"
source = "        "

print(hostname_py(buffer, source))
