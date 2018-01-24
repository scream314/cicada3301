#!/usr/bin/python
# input file should contain runes encoded as numbers, separated by whitespace. Encoding starts with 0

# number to alphabet
n2g = { 0: 'F', 1: 'U', 2: 'TH', 3: 'O', 4: 'R', 5: 'C/K', 6: 'G', 7: 'W', 8: 'H', 9: 'N', 10: 'I', 11: 'J', 12: 'EO', 13: 'P', 14: 'X', 15: 'S/Z', 16: 'T', 17: 'B', 18: 'E', 19: 'M', 20: 'L', 21: 'NG/ING', 22: 'OE', 23: 'D', 24: 'A', 25: 'AE', 26: 'Y', 27: 'IA/IO', 28: 'EA' }

skip = 56
addition = 1

def main():
    counter = 0
    primes = iter( gen_primes() ) 
    parts = open( '56.runes', 'r' ).read().split()
    for rune in parts:
        if rune.isdigit():
            rune = int(rune)
            if counter == skip:
                print counter, ':', n2g[rune], "  (SKIP DECODE)"
                counter=counter+1
                continue
            prime = primes.next();
            print counter, ':', n2g[(rune-prime+addition) % 29]
            counter=counter+1
        else:
            print ":",rune,":"


# Sieve of Eratosthenes
# Code by David Eppstein, UC Irvine, 28 Feb 2002
# http://code.activestate.com/recipes/117119/
def gen_primes():
    """ Generate an infinite sequence of prime numbers.
    """
    D = {}  
    q = 2  
    while True:
        if q not in D:
            yield q        
            D[q * q] = [q]
        else:
            for p in D[q]:
                D.setdefault(p + q, []).append(p)
            del D[q]

        q += 1

# main
main()

