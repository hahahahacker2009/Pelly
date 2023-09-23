
bits     16
section _TEXT class=CODE

global _init_keyboard
_init_keyboard:
    mov ah, 0x01
    mov cx, 0x10
    int 0x10

    mov cl, 0
    mov bl, 0

;
;   _c_keyboard   ->  get user input (int 0x16) cmp. with characters,
;                       return char to C,
;                         if backspace handle here,
;                         if cursor keys are pressed, assign special value to them and return new value to C
;
global _c_keyboard
_c_keyboard:
    mov ah, 0x00
    int 0x16

    cmp al, 0x08
    je  .backspace

    cmp al, 0x0D
    je  .enterk

    cmp ah, 0x48
    je .up_cursor

    cmp ah, 0x50
    je .down_cursor

    cmp ah, 0x4B
    je .left_cursor

    cmp ah, 0x4D
    je .right_cursor

    mov ah, 0x0e
    int 0x10

    ret

    .backspace:
        mov ah, 0x0e
        mov al, 0x08
        int     0x10

        mov al, ' '
        int     0x10

        mov al, 0x08
        int 0x10

        ret

    .enterk:
        mov ah, 0x0e
        mov al, 0x0a
        int 0x10

        mov ah, 0x0e
        mov al, 0x0D
        int 0x10

        ret

    .up_cursor:
        cmp dl, 0x00
        je  .return

        sub dl, 0x01

        mov ah, 0x02
        mov dh, cl
        mov dl, bl
        int 0x10

        ret

    .down_cursor:
        cmp dl, 24
        je  .return

        add dl, 0x01
        ret

    .left_cursor:
        cmp bl, 0x00
        je  .return

        sub bl, 0x01
        ret

    .right_cursor:
        cmp bl, 79
        je  .return

        add bl, 0x01
        ret

    .return:
        ret

;
;   _clear_screen -> clears the screen (80x25 res.), disable blinking
;                    sets the color of the background & foreground
;                    https://en.wikipedia.org/wiki/BIOS_color_attributes
;
global  _clear_screen
_clear_screen:
    
    mov     ax, 0x03
    int         0x10

    ;   Stop blinking (for full 16-colors)
    mov     ax, 1003h
    mov     bx, 0
    int         0x10

    mov     ah, 09h
    mov     cx, 2000d
    mov     al, 20h
    mov     bl, 0x1F
    int         0x10

    ret
