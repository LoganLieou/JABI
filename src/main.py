import sys

def execute(filename: str):
    with open(filename, "r") as f:
        evaluate(f.read())
        f.close()

def evaluate(contents: str):
    contents = cleanup(contents)
    breacemap = buildbracemap(contents)

    cells, codeptr, cellptr = [0], 0, 0

    while (codeptr < len(contents)):
        command = contents[codeptr]

        if (command == ">"):
            cellptr += 1
            if (cellptr == len(cells)): cells.append(0)

        if (command == "<"):
            cellptr = (0 if cellptr <= 0 else cellptr - 1)

        if (command == "+"):
            cells[cellptr] = cells[cellptr] + 1 if cells[cellptr] < 255 else 0

        if (command == "-"):
            cells[cellptr] = cells[cellptr] - 1 if cells[cellptr] > 0 else 255

        if (command == "[" and cells[cellptr] == 0): codeptr = breacemap[codeptr]
        if (command == "]" and cells[cellptr] != 0): codeptr = breacemap[codeptr]
        if (command == "."): sys.stdout.write(chr(cells[cellptr]))
        if (command == ","): cells[cellptr] = ord(getch.getch())

        codeptr += 1

def cleanup(contents):
    return ''.join(filter(lambda x: x in ['.', ',', '[', ']', '+', '-', '>', '<'], contents))

def buildbracemap(contents):
  temp_bracestack, bracemap = [], {}

  for position, command in enumerate(contents):
    if (command == "["): temp_bracestack.append(position)
    if (command == "]"):
      start = temp_bracestack.pop()
      bracemap[start] = position
      bracemap[position] = start
  return bracemap

if __name__ == "__main__":
    if (len(sys.argv) == 2): execute(sys.argv[1])
    else: print("Useage:", sys.argv[0], "filename")
