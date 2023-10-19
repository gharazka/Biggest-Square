import random

def choose_params():
    width = input("choose width: ")
    length = input("choose length: ")
    empty = input("choose empty character: ")
    obstacle = input("choose obstacle character: ")
    full = input("choose full character: ")
    frequency = input("choose obstacle frequency (5-8 reccomended): ")

    return width, length, empty, obstacle, full, frequency

def create_map(mapname):
    width, length, empty, obstacle, full, frequency = choose_params()
    file = open(f'{mapname}', "w")
    file.write(f'{length}.{empty}{obstacle}{full}\n')
    for i in range(int(length)):
        line = ""
        for j in range(int(width)):
            if random.randint(0,100) > int(frequency):
                line = line + empty
            else:
                line = line + obstacle
        file.write(f'{line}\n')


def main():
    create_map(input("pick map name(map1 default if using make out command): "))

main()
