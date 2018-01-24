# Step three

First wget gives us the bytestream that slowly increases...

	torify wget http://cu343l33nqaekrnw.onion/

Output in index.html

Second gives the final file

	torify wget http://cu343l33nqaekrnw.onion/

Final file in index.html.2

hex dump and XOR with 0xFF

	dd if=onioninvert.bin of=onion1.jpg bs=1 skip=0 count=168876
	dd if=onioninvert.bin of=onion2.jpg bs=1 skip=168876 count=1476614
	dd if=onioninvert.bin of=onion3rev.jpg bs=1 skip=1645490 count=175159

	rev < onion3rev.jpg > onion3.jpg

	cat index.html.2 | tail -n +2 | xxd -r -p > out

	outguess -r onion1.jpg onion1.outguess
	outguess -r onion2.jpg onion2.outguess
	outguess -r onion3.jpg onion3.outguess

	gpg < onion1.outguess | xxd -r -p > onion1.bin
	gpg < onion2.outguess | xxd -r -p > onion2.bin
	gpg < onion3.outguess | xxd -r -p > onion3.bin

XOR all the three files together

        make xor

        ./xor -o xor.txt onion1.bin onion2.bin onion1xor2.bin

	gpg < xor.txt

By using a column transposition cipher, with 14 columns wide, ( http://tholman.com/other/transposition/ ) and reordering the columns to the following order: 2 8 9 1 12 13 11 4 5 7 3 0 6 10 I was able to find:

GOOD WORK ULTIMATE TRUTH IS THE ULTIMATE ILLUSION JOIN US AT FV7LYUCMEOZZD5J4 ONIO

