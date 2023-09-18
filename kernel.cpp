/******************************************************************************
\Project MyKernel (Writing my own OS)

\Author : Oussama BOUKSIM

\File : kernel.cpp

\Creation date : 12/02/2023

\Copyright (C) 2023 - All rights reserved.
*******************************************************************************/
#include <Types.h>
/**
 * Display the character in the console
 *
 * @param   str string character
 * @return  void function
 */
void printf(char *str) {
  static unsigned short *VideoMemory = (uint16_t *)0xb8000;

  for (int i = 0; str[i] != '\0'; ++i)
    VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors() {
  for (constructor *i = &start_ctors; i != &end_ctors; i++)
    (*i)();
}

extern "C" void kernelMain(const void *multiboot_structure,
                           uint32_t /*multiboot_magic*/) {
  printf("[Oussama BOUKSIM] Hello World!");
  while (1)
    ;
}