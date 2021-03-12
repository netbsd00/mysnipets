#include <stdio.h>

#define _BSWAP16(w) __asm{ __asm mov ax, w   __asm xchg al, ah   __asm mov w, ax}
#define _BSWAP32(dw) __asm{ __asm mov eax, dw   __asm bswap eax   __asm mov dw, eax}

inline unsigned short bswap16(unsigned short w)
{
	_asm
	{
		mov ax, w
		xchg al, ah
		mov w, ax
	}
	return w;
}

inline unsigned long bswap32(unsigned long dw)
{
	_asm
	{
		mov eax, dw
		bswap eax
		mov dw, eax
	}
	return dw;
}

void main(void)
{
	printf("%08X => %08X\n", 0x12345678, bswap32(0x12345678));
	printf("%08X => %08X\n", bswap32(0x12345678), bswap32(bswap32(0x12345678)));

	printf("%04X => %04X\n", 0x1234, bswap16(0x1234));
	printf("%04X => %04X\n", bswap16(0x1234), bswap16(bswap16(0x1234)));

	unsigned long dw = 0x12345678;
	unsigned short w = 0x1234;

	printf("%08X", dw);
	_BSWAP32(dw);
	printf(" => %08X\n", dw);

	printf("%08X", dw);
	_BSWAP32(dw);
	printf(" => %08X\n", dw);

	printf("%04X", w);
	_BSWAP16(w);
	printf(" => %04X\n", w);

	printf("%04X", w);
	_BSWAP16(w);
	printf(" => %04X\n", w);
}