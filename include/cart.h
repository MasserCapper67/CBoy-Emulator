#pragma once

#include <common.h>

typedef struct {
  u8 entry[4];
  u8 logo[0x30];
  char title[16];
  char new_lic_code[2];  //REMINDER: This string has not null terminator
  u8 sgb_flag;
  u8 cartridge_type;
  u8 rom_size;
  u8 ram_size;
  u8 destination_code;
  u8 lic_code;
  u8 version;
  u8 checksum;
  u16 global_checksum;
} rom_header;

bool cartridge_load(char *cartridge);
