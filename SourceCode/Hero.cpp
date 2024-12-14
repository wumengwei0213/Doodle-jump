#include "Hero.h"
#include <cstdio>
#include "./data/DataCenter.h" // We will need width and height of the game window
#include "./data/GIFCenter.h" // We will get GIF data from here
#include "./shapes/Rectangle.h"

namespace HeroSetting {
	static constexpr char gif_root_path[40] = "./assets/gif/Hero";
	static constexpr char gif_postfix[][10] = {
		"left", "right", "front", "back"
	};
}

void Hero::init(){
    for (size_t type = 0; type < static_cast<size_t>(HeroState::HEROSTATE_MAX); ++type) {
        // Update real hit box for monster.
        char buffer[50];
        sprintf(
            buffer, "%s/dragonite_%s.gif",
            HeroSetting::gif_root_path,
            HeroSetting::gif_postfix[static_cast<int>(type)]);
        gifPath[static_cast<HeroState>(type)] = std::string(buffer);
    }
    DataCenter *DC = DataCenter::get_instance();
    GIFCenter *GIFC = GIFCenter::get_instance();
    // see monsters\Monster.cpp 148
    ALGIF_ANIMATION *gif = GIFC->get(gifPath[HeroState::FRONT]);

    shape.reset(new Rectangle(
        DC->window_width / 2, // the x of the top left corner
        DC->window_height / 2, // the y of the top left corner
        DC->window_width / 2 + gif->width, // the x of the bottom right corner
        DC->window_height / 2 + gif->height // the y of the bottom right corner
    ));
}
void Hero::update(){
    DataCenter *DC = DataCenter::get_instance();
    // position of window
        // if go up, then y value decreases.
        // if go right, then x value increase. 
    if (DC->key_state[ALLEGRO_KEY_W]) // go up
    {
        shape->update_center_y(shape->center_y() - speed); 
        state = HeroState::BACK; // go up
    } 
    else if (DC->key_state[ALLEGRO_KEY_A]) // go left
    {
        shape->update_center_x(shape->center_x() - speed);
        state = HeroState::LEFT; // go left
    }
    else if (DC->key_state[ALLEGRO_KEY_S]) // go down
    {
        shape->update_center_y(shape->center_y() + speed); 
        state = HeroState::FRONT; // go down
    }
    else if (DC->key_state[ALLEGRO_KEY_D]) // go right
    {
        shape->update_center_x(shape->center_x() + speed);
        state = HeroState::RIGHT; // go right
    }
}
void Hero::draw(){
	GIFCenter *GIFC = GIFCenter::get_instance();
	ALGIF_ANIMATION *gif = GIFC->get(gifPath[state]);
	algif_draw_gif(
		gif,
		shape->center_x() - gif->width / 2, // x of upper left corner
		shape->center_y() - gif->height / 2, // y of upper left corner
        0);
}