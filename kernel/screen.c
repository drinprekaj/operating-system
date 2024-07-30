// screen.c

#include "screen.h"

volatile uint16_t* video_memory = (uint16_t*)0xB8000;
int cursor_x = 0;
int cursor_y = 0;

void init_screen() {
    // Screen initialization (clear screen, set cursor position, etc.)
    clear_screen();
}

void clear_screen() {
    // Clear the entire screen
    for (int i = 0; i < 80 * 25; ++i) {
        video_memory[i] = (video_memory[i] & 0xFF00) | ' ';
    }
    cursor_x = 0;
    cursor_y = 0;
}

void print_char(char character, int x, int y) {
    // Print a character at the given position
    int index = y * 80 + x;
    video_memory[index] = (video_memory[index] & 0xFF00) | character;
}

void print_string(const char *str) {
    // Print a null-terminated string starting at the current cursor position
    while (*str != '\0') {
        if (*str == '\n') {
            cursor_x = 0;
            cursor_y++;
        } else {
            print_char(*str, cursor_x, cursor_y);
            cursor_x++;
            if (cursor_x >= 80) {
                cursor_x = 0;
                cursor_y++;
            }
        }
        str++;
    }
}

void kernel_main() {
    // Kernel main function
    init_screen();
    print_string("Welcome to My OS!\n");
    print_string("Initializing kernel...\n");

    // Further kernel initialization goes here

    // Hang the system for now
    while (1) {
        asm("hlt");
    }
}
