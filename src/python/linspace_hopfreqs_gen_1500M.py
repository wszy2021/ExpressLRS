import numpy as np

start = 1520000000
stop = 1620000000
bandwidth = 500000
numfreqs = 40
stopband = bandwidth*0.25

output = np.linspace(start, stop, numfreqs)


prev = start + bandwidth/2 +0
startf = prev

for x in range(0,numfreqs):
    print(prev)
    prev = prev + bandwidth + stopband

 
print(startf-(start+bandwidth/2))
print(stop-(prev+bandwidth/2))
