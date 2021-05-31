# Eneas Operating System (EneasOS)

This an operating system based on the library Circle by René Stange(rsta2) https://github.com/rsta2/circle/tree/develop example 21 web-server. Deploy in a Raspberry Pi 4 64bits 4GB RAM. In this repository the OS is not build yet, is neccesary the compilation of the following files to build the .img of the project and deploy into the Raspberry Pi. If you need more information about this library you are welcome to read the documentation that René Stange give it to us in his repository.

## Pre requirements

  0. A linux PC or an OS with UNIX, because is makes more easier to create the OS.

  1. Is mandatory to download or clone first the repository of circle to work with the project.
  ```
  git clone https://github.com/rsta2/circle/tree/develop
  ```

  2. Download the toolchain for Raspberry Pi 4 arch64 bits, can be downloaded [here](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-a/downloads).
  You can find more information in this article about AArch64 in Circle https://github.com/rsta2/circle/tree/develop#aarch64

  3. Download [Raspberry Pi Imager](https://www.raspberrypi.org/software/), is neccesary to install OS inside the SD card.

## Instalation

1. Clone the EneasOS repository and save it into the samples file in the circle library.
  ```
  git clone https://github.com/rsta2/circle/tree/develop
  ```
2. Go to the main file in the circle library.

3. Edit the file *Rules.mk* and set the Raspberry Pi architecture (*AARCH*, 32 or 64) and the *PREFIX64* of your toolchain commands. The *RASPPI* variable has to be set to 3 or 4 for `AARCH = 64`. Alternatively you can create a *Config.mk* file (which is ignored by git) and set the Raspberry Pi architecture and the *PREFIX64* variable to the prefix of your compiler like this (don't forget the dash at the end):

```
AARCH = 64
RASPPI = 3
PREFIX64 = aarch64-none-elf-
```

The configuration file *Config.mk* can be created using the `configure` tool too. Please enter `./configure -h` for help on using it!

Then go to the build root of Circle and do:

```
./makeall clean
./makeall
```

By default only the latest sample (with the highest number) is build. The ready build *kernel8.img* or *kernel8-rpi4.img* file should be in its subdirectory of sample/. If you want to build another sample after `makeall` go to its subdirectory and do `make`.

Taken by: https://github.com/rsta2/circle/tree/develop#aarch64

4. Now we got all the files compiled! Then we move to install into the SD to deploy in the Raspberry Pi

### SD Card instalation
There are several way to install the Operating System inside the SD, the way that we use is the simpler one.

1. Insert the SD card into your computer an Open Raspberry Pi Imager

2. Select you SD card

3. Install the Raspberry Pi 64 bits Operating System

4. After finish the instalation, open the files of the SD card and paste inside the boot file. The archive kernel8.img of created previosly in the circle build

5. Once you pasted the Operating System is ready to be used!

## Create your own page

**Before creating your own page is MANDATORY to read the instalation and do it step by step.**

Is simple to create your own static page for this OS, the first thing is to replace those images, .html, .css and .js files of this project and paste your ones.

Once pasted in the folder go into Makefile, and modify the content with the name of yours files and the extension of .h, if you need to add a file different to html, css, jpg, jpeg and png you can added by modifing into the Makefile and adding the extension, for example:
```
%.h: %.js
	@echo "  GEN   $@"
	@$(CIRCLEHOME)/tools/converttool $< > $@
```
After edit the Makefile, go to the webserver.cpp file, and replace or delete the functions with our respective files, for example:
```
static const u8 s_Amstrong[] =
{
#include "amstrong.h"
};

static const u8 s_Example[] =
{
#include "example.h"
};
```
and edit all the variables that depends of this functions
```
else if (strcmp (pPath, "/amstrong.jpeg") == 0)
	{
		pContent = s_Amstrong;
		nLength = sizeof s_Amstrong;
		*ppContentType = "image/jpeg";
	}
  
  else if (strcmp (pPath, "/example.js") == 0)
	{
		pContent = s_Example;
		nLength = sizeof s_Example;
		*ppContentType = "text/js";
	}
```
Once all the modification is finished, you can proceed to build this project, _I recomment to copy all the files and paste it into a folder inside the project, called Old or Saved in case of any error_

Proceed to the terminal and write `make` this command will create all the libraries, and archives .O need it to use the .img.

Once is the complied is successful, copy the image kernel8.img and paste it into the SD Card boot folder.

That's all, you can prove that the OS works that way.

## Authors

_We are students of the Universidad del Norte, studying CS and this project is Our I+D in the subject Operating System, my Team is formed by:_

* **Luis Llanos** - *Developer* - [avilezf](https://github.com/avilezf)
* **Andrés Prieto** - *Manager* - [luquef](https://github.com/luquef)
* **Joshua Angarita** - *Testing* - [ajoshua](https://github.com/ajoshua)
* **Fulanito Detal** - *Docs* - [amstrong](#https://github.com/amstrong)


## License 

This project is made by using the library of Circle. This is an academic project and this OS is not available to use commercially

## Specials thanks to

* Fabricio Puche and Samir Pérez for the infomation about Circle Library
* My Father and Mother to give me support any time I need it
* Pedro Wightman to give us the oportunity to experiment in this field

