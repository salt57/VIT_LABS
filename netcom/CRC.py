def xor(a, b):

    result = []
 
    for i in range(1, len(b)):
        if a[i] == b[i]:
            result.append('0')
        else:
            result.append('1')
 
    return ''.join(result)
 
 
def mod2div(divident, divisor):

    pointer = len(divisor)
 
    tmp = divident[0 : pointer]
 
    while pointer < len(divident):
 
        if tmp[0] == '1':
            tmp = xor(divisor, tmp) + divident[pointer]
 
        else:
            tmp = xor('0'*pointer, tmp) + divident[pointer]
 
        pointer += 1
 
    if tmp[0] == '1':
        tmp = xor(divisor, tmp)
    else:
        tmp = xor('0'*pointer, tmp)
 
    checkword = tmp
    return checkword

def encodeData(data, key):
 
    l_key = len(key)
 
    appended_data = data + '0'*(l_key-1)
    remainder = mod2div(appended_data, key)

    codeword = data + remainder
    print("Remainder : ", remainder)
    print("Encoded Data (Data + Remainder) : ", codeword)
 
def decodeData(data, key):
    remainder = mod2div(data, key)
    print("Decoded data on reciever side: ", remainder)
    if remainder == '0'*(len(key)-1):
        print("Hence no error in transmission")
    else:
        print("Error in transmission")

data = input("Enter data to be encoded: ")
key = input("Enter key: ")
encodeData(data, key)
recieverValue = input("Enter value received by receiver: ")
decodeData(recieverValue, key)