#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <ctime>


using namespace sf;

const int H = 22; ///< Height of the tile map
const int W = 25; ///< Width of the tile map
const int ts = 50; ///< Size of each tile

extern float offsetX; ///< X offset for rendering
extern float offsetY; ///< Y offset for rendering

extern bool inMenu; ///< Indicates if the game is in the menu
extern bool game; ///< Indicates if the game is running
extern bool win; ///< Indicates if the player has won the game

extern String TileMap[H]; ///< The tile map array

/**
 * class setSound
 * \brief Manages sound effects and music for the game.
 */
class setSound {
public:
    SoundBuffer b, ca, co, hf, hn, l, s, w;
    Sound bat, cannon, coin, hedoff, hedon, lose, start, win;
    Music music;
    bool stop;

    setSound();
};

extern setSound sound;

/**
 * \class Player
 * \brief Represents the player character in the game.
 */
class Player {
public:
    float dx, dy;
    FloatRect rect;
    Sprite sprite;
    bool left, right, up, down;
    int rotate;

    Player(Texture& image);
    void update(float time);
    void Collision(int dir);
};

/**
 * \class Arrow
 * \brief Represents an arrow projectile in the game.
 */
class Arrow {
public:
    float dx, dy;
    FloatRect rect;
    Sprite sprite;
    int px, py, rotate, timer, Sti;
    bool pusk, shot;

    void set(Texture& image, int x, int y, int r);
    void update(float time);
    void Collision(int dir);
};

/**
 * \class Box
 * \brief Represents a box object in the game.
 */
class Box {
public:
    Sprite sprite;
    int timer = 2000;
    bool big = 0;
    int Bx, By;
    FloatRect rect;

    void set(Texture& image, int x, int y);
    void update();
};

/**
 * \class Bat
 * \brief Represents a bat enemy in the game.
 */
class Bat {
public:
    Sprite sprite;
    FloatRect rect;
    float curFrame, dx, dy;

    void set(Texture& image, int x, int y, bool Cx);
    void update(float time);
    void Collision(int dir);
};

/**
 * \class Menu
 * \brief Manages the game's main menu.
 */
class Menu {
public:
    Menu(RenderWindow& window);
    void draw();
    bool handleInput(Event& event);
    void updateBestTime(std::time_t newTime, bool isWin);

private:
    void showResults();
    std::string formatTime(std::time_t time);

    RenderWindow& window;
    Font font;
    Text startButton;
    Text recordButton;
    Text exitButton;
    Texture menuTexture;
    Sprite menuSprite;
    std::time_t bestTime;
};

/**
 * \class GameTimer
 * \brief Manages the game timer.
 */
class GameTimer {
public:
    GameTimer(RenderWindow& window);
    void start();
    void update();
    void draw();
    std::time_t getElapsedTime() const;

private:
    RenderWindow& window;
    Font font;
    Text timerText;
    std::time_t startTime;
    std::time_t elapsedTime;
};

/**
 * \brief Resets the game state.
 * \param p Reference to the Player object.
 * \param clock Reference to the game clock.
 * \param Picture Reference to the game texture.
 */
void resetGame(Player& p, Clock& clock, Texture& Picture);

#endif GAME_HPP
