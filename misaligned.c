#include <stdio.h>
#include <assert.h>
#include <string.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

struct ColorPairInfo
{
    int pairNumber;
    char MajorColorName[15];
    char MinorColorName[15];
};

ColorPairInfo colorpairinfo [25];
void printToConsole(int MajorColorIndex, int MinorColorIndex);

int printColorMap() {
    
    int i = 0, j = 0, index=0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
           colorpairinfo [index].pairNumber = i*5+j;
            strcpy(colorpairinfo [index].MajorColorName, majorColor[i]);
            strcpy(colorpairinfo [index].MinorColorName, minorColor[j]);
            printToConsole (i,j);
            index++;
        }
    }
    return i * j;
}

void printToConsole(int MajorColorIndex, int MinorColorIndex)
{
    printf("%d | %s | %s\n", MajorColorIndex * 5 + MinorColorIndex, majorColor[MajorColorIndex], minorColor[MinorColorIndex]);
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    assert(colorpairinfo [0].pairNumber == 0);
    assert(strcmp(colorpairinfo [0].MajorColorName,"White") == 1);
    assert(strcmp(colorpairinfo [0].MinorColorName,"Blue") == 1);
    return 0;
}
