/*
 * Transposition cipher cracker
 *
 * Algorithm used to find keys:
 *
 * n = keylength
 * t = textlength
 * a = t / n
 * b = t % n
 * d = accumulated rest terms
 * k = wanted plain text position
 * loc(k) = a * perm(k % n) + d(perm(k % n)) + k/n
 *
 * By Ben Ruijl, 2009
 *
 * compile: g++ -O2 col.cpp
*/

#include <stdio.h>
#include <string.h>

#define MAXKEY 20

const char* buffer = "IDGTKUMLOOARWOERTHISUTETLHUTIATSLLOUIMNITELNJ7TFYVOIUAUSNOCO5JI4MEODZZ";

int buflength;
const char* crib = "ULTIMATE";
int criblength;

void print(int* perm, int n)
{
    int a = buflength / n;
    int b = buflength % n;
    int i;

    //invert perm
    int invperm[MAXKEY];

    for (i = 0; i < n; i++)
        invperm[perm[i]] = i;

    int d[MAXKEY] = {0};
    for (i = 1; i < n; i++)
    {
        d[i] = d[i -1];

        if (invperm[i - 1] < b)
            d[i]++;
    }

    printf( "Found: " );
    fflush(stdout);

    for (i = 0; i < buflength; i++)
        printf( "%c", buffer[a * perm[i % n] + d[perm[i % n]] + i / n] );
        fflush(stdout);

    printf( "\n" );
}


int checkperm(int* perm, int n)
{
    int cribpos = 0;
    int a  = buflength / n;
    int b = buflength % n;
    int i;

    //invert perm
    int invperm[MAXKEY];

    for (i = 0; i < n; i++)
        invperm[perm[i]] = i;

    int d[MAXKEY] = {0};
    for (i = 1; i < n; i++)
    {
        d[i] = d[i -1];

        if (invperm[i - 1] < b)
            d[i]++;
    }


    for (i = 0; i < buflength; i++)
    {
        if (buffer[a * perm[i % n] + d[perm[i % n]] + i / n] == crib[cribpos])
            cribpos++;
        else
            cribpos = 0;

        if (cribpos == criblength)
        {
            print(perm, n); // print the found text
            return 1;
        }
    }

    return 0;
}

// University of Exeter algorithm
// a fast algorithm, we don't care about sorting it like a dictionary
void permute(int *v, const int start, const int n)
{
    int i;

    if (start == n - 1)
        checkperm(v, n);
    else
    {
        for (i = start; i < n; i++)
        {
            int tmp = v[i];

            v[i] = v[start];
            v[start] = tmp;
            permute(v, start + 1, n);
            v[start] = v[i];
            v[i] = tmp;
        }
    }
}

int main(int argv, char** argc)
{
    int perm[MAXKEY];
    int i;

    for (i = 0; i < MAXKEY; i++)
        perm[i] = i;

    buflength = strlen(buffer);
    criblength = strlen(crib);

    int curkey = 14; // start key

    while (curkey < MAXKEY)
    {
        printf( "Testing key %d\n", curkey );
        fflush(stdout);
        permute(perm, 0, curkey); // permutate keys
        curkey++;
    }

    return 0;
}
