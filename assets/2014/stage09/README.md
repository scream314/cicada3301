# Stage 9

Get the latest files

	torify wget http://ut3qtzbrvs7dtvzp.onion

Strip the headers and reverse hexdump

	tail -n +2 index.html | xxd -r -p > index.bin

Extract four JPEG files

	dd if=index.bin of=index.1.jpg bs=1 skip=0 count=754662
	dd if=index.bin of=index.2.jpg bs=1 skip=754662 count=712733
	dd if=index.bin of=index.3.jpg bs=1 skip=1467395 count=703428
	dd if=index.bin of=index.4.jpg bs=1 skip=2170823 

Run outguesson each

	outguess -r index.4.jpg  index.1.outguess
	outguess -r index.2.jpg  index.2.outguess
	outguess -r index.3.jpg  index.3.outguess
	outguess -r index.4.jpg  index.4.outguess

Verify signature

	gpgv < index.1.outguess
	gpgv < index.2.outguess
	gpgv < index.3.outguess
	gpgv < index.4.outguess

