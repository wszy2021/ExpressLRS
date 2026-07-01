import numpy as np

start = 2550000000
stop = 2700000000
bandwidth = 500000
numfreqs = 80
stopband = bandwidth * 0.2

output = np.linspace(start, stop, numfreqs)


prev = start + bandwidth / 2
startf = prev

for x in range(0, numfreqs):
    print(prev)
    prev = prev + bandwidth + stopband


print(startf - (start + bandwidth / 2))
print(stop - (prev + bandwidth / 2))
