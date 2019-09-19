import time

arr = [1 if x % 2 else -1 for x in range(10000)]

time_before = time.time()
for i in range(100000):
    arr = list(filter(lambda x: 1 if x > 0 else 0, arr))
time_after = time.time()

print(time_after - time_before, " time running reduce on Python")