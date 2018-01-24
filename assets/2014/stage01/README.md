# Start of Cicada 2014

Start with the twee

	wget https://twitter.com/1231507051321

Get the image

	wget i.imgur.com/zN4h51m.jpg 

Run outguess

	outguess -r zN4h51m.jpg zN4h51m.jpg.outguess
	Reading zN4h51m.jpg....
	Extracting usable bits:   29835 bits
	Steg retrieve: seed: 178, len: 1150

Verify signature

	gpg < zN4h51m.jpg.outguess

