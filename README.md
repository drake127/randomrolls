Infinity Engine Mod: Random rolls using RDRAND
==============================================

This mod aims to fix randomness of dice rolls in Enhanced Editions of Infinity
Engine games. This includes BG:EE, BG2:EE (including EET), IWD:EE and PST:EE.

This issue was discovered using Faydark's Autoroller (now part of
[EE UI Tweaks](https://github.com/r-e-d/EEUITweaks)) where it takes just several
minutes to notice odd results (repeating ability scores or same exceptional
strength). It was discovered that the games are using plain rand() function
from C library which is now deemed insufficient for any advanced use.

The Autoroller makes this issue apparent as random numbers start to repeat, more
notably on Windows platform. I believed that the games deserve better random
number generator so I have decided to create this mod. Its form differs
depending on a platform.

Windows
-------

On Windows, it is the standard WeiDU mod that replaces original rand() function
with RDRAND instruction.

RDRAND is provided by CPU and its support was added in AMD Zen (2015) and Intel
Ivy-Bridge (2012) processors. Therefore this mod will not work for owners of
older processors. It was not my first choice but I had to fit the code in 33
bytes that are available in PST:EE. Also, only Windows binaries patched to
version 2.6 (for BG/BG2/EET/IWD) or version 3.1.3/3.1.4 (for PST) are currently
supported.

The mod consists of single component:
  - Improve randomness of dice rolls:
      Detects CPU support for RDRAND instruction and patches your game binary to
      use it instead of rand().

Linux
-----

There's no need for an actual mod in Linux. The package distributes a simple
library _rand.so_ which can be preloaded to a game binary.

E.g.: `LD_PRELOAD=rand.so ./BaldursGate`

Version History:
  - 1.1: Added Linux support
  - 1.0: Initial release

Author: Emanuel Komínek <drake127@planescape.cz>
