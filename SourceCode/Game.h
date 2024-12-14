#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <allegro5/allegro.h>
#include "UI.h"

/**
 * @brief Main class that runs the whole game.
 * @details All game procedures must be processed through this class.
 */
class Game
{
public:
	void execute();
public:
	Game();
	~Game();
	void game_init();
	bool game_update();
	void game_draw();
private:
	/**
	 * @brief States of the game process in game_update.
	 * @see Game::game_update()
	 */
	enum class STATE {
		/* ---- Revise start ---- */
		MENU, // -> START
		/* ---- Revise end ---- */
		START, // -> LEVEL
		LEVEL, // -> PAUSE, END
		PAUSE, // -> LEVEL
		END
	};
	STATE state;
	ALLEGRO_EVENT event;
	ALLEGRO_BITMAP *game_icon;
	ALLEGRO_BITMAP *background;
	/* ---- Revise start ---- */
	ALLEGRO_BITMAP *menu;
	ALLEGRO_BITMAP *play;
	float y_offset = 0;			// 背景圖片的 Y 偏移量
	bool is_moving = false;		// 是否正在移動
	float target_offset = 0;	// 目標的 Y 偏移量
	const float move_speed = 5; // 每幀移動的距離
	/* ---- Revise end ---- */
private:
	ALLEGRO_DISPLAY *display;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *event_queue;
	UI *ui;
};

#endif
