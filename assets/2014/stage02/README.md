# Step two

Get onion data

	wget http://auqgnxjtvdbll3pv.onion

Get the image

	wget http://auqgnxjtvdbll3pv.onion/1033.jpg

Run outguess

	outguess -r 1033.jpg 1033.jpg.outguess

Verify signature

	gpg < 1033.jpg.outguess

> decrypt RSA

Result: http://cu343l33nqaekrnw.onion/

