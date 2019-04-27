import numpy as np
import pyfftw
import time

'''
c = np.random.rand(100)

start = time.time()

fft_c = pyfftw.interfaces.numpy_fft.fft(c, threads=4)

end = time.time()

print(str(end-start))

'''
n = 1048576

c = pyfftw.empty_aligned(n, dtype='complex128')

# fft_single = pyfftw.interfaces.numpy_fft.fft(c) # Needs a new plan

# c[:] = np.random.randn(*c.shape) + 1j*np.random.randn(*c.shape)

# thread 1
avg = 0.0
for i in range(100):
    start = time.time()
    fft_single = pyfftw.interfaces.numpy_fft.fft(c)
    end = time.time()
    avg += (end - start)

c[:] = np.random.randn(*c.shape) + 1j*np.random.randn(*c.shape)

print("Time: ", avg/100 ,"s \n")

# thread 2
avg = 0.0
for i in range(100):
    start = time.time()
    fft_single = pyfftw.interfaces.numpy_fft.fft(c, threads=2)
    end = time.time()
    avg += (end - start)

c[:] = np.random.randn(*c.shape) + 1j*np.random.randn(*c.shape)

print("Time: ", avg/100 ,"s \n")

# thread 4
avg = 0.0
for i in range(100):
    start = time.time()
    fft_single = pyfftw.interfaces.numpy_fft.fft(c, threads=4)
    end = time.time()
    avg += (end - start)

c[:] = np.random.randn(*c.shape) + 1j*np.random.randn(*c.shape)

print("Time: ", avg/100 ,"s \n")

# thread 6
avg = 0.0
for i in range(100):
    start = time.time()
    fft_single = pyfftw.interfaces.numpy_fft.fft(c, threads=6)
    end = time.time()
    avg += (end - start)

c[:] = np.random.randn(*c.shape) + 1j*np.random.randn(*c.shape)

print("Time: ", avg/100 ,"s \n")

# thread 8
avg = 0.0
for i in range(100):
    start = time.time()
    fft_single = pyfftw.interfaces.numpy_fft.fft(c, threads=8)
    end = time.time()
    avg += (end - start)

c[:] = np.random.randn(*c.shape) + 1j*np.random.randn(*c.shape)

print("Time: ", avg/100 ,"s \n")

# thread 10
avg = 0.0
for i in range(100):
    start = time.time()
    fft_single = pyfftw.interfaces.numpy_fft.fft(c, threads=10)
    end = time.time()
    avg += (end - start)

c[:] = np.random.randn(*c.shape) + 1j*np.random.randn(*c.shape)

print("Time: ", avg/100 ,"s \n")
