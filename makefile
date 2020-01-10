ctfmake: binary.c
	gcc binary.c -O0 -no-pie -fno-stack-protector -masm=intel -o binarytest
