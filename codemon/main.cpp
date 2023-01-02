#include <SFML/Graphics.hpp>

#include "character.h"
#include "map.h"
#include "Window.h"
#include "direction.h"

#include <list>
#include <string>

//Convert the key input into direction input
DIR convert_key_event(sf::Event *event) {
    DIR input_dir = DIR::NONE;

    //Recode event as a input direction for game state.
    //Up was pressed
    if (event->key.code == sf::Keyboard::W) {
        input_dir = DIR::N;
    }
    //Down was pressed
    else if (event->key.code == sf::Keyboard::S) {
        input_dir = DIR::S;
    }
    //Left was pressed
    else if (event->key.code == sf::Keyboard::A) {
        input_dir = DIR::W;
    }
    //Right was pressed
    else if (event->key.code == sf::Keyboard::D) {
        input_dir = DIR::E;
    }
    return input_dir;
}

//Welcome to Codemon!
int main()
{
    //Main Screen declaration. Right now its a 16x16 grid of 32 px tiles
    Window scr(32*16, 32 * 16, "Codemon!");

    //Just keep track of all the windows created
    std::list<Window> windows_list;
    windows_list.push_front(scr);

    //Create Test player character
    Character player;
    player.load_sprite_sheet();

    //Load in test map
    Map game_map("maps/map_00.txt", "maps/map_set/map_00.png");

    //Flag declarations
    bool key_input = false;
    DIR input_dir = NONE;

    //So long as the active_window is still open.
    while (scr.get_window()->isOpen())
    {   
        //Create a storage event for processing system/input events
        sf::Event event;
        while (scr.get_event(&event))
        {
            //If the player has closed the game
            switch (event.type) {
            //Close button clicked
            case sf::Event::Closed:
                scr.close();
                break;
            //A keyboard key has been pressed
            case sf::Event::KeyPressed:
                key_input = true;
                input_dir = convert_key_event(&event);
                break;
            }
        }
        /*
        Process Game State + Input 
        */

        //If a keyboard input was pressed
        if (key_input && input_dir != DIR::NONE) {
            //Check bounds and if fine move. 
            game_map.in_bounds(player.move_cord(input_dir));

            player.move(input_dir);
            player.update_sprite_pos();

            //Reset the flags
            key_input = false;
            input_dir = DIR::NONE;
        }

        /*
        Render loop portion
        */

        scr.clear();
        //draw the sprite to the window
        game_map.render_map(&scr);
        scr.draw(&player);


        //Update the window to draw stuff
        scr.display();
    }

    return 0;
}
