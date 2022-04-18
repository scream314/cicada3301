# 2016 jan. 5.
## The 2016 tweet
Start with the [tweet](https://twitter.com/1231507051321/status/684596461628223488)

    wget https://twitter.com/1231507051321/status/684596461628223488

Get the image

    wget https://infotomb.com/4gq25.jpg

<p align="middle"><img src="assets/2016/4gq25.jpg" alt="4gq25.jpg" width="600" border="2"></p>

Run outguess

    outguess -r 4gq25.jpg 4gq25.jpg.outguess

Verify signature

    gpg < 4gq25.jpg.outguess

Output:

    Hello.

    The path lies empty; epiphany seeks the devoted.

    Liber Primus is the way.  Its words are the map, their
    meaning is the road, and their numbers are the direction.

    Seek and you will be found.


    Good luck.

    3301


    Beware false paths.  Verify OpenPGP 7A35090F.


    gpg: Signature made Fri 01 Jan 2016 12:01:07 AM UTC
    gpg:                using RSA key 0x181F01E57A35090F
    gpg: Good signature from "Cicada 3301 (845145127)" [unknown]
    gpg: WARNING: This key is not certified with a trusted signature!
    gpg:          There is no indication that the signature belongs to the owner.
    Primary key fingerprint: 6D85 4CD7 9333 22A6 01C3  286D 181F 01E5 7A35 090F

* The message is signed.
* The image contains the "Cicada Logo" and the "Oak Tree In Winter".

[2017](2017.md)
