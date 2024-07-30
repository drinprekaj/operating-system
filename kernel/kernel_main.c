// kernel_main.c

void kernel_main() {
    // Kernel main function
    // Initialize screen and print a message

    init_screen();
    print_string("Welcome to My OS!");

    // Hang the system for now
    while (1) {
        asm("hlt");
    }
}

void init_screen() {
    // Screen initialization code goes here
}

void print_string(const char *str) {
    // Print string to screen function
}
