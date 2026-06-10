import numpy as np

# L1575 band: 1560-1587 MHz, center 1575 MHz, 28 channels @ 1 MHz spacing
start = 1560000000
stop = 1587000000
bandwidth = 500000
numfreqs = 28
stopband = bandwidth * 0.25

output = np.linspace(start, stop, numfreqs)

prev = start + bandwidth / 2 + 0
startf = prev

for x in range(0, numfreqs):
    print(prev)
    prev = prev + bandwidth + stopband

print(startf - (start + bandwidth / 2))
print(stop - (prev + bandwidth / 2))
