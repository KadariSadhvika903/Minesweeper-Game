from distutils.core import setup
from Cython.Build import cythonize
from distutils.extension import Extension

extensions = [
    Extension('Minesweeper', ['./Binders/Minesweeper.pyx', './src/minesweeper.cpp'],
              extra_compile_args=['-std=c++11'],
              language='c++'
              ),
]

setup(ext_modules=cythonize(extensions))
