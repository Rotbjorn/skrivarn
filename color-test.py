
for i in range(256):
    print(f"\x1b[{i}m {i} \x1b[0m", end=" ")
    if (i % 7 == 0):
        print()
