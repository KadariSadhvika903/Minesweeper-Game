from distutils.core import setup
from Cython.Build import cythonize
from distutils.extension import Extension

extensions = [
    Extension('mult', ['mult.pyx', 'multiplication.cpp'],
              extra_compile_args=['-std=c++11'],
              language='c++'
              ),
]

setup(ext_modules=cythonize(extensions))
