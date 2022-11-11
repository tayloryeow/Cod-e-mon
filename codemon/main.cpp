#include <SFML/Graphics.hpp>

#include "character.h"
#include "map.h"
#include "Window.h"

#include <list>
#include <string>


int main()
{

    //Main Screen decleration.  
    Window scr(32*16, 32 * 16, "Codemon!");

    //Just keep track of all the windows created - maybe make this into a window manager
    std::list<Window> windows_list;
    windows_list.push_front(scr);

    //Create Test player character
    Character player;
    player.load_sprite_sheet();

    //Load in test map
    Map game_map("maps/map_00.txt", "maps/map_set/map_00.png");

    while (scr.get_window()->isOpen())
    {
        sf::Event event;
        while (scr.get_event(&event))
        {
            //If the player has closed the game
            switch (event.type) {
            case sf::Event::Closed:
                scr.close();
                break;
                //If a key was pressed
            case sf::Event::KeyPressed:

                //Up was pressed
                if (event.key.code == sf::Keyboard::W) {
                    player.move_y(-32);
                    player.update_sprite_pos();
                }
                //Down was pressed
                else if (event.key.code == sf::Keyboard::S) {
                    player.move_y(32);
                    player.update_sprite_pos();
                }
                //Left was pressed
                else if (event.key.code == sf::Keyboard::A) {
                    player.move_x(-32);
                    player.update_sprite_pos();
                }
                //Right was pressed
                else if (event.key.code == sf::Keyboard::D) {
                    player.move_x(32);
                    player.update_sprite_pos();
                }   
                break;
            }
        }

        scr.clear();
        //draw the sprite to the window
        game_map.render_map(&scr);
        scr.draw(&player);


        //Update the window to draw stuff
        scr.display();
    }

    return 0;
}
