#include <stdio.h>
#include <emu.h>
#include <cart.h>
#include <cpu.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


/*
 *  EMU COMPONENTS:
 *
 *    |Cart|
 *    |CPU|
 *    |Address Bus|
 *    |PPU|
 *    |Timer|
*/


static emu_context context;

emu_context *emu_get_context() {
  return &context;
}

void delay(u32 ms) {
  SDL_delay(ms);
}

int emu_run(int argc, char **argv) {

}
