#!/bin/bash

if [ $1 ]
then
	pass=$1
else
	mkdir ./out/nopass; for out in $(ls); do outguess -r $out ./out/nopass/$out.txt -t ; done
	cd ./out/nopass
	find . -size 0 -print0 | xargs -0 rm
	exit 0
fi

mkdir ./out/$pass; for out in $(ls); do outguess -r -k $pass $out out/$pass/$out.$pass.txt -t ; done
cd ./out/$pass
find . -size 0 -print0 | xargs -0 rm
file ./* > ./filetypes.txt
