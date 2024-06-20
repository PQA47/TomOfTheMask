#include "Game.h"

/**
 * \brief Main function of the game.
 * Initializes the game window, loads textures, sets up game objects, and handles the game loop.
 * \return 0 on successful execution.
 */
int main() {
    RenderWindow window(VideoMode(500, 700), "Tomb of the Mask!");

    Texture t;
    t.loadFromFile("Game/Paint/title.png");
    Sprite title(t);

    Texture Picture;
    Picture.loadFromFile("Game/Paint/player.png");
    Player p(Picture);

    Texture bt;
    bt.loadFromFile("Game/Paint/bat.png");
    Bat bat[4];
    bat[0].set(bt, ts * 8, ts * 15, false);
    bat[1].set(bt, ts * 16, ts * 7, true);
    bat[2].set(bt, ts * 16, ts * 13, true);
    bat[3].set(bt, ts * 20, ts * 12, false);

    Texture b;
    b.loadFromFile("Game/Paint/box.png");
    Box box[2];
    box[0].set(b, ts * 21, ts * 18);
    box[1].set(b, ts * 19, ts);

    Texture pu;
    pu.loadFromFile("Game/Paint/pula.png");
    Arrow pula[6];
    pula[0].set(pu, ts * 11, ts * 12, 1);
    pula[1].set(pu, ts * 11, ts * 10, 1);
    pula[2].set(pu, ts * 17, ts * 10, 2);
    pula[3].set(pu, ts * 17, ts * 16, 2);
    pula[4].set(pu, ts * 12, ts * 1, 3);
    pula[5].set(pu, ts * 13, ts * 3, 4);

    Clock clock;

    Texture yl;
    yl.loadFromFile("Game/Paint/youlose.png");
    Sprite youlose(yl);
    youlose.setPosition(100, 210);

    Texture wn;
    wn.loadFromFile("Game/Paint/youwin.png");
    Sprite youwin(wn);
    youwin.setPosition(100, 350);

    Menu menu(window);
    GameTimer gameTimer(window);
    bool inMenu = true;

    sound.music.play();

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (inMenu) {
                if (menu.handleInput(event)) {
                    inMenu = false;
                    resetGame(p, clock, Picture);
                    sound.start.play();
                    gameTimer.start();
                }
            }
            else {
                if (event.type == Event::KeyPressed && p.dx == 0 && p.dy == 0) {
                    if (event.key.code == Keyboard::D) {
                        p.dx = 1;
                        p.left = p.up = p.down = false;
                        p.right = true;
                        sound.coin.play();
                    }
                    if (event.key.code == Keyboard::A) {
                        p.dx = -1;
                        p.right = p.up = p.down = false;
                        p.left = true;
                        sound.coin.play();
                    }
                    if (event.key.code == Keyboard::W) {
                        p.dy = -1;
                        p.right = p.left = p.down = false;
                        p.up = true;
                        sound.coin.play();
                    }
                    if (event.key.code == Keyboard::S) {
                        p.dy = 1;
                        p.right = p.left = p.up = false;
                        p.down = true;
                        sound.coin.play();
                    }
                }
                if ((event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) ||
                    (!game || win)) {
                    gameTimer.update();
                    menu.updateBestTime(gameTimer.getElapsedTime(), win);
                    inMenu = true;
                    resetGame(p, clock, Picture);
                    sound.music.play();
                }
            }
        }

        if (!inMenu) {
            for (int i = 0; i < 4; i++)
                if (p.rect.intersects(bat[i].rect))
                    game = false;

            for (int i = 0; i < 6; i++)
                if (pula[i].pusk && p.rect.intersects(pula[i].rect))
                    game = false;

            for (int i = 0; i < 2; i++)
                if (box[i].big == 1 &&
                    box[i].rect.left <= p.rect.left && p.rect.left <= box[i].rect.left + 2 * ts &&
                    box[i].rect.top <= p.rect.top && p.rect.top <= box[i].rect.top + 2 * ts)
                    game = false;

            if (p.rect.left > 250 && p.rect.left < 1000)
                offsetX = p.rect.left - 250;
            if (p.rect.top > 250 && p.rect.top < 1500)
                offsetY = p.rect.top - 250;

            if (!game && !sound.stop) {
                sound.lose.play();
                sound.stop = true;
            }

            if (game && !win) {
                for (int i = 0; i < 4; i++)
                    bat[i].update(time);
                p.update(time);
                for (int i = 0; i < 2; i++)
                    box[i].update();
                for (int i = 0; i < 6; i++)
                    pula[i].update(time);
            }
            gameTimer.update();
        }

        window.clear(Color::Transparent);

        if (inMenu) {
            menu.draw();
        }
        else {
            for (int i = 0; i < H; i++)
                for (int j = 0; j < W; j++) {
                    if (TileMap[i][j] == 'A')
                        title.setTextureRect(IntRect(0, 0, ts, ts));
                    if (TileMap[i][j] == 'B')
                        title.setTextureRect(IntRect(ts, 0, ts, ts));
                    if (TileMap[i][j] == 'C')
                        title.setTextureRect(IntRect(ts * 2, 0, ts, ts));
                    if (TileMap[i][j] == 'D')
                        title.setTextureRect(IntRect(0, ts * 2, ts, ts));
                    if (TileMap[i][j] == 'E')
                        title.setTextureRect(IntRect(ts * 3, 0, ts, ts));
                    if (TileMap[i][j] == 'F')
                        title.setTextureRect(IntRect(ts, ts * 2, ts, ts));
                    if (TileMap[i][j] == 'G')
                        title.setTextureRect(IntRect(ts * 2, ts * 2, ts, ts));
                    if (TileMap[i][j] == 'H')
                        title.setTextureRect(IntRect(ts * 3, ts * 2, ts, ts));
                    if (TileMap[i][j] == 'I')
                        title.setTextureRect(IntRect(ts * 4, ts * 2, ts, ts));
                    if (TileMap[i][j] == 'J')
                        title.setTextureRect(IntRect(ts * 5, ts * 2, ts, ts));
                    if (TileMap[i][j] == 'K')
                        title.setTextureRect(IntRect(ts * 3, 0, ts, ts));
                    if (TileMap[i][j] == 'L')
                        title.setTextureRect(IntRect(ts * 6, ts * 2, ts, ts));
                    if (TileMap[i][j] == 'M')
                        title.setTextureRect(IntRect(ts * 7, ts * 2, ts, ts));
                    if (TileMap[i][j] == 'N')
                        title.setTextureRect(IntRect(ts * 8, ts * 2, ts, ts));
                    if (TileMap[i][j] == '1')
                        title.setTextureRect(IntRect(0, ts, ts, ts));
                    if (TileMap[i][j] == '2')
                        title.setTextureRect(IntRect(ts, ts, ts, ts));
                    if (TileMap[i][j] == '3')
                        title.setTextureRect(IntRect(ts * 2, ts, ts, ts));
                    if (TileMap[i][j] == '4')
                        title.setTextureRect(IntRect(ts * 3, 0, ts, ts));
                    if (TileMap[i][j] == '5')
                        title.setTextureRect(IntRect(ts * 4, ts * pula[0].shot, ts, ts));
                    if (TileMap[i][j] == '6')
                        title.setTextureRect(IntRect(ts * 5, ts * pula[0].shot, ts, ts));
                    if (TileMap[i][j] == '7')
                        title.setTextureRect(IntRect(ts * 6, ts * pula[0].shot, ts, ts));
                    if (TileMap[i][j] == '8')
                        title.setTextureRect(IntRect(ts * 7, ts * pula[0].shot, ts, ts));
                    if (TileMap[i][j] == 'W')
                        title.setTextureRect(IntRect(ts * 8, 0, ts, ts));
                    if (TileMap[i][j] == ' ')
                        continue;

                    title.setPosition(j * ts - offsetX, i * ts - offsetY);
                    window.draw(title);
                    gameTimer.draw();
                }
            if (!win)
                window.draw(p.sprite);
            for (int i = 0; i < 6; i++)
                if (pula[i].pusk)
                    window.draw(pula[i].sprite);
            for (int i = 0; i < 4; i++)
                window.draw(bat[i].sprite);
            for (int i = 0; i < 2; i++)
                window.draw(box[i].sprite);
            if (!game)
                window.draw(youlose);
            else if (win)
                window.draw(youwin);
        }

        window.display();
    }

    return 0;
}
