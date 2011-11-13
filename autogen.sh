#!/bin/bash

gen()
{
autoreconf --install
}
build()
{
./configure CXXFLAGS="-g -ggdb -O0"
make
}
clean()
{
#if [[ -e src/Makefile ]]; then
#	make clean
#fi
rm -rf src/*.o src/gtkmmlearn
rm -rf aclocal.m4 autom4te.cache config.log config.status configure depcomp install-sh Makefile missin Makefile.in src/Makefile.in Makefile config.h config.h.in stamp-h1 missing src/config.h src/config.h.in src/stamp-h1 src/Makefile
}

if [[ $1 == 'clean' ]]; then
clean
elif [[ $1 == 'build' ]]; then
gen
build
else
gen
fi	
