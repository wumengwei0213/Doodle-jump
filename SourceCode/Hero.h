#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
#include "./Object.h"
#include <map>
#include <string>

enum class HeroState {
    LEFT,
    RIGHT,
    FRONT,
    BACK,
	HEROSTATE_MAX
};

class Hero : public Object{
public:
    void init();
	void update();
	void draw();
private:
    HeroState state = HeroState::FRONT; // 初始狀態
    double speed = 5; // 初始速度
    std::map<HeroState, std::string> gifPath; // 英雄狀態, 圖片路徑
};

#endif