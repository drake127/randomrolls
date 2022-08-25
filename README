Improve randomness of dice rolls
================================

This mod aims to fix randomness of dice rolls in Enhanced Editions of Infinity
Engine games. This includes BG:EE, BG2:EE, IWD:EE and PST:EE.

This issue was discovered using Faydark's Autoroller (now part of EE UI Tweaks)
where it takes just several minutes to notice odd results (repeating ability
scores or same exceptional strength). It was discovered that the games are using
plain rand() function from C library which is now deemed insufficient for any
advanced use.

The Autoroller makes this issue apparent as random numbers start to repeat, at
least on Windows. I believed that the games deserve better random number
generator so I have decided to create this mod that replaces original rand()
function with RDRAND instruction.

RDRAND is provided by CPU and its support was added in AMD Zen (2015) and Intel
Ivy-Bridge (2012) processors. So this mod will not work for owners of older
processors. It was not my first choice but I had to fit the code in 33 bytes
that are available in PST:EE. Also, only Windows binaries are currently
supported.

The mod currently consists of single component:
  - Improve randomness of dice rolls:
      Detects CPU support for RDRAND instruction and patches your game binary
      to use it instead of rand().


Version History:
  - 1.0: Initial release

Author: Emanuel Komínek <drake127@planescape.cz>
