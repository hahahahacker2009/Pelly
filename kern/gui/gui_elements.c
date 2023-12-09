#include "gui.h"

Button init_button(Window window, uint16_t x, uint16_t y, uint16_t len_x, uint16_t len_y, 
                    uint16_t background_color, uint16_t foreground_color, char* title)
{
    Button new;
    new.error = NO_ERROR;

    /* Perform checks */
    if (strlen(title) > (window.len_x - 2))
    {
        new.error = TITLE_BOUNDARY_EXCEEDED;
        return new;
    }

    if (x > (window.x + window.len_x))
    {
        new.error = X_BOUNDARY_EXCEEDED;
        return new;
    }

    if (y > (window.y + window.len_y))
    {
        new.error = Y_BOUNDARY_EXCEEDED;
        return new;
    }

    if (len_x > (window.len_x - 2))
    {
        new.error = LEN_X_BOUNDARY_EXCEEDED;
        return new;
    }

    if (len_y >= (window.len_y - 2))
    {
        new.error = LEN_Y_BOUNDARY_EXCEEDED;
        return new;
    }

    new.x = x;
    new.y = y;

    new.len_x = len_x;
    new.len_y = len_y;
    
    new.background_color = background_color;
    new.foreground_color = foreground_color;
    
    new.title = title;

    return new;
}

void draw_button(Window window, Button button)
{
    /* ******************************** */
    /*          Top border              */
    /* ******************************** */

    move_cursor(window.x + button.x, window.y + button.y);
    
    for (uint16_t i = 0; i < button.len_x; i++)
    {
        printf("%c", 0xC4);
    }

    /* ******************************** */
    /*          Right border            */
    /* ******************************** */

    for (uint16_t i = 1; i < button.len_y; i++)
    {
        move_cursor(window.x + (button.x + button.len_x), window.y + (button.y + i));
        printf("%c", 0xB3);
    }

    /* ******************************** */
    /*          Bottom border           */
    /* ******************************** */

    move_cursor(window.x + button.x, window.y + (button.y + button.len_y));

    for (uint16_t i = 0; i < button.len_x; i++)
    {
        printf("%c", 0xC4);
    }

    /* ******************************** */
    /*          Left border             */
    /* ******************************** */

    move_cursor(window.x + button.x, window.y + button.y);

    for (uint16_t i = 1; i < button.len_y; i++)
    {
        move_cursor((window.x + button.x) - 1, window.y + (button.y + i));
        printf("%c", 0xB3);
    }

    /* ******************************** */
    /*          Title                   */
    /* ******************************** */

    move_cursor(window.x + (button.x + 1), window.y + (button.y + 1));
    printf("%s", button.title);
}

/* ------------------------------------ */

/**
 * Initialize a context menu
 * @param window window element where button will be drawn
 * @param x starting position (x)
 * @param y starting position (y)
 * @param len_x width
 * @param len_y height
 * @param background_color background color
 * @param foreground_color foreground color
 * @param buttons context menu elements in form of buttons
*/
ContextMenu init_context_menu(Window window, uint16_t x, uint16_t y, uint16_t len_x, uint16_t len_y, 
                    uint16_t background_color, uint16_t foreground_color, Button buttons[BUTTON_SIZE])
{
    
}

/**
 * Draw a context menu
 * @param window window where button will be drawn
 * @param button button which will be drawn
*/
void draw_context_menu(Window window, ContextMenu context_menu)
{

}
