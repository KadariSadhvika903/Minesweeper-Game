
cdef extern from "multiplication.h":
    int multiply(int, int)

cpdef pymult(x, y):
    return multiply(x, y)