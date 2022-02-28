
#include <stdio.h>

int main(int argc, char* argv[])
{
	int n = 0;
	unsigned char *vram = (unsigned char *)0xFECA0000;
	for (int i = 0;i < 512;i++) vram[i] = i;
}