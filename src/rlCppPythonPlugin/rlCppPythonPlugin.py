from random import random
from time import perf_counter

from rlCppPlugin import fast_tanh
from rlCppPlugin import multi_fast_tanh_test
from rlCppPlugin2 import fast_tanh2
from rlCppPlugin2 import multi_fast_tanh_test2

COUNT = 50000000  # Change this value depending on the speed of your computer
DATA = [(random() - 0.5) * 3 for _ in range(COUNT)]

e = 2.7182818284590452353602874713527

def sinh(x):
    return (1 - (e ** (-2 * x))) / (2 * (e ** -x))

def cosh(x):
    return (1 + (e ** (-2 * x))) / (2 * (e ** -x))

def tanh(x):
    tanh_x = sinh(x) / cosh(x)
    return tanh_x

def test(fn, name):
    start = perf_counter()
    fn(DATA)
    duration = perf_counter() - start
    print('{:.3f} seconds [{}]'.format(duration, name))



if __name__ == "__main__":
    print('Running benchmarks with COUNT = {}'.format(COUNT))

    test(lambda d: [tanh(x) for x in d], '[tanh(x) for x in d] (Python implementation)')
    test(lambda d: [fast_tanh(x) for x in d], '[tanh(x) for x in d] (C++ CPython implementation)')
    test(lambda d: [fast_tanh2(x) for x in d], '[tanh(x) for x in d] (C++ PyBind11 implementation)')
    
    test(lambda d: multi_fast_tanh_test(COUNT), 'multi_fast_tanh_test(COUNT) (C++ CPython implementation)')
    test(lambda d: multi_fast_tanh_test2(COUNT), 'multi_fast_tanh_test2(COUNT) (C++ PyBind11 implementation)')
