/**
 * @author Emanuel Komínek <drake127@planescape.cz>
 * @license Public Domain
 * @file
 */

#include <intrin.h>

bool rdrand_supported()
{
	int registers[4];
	__cpuid(registers, 1);
	return registers[2] & (1 << 30);
}

bool rdrand_sensible()
{
	for (int i = 0; i < 10; ++i)
	{
		unsigned int rand;
		if (!_rdrand32_step(&rand))
			break;
		if (rand != 0xFFFFFFFF && rand != 0x00000000)
			return true;
	}

	return false;
}

int main()
{
	return !(rdrand_supported() && rdrand_sensible());
}
