#ifndef BASIC_H
#define BASIC_H

#define ZOMBIE_APPEAR_SPEED (15 * 600 / 33) //僵尸产生速度
#define CELL_HIGHT 98 //cell的高度
#define CELL_WEIGHT  //cell的宽度
#define MAP_Y 130 //map起始的纵坐标
#define MOWER_X 210  //割草机的横坐标

//僵尸的状态
#define ZOM_MOVE 0
#define ZOM_ATK 1
#define ZOM_DIE 2

//爆炸状态
#define BOMB_PRE 0
#define BOMB_REA 1
#define BOMB_BOMB 2

#define PUMPKIN_HP 2200

#define atk_speed(x) int(x * 1000 / 33)
#define attack(x) int(x * 33 / 1000)
#define sped(x) (80.0 * 33 / 1000 / x)

#endif // BASIC_H
