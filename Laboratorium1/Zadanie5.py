file = open("test.txt")
content = file.read()

print("Podaj slowo do wyszukania: ")
slowo = input()

for line in content.splitlines():
    if slowo in line:
        print(line)
