def binToDec(bin):
    return str(int(bin, 2))

inp = input("Enter a binary ip address: ")
inp = inp.split(".")
out=''
for i in inp:
    out += binToDec(i)
    out += "."
print("The decimal ip address is: ", out[:-1])