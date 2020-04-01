
def encode(input_string):
    count = 1
    prev = ''
    lst = []
    for character in input_string:
        if character != prev:
            if prev:
                entry = (count, prev)
                lst.append(entry)

            count = 1
            prev = character
        else:
            count += 1
    else:
        try:
            entry = (count, character)
            lst.append(entry)
            return (lst, 0)
        except Exception as e:
            print("Exception encountered {e}".format(e=e))
            return (e, 1)


def decode(lst):
    q = ""
    for character, count in lst:
        q += character * count
    return q


#Method call
with open("doc.txt") as fp:
    rawText = fp.read(-1)

value = encode(rawText)
if value[1] == 0:
    carr = []

    for i, c in value[0]:
        carr.append(str(hex(i)))
        carr.append(str(hex(ord(c))))


    output = "const char RLE_INSTRUCTIONS[] = { \\\n"
    
    while len(carr):
        limit = min(len(carr), 12)
        row = carr[:limit]
        carr = carr[limit:]
        output+= f"\t{','.join(row)},\\\n" 
    
    print(output)
    
    decode(value[0])


print(len(rawText))
print(len(carr))
