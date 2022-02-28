def sender(numbers):
    # introducing checksum as 0
    numbers.append(0)
    # calculating the checksum
    bnr = bin(getWrappedSum(numbers)).replace('0b','')
    x = bnr[::-1]
    while len(x) < 4:
        x += '0'
    bnr = x[::-1]
    checksum = int(getOnesComplement(bnr),2)
    print("Checksum: ",checksum)
    numbers.pop()
    numbers.append(checksum)
    return numbers


def receiver(numbers):
    # calculating the checksum
    bnr = bin(getWrappedSum(numbers)).replace('0b','')
    x = bnr[::-1]
    while len(x) < 4:
        x += '0'
    bnr = x[::-1]
    checksum = int(getOnesComplement(bnr),2)
    print("Checksum: ",checksum)
    if checksum == 0:
        print("data accepted")
    else:
        print("data rejected, error detected")

def getWrappedSum(numbers):
    sum_of_numbers = bin(sum(numbers)).replace("0b","")
    if (len(sum_of_numbers) > 4): 
        wrappedSum = (int(sum_of_numbers[-4:],2) + int(sum_of_numbers[0:-4],2)) 
    else: 
        wrappedSum = (int(sum_of_numbers, 2))
    print("Wrapped sum: ", wrappedSum)
    return wrappedSum


def getOnesComplement(number):
    return number.replace('1', '_').replace('0', '1').replace('_', '0')

print("On sender side: ")
numbers = [int(x) for x in input("Enter set of numbers space seperated: ").split(" ")]
codedDataword = sender(numbers)
print("Set of numbers sent to receiver: ",codedDataword)
print("On Receiver side: ")
receivedData = [int(x) for x in input("Enter received data space seperated: ").split(" ")]
receiver(receivedData)
