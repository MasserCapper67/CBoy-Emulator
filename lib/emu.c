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
static char *emu_command = "cboy";
static int COMMAND_ERROR = -1;
static int ROM_ERROR = -2;
static int CPU_STEP_ERROR = -3;
static int DEFAULT_EXIT_CODE = 0;

emu_context *emu_get_context() {
  return &context;
}

void delay(u32 ms) {
  SDL_Delay(ms);
}

int emu_run(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <rom_file>\n", emu_command);
    return COMMAND_ERROR;
  }

  if (!cartridge_load(argv[1])) {
    fprintf(stderr, "Failed to load ROM file: %s\n", argv[1]);
    return ROM_ERROR;
  }

  printf("Cart loaded...\n");

  SDL_Init(SDL_INIT_VIDEO);
  printf("SDL INIT\n");
  TTF_Init();
  printf("TTF INIT\n");

  cpu_init();

  context.running = true;
  context.paused = false;
  context.ticks = 0;

  while (context.running) {
    if (context.paused) {
      delay(10);
      continue;
    }

    if (!cpu_step()) {
      fprintf(stderr, "CPU stopped\n");
      return CPU_STEP_ERROR;
    }

    context.ticks++;
  }

  return DEFAULT_EXIT_CODE;
}

