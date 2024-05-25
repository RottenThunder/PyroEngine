# PyroEngine ![](https://img.shields.io/github/license/RottenThunder/PyroEngine "PyroEngine is licensed under the EPL-2.0 License")

## 2D Game Engine

Pyro Engine is a specialised 2D game engine that is currently in development, awaiting it's first release. The engine uses OpenGL as it's rendering API and the platforms that will be supported upon release will be Windows & Linux.

## Obtaining the Engine

Currently there is no pre-built binaries, so as of now the only option is to compile from source

### Compiling from source

The project uses [Premake](https://premake.github.io/) as it's build system and is considered as a crucial dependency. You can download the prebuilt binaries for it [here](https://premake.github.io/download). Make sure to use the ones that are specific to the platform you are compiling on. Then clone the repository with ```git clone https://github.com/RottenThunder/PyroEngine``` and put the premake binary within the same folder that you cloned the project in. If you are on Linux you will need to make sure that you are using the X11 windowing system (rather than Wayland) and call the following command before continuing, to install neccessary dev packages - ```sudo apt install make g++ xorg-dev```. Then change your active directory to the one you cloned then call ```premake5 vs2022``` if you are on Windows or ```premake5 gmake2``` if you are on Linux. If you are on Windows then this would of made a visual studio solution file for you to compile it with MSVC. If you are on Linux this would of made a Makefile for you to call ```make config=release``` to compile it with the g++ compiler. Once compiled, the final build can be found within the Bin/FinalBuild folder.

***

![](https://img.shields.io/github/repo-size/RottenThunder/PyroEngine) ![](https://img.shields.io/github/languages/code-size/RottenThunder/PyroEngine)