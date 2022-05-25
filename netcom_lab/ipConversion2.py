def decToBin(dec):
    return format(int(dec), '08b')

inp = input("Enter a decimal ip address: ")
inp = inp.split(".")
out=''
for i in inp:
    out += decToBin(int(i))
    out += "."
print("The decimal ip address is: ", out[:-1])