# NXEngine-evo

This is a somewhat upgraded/refactored version of [nxengine](http://nxengine.sourceforge.net/)

[![Build Status](https://travis-ci.org/isage/nxengine-evo.svg?branch=master)](https://travis-ci.org/isage/nxengine-evo) [![Build status](https://ci.appveyor.com/api/projects/status/csoc1fkqkxoajk64/branch/master?svg=true)](https://ci.appveyor.com/project/isage/nxengine-evo/branch/master)

![Screenshot](https://raw.githubusercontent.com/isage/nxengine-evo/master/screenshot.png)

* [Differences](#differences-from-original-nxengine)
* [Building](#building)
* [Running](#running)

## Differences from original nxengine:

* Port to SDL2 ( thanks to https://github.com/PIlin/NXEngine-iOS )
* More resolutions and widescreen support up to FullHD (thanks to https://github.com/EXL/NXEngine )
* Fullscreen for any resolution
* Gamepad with force-feedback support.
* Mimiga mask ending pictures (re-drawn by me)
* Modern main menu
* Header-dependency hell cleaned up. No more autogenerated headers
* Cleaned up nx.h
* Lists/maps from haiku replaced with std::vector/map
* smalfont -> smallfont
* removed built-in data extractor
* removed replays, as they were buggy/not implemented anyway
* fixed tons of warnings and undefined behaviour

## Building
* [Linux](https://github.com/isage/nxengine-evo/wiki/Building-linux-version)
* [Windows](https://github.com/isage/nxengine-evo/wiki/Building-windows-version)
* [OSX](https://github.com/isage/nxengine-evo/wiki/Building-OSX-version)


## Running
 * For source builds see [Running](https://github.com/isage/nxengine-evo/wiki/Running) on wiki.
 * or just use prepackaged [releases](https://github.com/isage/nxengine-evo/releases)
   (OSX builds are done on 10.10, so that's a minimum requirement, windows builds require [MSVC2015 runtime](https://www.microsoft.com/en-us/download/details.aspx?id=53587)

Look in TODO.md for upcoming features

May (and most definitely) contain bugs.
