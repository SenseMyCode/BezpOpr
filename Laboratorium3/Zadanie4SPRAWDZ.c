// Zadanie 4 (wersja Windows)
// Generowanie pseudolosowego klucza preKey[16] w pamieci zablokowanej (VirtualLock)
// i zerowanie jej na koniec.
// kompilacja: gcc zadanie4_windows.c -o zadanie4.exe   (MinGW)
//         lub: cl zadanie4_windows.c                  (Visual Studio)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// wszystkie zmienne ktore maja cos wspolnego z kluczem trzymam w jednej
// strukturze, zeby siedzialy w jednym miejscu i dalo sie je zablokowac
struct dane {
    char preKey[16];
    unsigned int seed;
    int i;
};

// prosty generator LCG - stan trzymam w strukturze, a nie gdzies w bibliotece
// (jakosc losowosci nie jest oceniana)
unsigned char losuj(unsigned int *seed)
{
    *seed = *seed * 1103515245 + 12345;
    return (unsigned char)(*seed >> 16);
}

int main()
{
    // zeby nie wyskakiwalo okno bledu z mozliwoscia zrobienia zrzutu pamieci
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);

    SYSTEM_INFO si;
    GetSystemInfo(&si);
    SIZE_T rozmiar = si.dwPageSize;   // cala strona, zeby blokowac tylko moje dane

    // powiekszenie working set, inaczej VirtualLock moze sie nie udac
    SIZE_T minWS, maxWS;
    GetProcessWorkingSetSize(GetCurrentProcess(), &minWS, &maxWS);
    SetProcessWorkingSetSize(GetCurrentProcess(), minWS + rozmiar, maxWS + rozmiar);

    struct dane *d = (struct dane *)VirtualAlloc(NULL, rozmiar,
                                                 MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (d == NULL) {
        printf("blad VirtualAlloc\n");
        return 1;
    }

    // VirtualLock - strona zostaje w RAM, nie idzie do pliku wymiany
    if (!VirtualLock(d, rozmiar)) {
        printf("blad VirtualLock\n");
        VirtualFree(d, 0, MEM_RELEASE);
        return 1;
    }

    // generowanie bitow
    d->seed = (unsigned int)time(NULL) ^ GetCurrentProcessId();
    for (d->i = 0; d->i < 16; d->i++)
        d->preKey[d->i] = losuj(&d->seed);

    // wypisanie zeby bylo widac ze dziala
    printf("preKey: ");
    for (d->i = 0; d->i < 16; d->i++)
        printf("%02x", (unsigned char)d->preKey[d->i]);
    printf("\n");

    // koniec - zerowanie (SecureZeroMemory nie zostanie wyciete przez kompilator),
    // odblokowanie i zwolnienie pamieci
    SecureZeroMemory(d, rozmiar);
    VirtualUnlock(d, rozmiar);
    VirtualFree(d, 0, MEM_RELEASE);

    printf("pamiec wyzerowana\n");
    return 0;
}