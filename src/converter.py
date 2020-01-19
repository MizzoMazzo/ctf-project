from base64 import b85encode
import sys

def reader(fname,iterations=1):

    with open(fname, "rb") as binary_file:
        encoded = binary_file.read()
        for x in range(0,iterations):
            encoded=b85encode(encoded)
        #print(encoded)
    if True:
        with open(fname+"encoded","wb") as outenc:
            outenc.write(encoded)

def main():
    if len(sys.argv)>1:
        name=sys.argv[1]
    else:
        name="binary1"
    reader(name)
    pass



if __name__ == '__main__':
    main()


