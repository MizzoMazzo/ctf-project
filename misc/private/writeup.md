Our challenge will provide a "random"-generated binary to exploit each run.

General solution:

1. Connect to the server and find out the used encoding for the binary
2. Reverse the binary
3. Repeat steps 1 and 2 until you find out the general layout
4. Write a script with python and pwntools to automatically compile the encoded string
5. Use pwntools to find the neccessary inputs with ltrace locally
6. Use pwntools to find the buffer-length locally
7. Find the address of the print_flag function with pwntools
8. Exploit it on the next connection!


To use the challenge locally, just run the "spawn" executable provided in the src/ folder.
This file will give you the output you'll need.
We will later implement this inside a Docker-Image on a hosted EC2-instance which will accept TCP-connections to be used with netcat.
