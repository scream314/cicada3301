# Step four

	torify wget http://fv7lyucmeozzd5j4.onion/

	torify wget http://fv7lyucmeozzd5j4.onion/server-status

> reverse hexdump to get server-status.jpg

	dd if=server-status.jpg of=server-status.data bs=1 skip=336353 count=360

	cat server-status.data  | perl -0777e 'print scalar reverse <>' | xxd -r -p > matrix

> index.html got a final update to new content. 4MB of hexdump

	cat index.html.1 | tail -n +2 | xxd -r -p > index.1.bin

	cat index.1.bin | /home/michel/3301-old/onion3/byte-reverse.pm > index.1.bin.reverse

	dd if=index.1.bin bs=1 of=index.1.jpg count=892759

	dd if=index.1.rev.bin bs=1 of=index.1.rev.jpg count=1223337

	outguess -r index.1.jpg index.1.outguess

	outguess -r index.1.rev.jpg index.1.rev.outguess

	cat index.1.outguess  | head -n 516 | tail -n +10 | xxd -r -p > index.1.outguess.jpg

