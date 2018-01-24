Get onion output

	torify wget http://q4utgdi2n4m4uim5.onion

Check GPG signature and reverse hexdump

	gpg < index.html | xxd -r -p > index.mp3

Some  experiments

	sudo apt-get install libmpg123-dev
	gcc -lmpg123 /usr/share/doc/libmpg123-dev/examples/extract_frames.c -o extract_frames
	./extract_frames --no-info < index.mp3 > index.frames

