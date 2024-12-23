#print("\n\nenter binary digit in multiple of 8\n")
#key = '01010100100101010000101111100101010100101010101001010011'
#print("the entered binary value is : ",key)

x=input("enter binary code : ")
key=(x)

count = 1
letter = ''
line = ''
for i in key:
    letter += i
    if count == 8:
        line += chr(int(letter, 2))
        count = 0
        letter = ''
    count += 1
print("------------------------------------------------------------------")    
print(line)
print("------------------------------------------------------------------")
