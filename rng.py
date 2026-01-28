import random

filename = "input.txt"
count = 12345
min_val = 1
max_val = 1337
with open(filename, "w") as file:
    file.write(f"{count} {random.randint(min_val, max_val)}\n")
    for _ in range(count):
        file.write(f"{random.randint(min_val, max_val)} ")
print(f"{count} random integers between {min_val} and {max_val} written in {filename}")
