import ctypes

lib = ctypes.CDLL("lib/out/my_lib.so")

# void fill_fib(int *arr, int num)
_fill_fib = lib.fill_fib
_fill_fib.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_fill_fib.restype = None

def fill_fib(num):
    arr = (ctypes.c_int * num)()
    _fill_fib(arr, num)

    return list(arr)

# int filter(int *src, int src_len, int *dst, int *dst_len)
_filter = lib.filter
_filter.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int))
_filter.restype = ctypes.c_int

def filter_without_stock(nums):
    src_len = len(nums)
    src = (ctypes.c_int * src_len)(*nums)
    dst_len = ctypes.c_int(0)

    rc = _filter(src, src_len, None, dst_len, 0)
    if rc:
        dst = (ctypes.c_int * dst_len.value)()
        _filter(src, src_len, dst, dst_len, 1)

        return list(dst)
    else:
        return list()

def filter_with_stock(nums):
    src_len = len(nums)
    src = (ctypes.c_int * src_len)(*nums)

    dst_len = ctypes.c_int(src_len)
    dst = (ctypes.c_int * dst_len.value)()
    _filter(src, src_len, dst, dst_len, 1)

    return list(dst)

print(filter_without_stock([]))