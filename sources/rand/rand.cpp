/**
 * @author Emanuel Komínek <drake127@planescape.cz>
 * @license Public Domain
 * @file
 */

#include <ctime>
#include <random>

/**
 * @brief Replaces C rand() function with ranlux48 generator.
 *
 * The function generates a random number between 0 and 2147480999 which guarantees no bias for most moduli used in D&D
 * rolls.
 */
extern "C" int rand() __THROW
{
	static std::ranlux48 generator(time(nullptr));
	static std::uniform_int_distribution<unsigned int> distribution(0, 2147480999);
	return distribution(generator);
}
