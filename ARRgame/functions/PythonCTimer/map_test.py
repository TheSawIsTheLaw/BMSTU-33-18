import time

arr = [0 for x in range(10000)]

time_before = time.time()
for i in range(1000):
    arr = list(map(lambda x: x + 1, arr))
time_after = time.time()

print(time_after - time_before, " time running map on Python")