import pyinstrument

infilename = "input.txt"
outfilename = "result_py.txt"


# Bubble sort and linear search
@pyinstrument.profile()  # Decorator for profiling the function
def sort_n_search(arr, n, val):
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    for i in range(n):
        if arr[i] == val:
            return i
    return None


# Read input from file
with open(infilename, "r") as file:
    lines = file.readlines()
    count, target = map(int, lines[0].split())
    nums = list(map(int, lines[1].split()))

index = sort_n_search(nums, count, target)  # Function call and profiling

# Write search result and sorted array to output file
with open(outfilename, "w") as file:
    file.write(
        f"Value {target} first found at index {index}.\n"
        if index is not None
        else f"Value {target} not found."
    )
    file.write(" ".join(map(str, nums)))
