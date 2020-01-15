import binascii
from base64 import b64encode
from base64 import b32encode
from base64 import b85encode


def reader(fname,iterations=1):
    #encoded = None
    with open(fname, "rb") as binary_file:
        encoded = binary_file.read()
        for x in range(0,iterations):
            encoded=b85encode(encoded)
    print(encoded)
    print(len(encoded))
    if True:
        with open(fname+"encoded","wb") as outenc:
            outenc.write(encoded)




def main():
    reader("binary1")
    pass



if __name__ == '__main__':
    main()


