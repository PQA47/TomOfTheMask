#include "Game.h"


/**
 * \brief X offset for rendering.
 */
float offsetX = ts * 0;

/**
 * \brief Y offset for rendering.
 */
float offsetY = ts * 12;

/**
 * \brief Indicates if the game is in the menu.
 */
bool inMenu = true;

/**
 * \brief Indicates if the game is running.
 */
bool game = true;

/**
 * \brief Indicates if the player has won the game.
 */
bool win = false;

String TileMap[H] = {
    "       AAAAA7A AAAAAAAAA ",
    "      B       D         K",
    "      B GFH   I   J     K",
    "      B   D       D     K",
    "      B   EFF8FFFFB     K",
    "      B   D       D     K",
    "      B  WD       D     K",
    "       CCCB   J   D     K",
    "  AAAAAAAAB   D   KCCCH K",
    "  B       B   D  G    B K",
    "  B       5   D   6AAAL K",
    "  B       B   D   D     K",
    "  B       5   KM  D     K",
    "  BAAAA AAL   D   D     K",
    "  B    I      D   D  GFF ",
    "  B J     NCCCB  GB     K",
    "  B D     K   B   6     K",
    " AL KCCCC3    B   KFFFM K",
    "B   K         B   I     K",
    "B   K         B         4",
    "B   K         2     J   4",
    " CCC           CCCCC CCC ",
};

/**
 * \brief Global instance of setSound.
 */
setSound sound;

/**
 * \brief Constructor for setSound class.
 * Initializes and loads all sound effects and music.
 */
setSound::setSound() {
    b.loadFromFile("Game/Sound/bat.ogg");
    ca.loadFromFile("Game/Sound/cannon.ogg");
    co.loadFromFile("Game/Sound/coin.ogg");
    hf.loadFromFile("Game/Sound/hedoff.ogg");
    hn.loadFromFile("Game/Sound/hedon.ogg");
    l.loadFromFile("Game/Sound/lose.ogg");
    s.loadFromFile("Game/Sound/start.ogg");
    w.loadFromFile("Game/Sound/win.ogg");

    bat.setBuffer(b);
    cannon.setBuffer(ca);
    coin.setBuffer(co);
    hedoff.setBuffer(hf);
    hedon.setBuffer(hn);
    lose.setBuffer(l);
    start.setBuffer(s);
    win.setBuffer(w);

    stop = false;

    music.openFromFile("Game/Sound/music.ogg");
    music.setLoop(true);
}

/**
 * \brief Constructor for Player class.
 * \param image Reference to the texture for the player sprite.
 */
Player::Player(Texture& image) {
    sprite.setTexture(image);
    rect = FloatRect(ts * 2, ts * 20, 50, 50);
    sprite.setTextureRect(IntRect(0, 0, 50, 50));

    dx = dy = 0;

    down = true;

    up = left = right = false;
}

/**
 * \brief Updates the player's position and state.
 * \param time Time elapsed since the last update.
 */
void Player::update(float time) {
    rect.left += dx * time;
    Collision(0);

    rect.top += dy * time;
    Collision(1);

    if (left)
        rotate = 0;
    else if (right)
        rotate = 1;
    else if (up)
        rotate = 2;
    else if (down)
        rotate = 3;

    if (dx != 0 || dy != 0)
        sprite.setTextureRect(IntRect(200, 0, ts, ts));
    else if (dx == 0 && dy == 0)
        sprite.setTextureRect(IntRect(ts * rotate, 0, ts, ts));

    sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
}

/**
 * \brief Handles collision detection for the player.
 * \param dir Direction of collision (0 for horizontal, 1 for vertical).
 */
void Player::Collision(int dir) {
    for (int i = rect.top / ts; i < (rect.top + rect.height) / ts; i++)
        for (int j = rect.left / ts; j < (rect.left + rect.width) / ts; j++) {
            if (TileMap[i][j] == 'A' || TileMap[i][j] == 'B' || TileMap[i][j] == 'C' || TileMap[i][j] == 'D' ||
                TileMap[i][j] == 'E' || TileMap[i][j] == 'F' || TileMap[i][j] == 'G' || TileMap[i][j] == 'H' ||
                TileMap[i][j] == 'I' || TileMap[i][j] == 'J' || TileMap[i][j] == 'K' || TileMap[i][j] == 'L' ||
                TileMap[i][j] == 'M' || TileMap[i][j] == 'N' ||
                TileMap[i][j] == '5' || TileMap[i][j] == '6' || TileMap[i][j] == '7' || TileMap[i][j] == '8') {
                if (dx > 0 && dir == 0) {
                    rect.left = j * ts - rect.width;
                    dx = 0;
                }
                if (dx < 0 && dir == 0) {
                    rect.left = j * ts + ts;
                    dx = 0;
                }
                if (dy > 0 && dir == 1) {
                    rect.top = i * ts - rect.height;
                    dy = 0;
                }
                if (dy < 0 && dir == 1) {
                    rect.top = i * ts + ts;
                    dy = 0;
                }
            }

            if (TileMap[i][j] == '1' || TileMap[i][j] == '2' || TileMap[i][j] == '3' || TileMap[i][j] == '4')
                game = false;
            if (TileMap[i][j] == 'W') {
                win = true;
                sound.win.play();
            }
        }
}

/**
 * \brief Sets the properties of the Arrow object.
 * \param image Reference to the Texture object to be used for the arrow sprite.
 */
void Arrow::set(Texture& image, int x, int y, int r) {
    sprite.setTexture(image);
    rect = FloatRect(x, y, 50, 50);
    sprite.setTextureRect(IntRect(ts * (r - 1), 0, 50, 50));

    if (r == 1) {
        dx = 0.2;
        dy = 0;
    }
    else if (r == 2) {
        dx = -0.2;
        dy = 0;
    }
    else if (r == 3) {
        dx = 0;
        dy = 0.2;
    }
    else if (r == 4) {
        dx = 0;
        dy = -0.2;
    }

    px = x;
    py = y;
    rotate = r;

    timer = 2000;
    Sti = 0;
    pusk = shot = false;
}

/**
 * \brief Updates the arrow's position and state.
 * \param time Time elapsed since the last update.
 */
void Arrow::update(float time) {
    if (timer > 0 && !pusk) {
        timer--;

        if (timer == 0) {
            timer = 1000;
            pusk = true;

            shot = true;
            Sti = 80;

            sound.cannon.play();
        }
    }

    if (shot && Sti > 0) {
        Sti--;

        if (Sti == 0)
            shot = false;
    }

    if (pusk) {
        rect.left += dx * time;
        Collision(0);

        rect.top += dy * time;
        Collision(1);
    }

    sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
}

/**
 * \brief Handles collision detection for the player.
 * \param dir Direction of collision (0 for horizontal, 1 for vertical).
 */
void Arrow::Collision(int dir) {
    for (int i = rect.top / ts; i < (rect.top + rect.height) / ts; i++)
        for (int j = rect.left / ts; j < (rect.left + rect.width) / ts; j++) {
            if (TileMap[i][j] == 'A' || TileMap[i][j] == 'B' || TileMap[i][j] == 'C' || TileMap[i][j] == 'D' ||
                TileMap[i][j] == 'E' || TileMap[i][j] == 'F' || TileMap[i][j] == 'G' || TileMap[i][j] == 'H' ||
                TileMap[i][j] == 'I' || TileMap[i][j] == 'J' || TileMap[i][j] == 'K' || TileMap[i][j] == 'L' ||
                TileMap[i][j] == 'M' || TileMap[i][j] == 'N' ||
                TileMap[i][j] == '5' || TileMap[i][j] == '6' || TileMap[i][j] == '7' || TileMap[i][j] == '8') {
                if (dx != 0 && dir == 0) {
                    rect.left = px;
                    pusk = false;
                }
                if (dy != 0 && dir == 1) {
                    rect.top = py;
                    pusk = false;
                }
            }
        }
}

/**
 * \brief Sets up the box object.
 * \param image Reference to the texture for the box sprite.
 * \param x Initial x position.
 * \param y Initial y position.
 */
void Box::set(Texture& image, int x, int y) {
    sprite.setTexture(image);

    Bx = x;
    By = y;
}

/**
 * \brief Updates the box's state.
 */
void Box::update() {
    timer--;

    if (timer == 0) {
        if (big == 0) {
            big = 150;
            timer = 1000;

            sound.hedon.play();
        }
        else {
            big = 0;
            timer = 2000;

            sound.hedoff.play();
        }
    }

    rect.left = Bx;
    rect.top = By;

    sprite.setTextureRect(IntRect(150 * big, 0, 150, 150));
    sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
}

/**
 * \brief Sets up the bat object.
 * \param image Reference to the texture for the bat sprite.
 * \param x Initial x position.
 * \param y Initial y position.
 * \param Cx Boolean indicating the direction of movement.
 */
void Bat::set(Texture& image, int x, int y, bool Cx) {
    sprite.setTexture(image);
    rect = FloatRect(x, y, 50, 50);

    curFrame = 0;

    if (Cx) {
        dx = -0.1;
        dy = 0;
    }
    else {
        dx = 0;
        dy = -0.1;
    }
}

/**
 * \brief Updates the bat's position and state.
 * \param time Time elapsed since the last update.
 */
void Bat::update(float time) {
    rect.left += dx * time;

    Collision(0);

    rect.top += dy * time;

    Collision(1);

    curFrame += 0.005 * time;
    if (curFrame > 3)
        curFrame -= 3;

    if (dx < 0 || dy > 0)
        sprite.setTextureRect(IntRect(50 * int(curFrame), 0, 50, 50));
    else
        sprite.setTextureRect(IntRect(50 * int(curFrame) + 50, 0, -50, 50));

    sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
}

/**
 * \brief Handles collision detection for the bat.
 * \param dir Direction of collision (0 for horizontal, 1 for vertical).
 */
void Bat::Collision(int dir) {
    for (int i = rect.top / ts; i < (rect.top + rect.height) / ts; i++)
        for (int j = rect.left / ts; j < (rect.left + rect.width) / ts; j++)
            if (TileMap[i][j] == 'A' || TileMap[i][j] == 'B' || TileMap[i][j] == 'C' || TileMap[i][j] == 'D' ||
                TileMap[i][j] == 'E' || TileMap[i][j] == 'F' || TileMap[i][j] == 'G' || TileMap[i][j] == 'H' ||
                TileMap[i][j] == 'I' || TileMap[i][j] == 'J' || TileMap[i][j] == 'K' || TileMap[i][j] == 'L' ||
                TileMap[i][j] == 'M' || TileMap[i][j] == 'N' ||
                TileMap[i][j] == '5' || TileMap[i][j] == '6' || TileMap[i][j] == '7' || TileMap[i][j] == '8') {
                if (dx > 0 && dir == 0) {
                    dx *= -1;

                    if (rect.left - offsetX >= 0 && rect.left - offsetX <= 500 &&
                        rect.top - offsetY >= 0 && rect.top - offsetY <= 700)
                        sound.bat.play();
                }
                else if (dx < 0 && dir == 0) {
                    dx *= -1;

                    sound.bat.play();
                }
                else if (dy < 0 && dir == 1) {
                    dy *= -1;

                    sound.bat.play();
                }
                else if (dy > 0 && dir == 1) {
                    dy *= -1;

                    sound.bat.play();
                }
            }
}

/**
 * \brief Constructor for Menu class.
 * \param window Reference to the game window where the menu will be displayed.
 */
Menu::Menu(RenderWindow& window) : window(window), bestTime(0) {
    if (!font.loadFromFile("Shrift/troika.otf")) {
        std::cerr << "Font not found!" << std::endl;
    }
    startButton.setFont(font);
    startButton.setString("Start Game");
    startButton.setCharacterSize(30);
    startButton.setFillColor(Color::White);
    startButton.setPosition(window.getSize().x / 2 - startButton.getLocalBounds().width / 2, window.getSize().y / 2 - startButton.getLocalBounds().height / 2);

    recordButton.setFont(font);
    recordButton.setString("Record");
    recordButton.setCharacterSize(30);
    recordButton.setFillColor(Color::White);
    recordButton.setPosition(window.getSize().x / 2 - recordButton.getLocalBounds().width / 2, window.getSize().y / 2 + 50);

    exitButton.setFont(font);
    exitButton.setString("Exit");
    exitButton.setCharacterSize(30);
    exitButton.setFillColor(Color::White);
    exitButton.setPosition(window.getSize().x / 2 - exitButton.getLocalBounds().width / 2, window.getSize().y / 2 + 100);

    if (!menuTexture.loadFromFile("Game/Paint/menu0.png")) {
        std::cerr << "Menu image not found!" << std::endl;
    }
    menuSprite.setTexture(menuTexture);
    menuSprite.setPosition(window.getSize().x / 2 - menuSprite.getGlobalBounds().width / 2, 100); // Позиционирование картинки
    recordButton.setString("Record: " + formatTime(bestTime));
}

/**
 * \brief Draws the menu elements to the window.
 */
void Menu::draw() {
    window.draw(menuSprite);
    window.draw(startButton);
    window.draw(recordButton);
    window.draw(exitButton);
    window.draw(recordButton);
}

/**
 * \brief Handles user input for the menu.
 * \param event The event to handle.
 * \return True if the start button was pressed, false otherwise.
 */
bool Menu::handleInput(Event& event) {
    if (event.type == Event::MouseButtonReleased) {
        if (event.mouseButton.button == Mouse::Left) {
            Vector2f mousePos = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
            if (startButton.getGlobalBounds().contains(mousePos)) {
                return true;
            }
            if (recordButton.getGlobalBounds().contains(mousePos)) {
                showResults();
            }
            if (exitButton.getGlobalBounds().contains(mousePos)) {
                window.close();
            }
            if (recordButton.getGlobalBounds().contains(mousePos)) {
                showResults();
            }
        }
    }
    return false;
}
/**
 * \brief Updates the best time record.
 * \param newTime The new time to compare with the best time.
 * \param isWin Indicates if the new time was achieved by winning the game.
 */
void Menu::updateBestTime(std::time_t newTime, bool isWin) {
    if (isWin && (newTime < bestTime || bestTime == 0)) {
        bestTime = newTime;
        recordButton.setString("Record: " + formatTime(bestTime));
    }
}

/**
 * \brief Displays the best time record.
 * \param Show the result near the record.
 */
void Menu::showResults() {
    std::cout << "Best Time: " << bestTime << " seconds" << std::endl;
}

std::string Menu::formatTime(std::time_t time) {
    std::ostringstream oss;
    oss << time << " sec";
    return oss.str();
}

/**
 * \brief Constructor for GameTimer class.
 * \param window Reference to the game window.
 */
GameTimer::GameTimer(RenderWindow& window) : window(window), startTime(0), elapsedTime(0) {
    if (!font.loadFromFile("Shrift/troika.otf")) {
        std::cerr << "Font not found!" << std::endl;
    }
    timerText.setFont(font);
    timerText.setCharacterSize(24);
    timerText.setFillColor(Color::White);
    timerText.setPosition(window.getSize().x - 100, 10);
}

/**
 * \brief Starts the game timer.
 */
void GameTimer::start() {
    startTime = std::time(nullptr);
}

/**
 * \brief Updates the game timer.
 */
void GameTimer::update() {
    std::time_t currentTime = std::time(nullptr);
    elapsedTime = currentTime - startTime;
    std::ostringstream oss;
    oss << "Time: " << elapsedTime;
    timerText.setString(oss.str());
}

/**
 * \brief Draws the game timer to the window.
 */
void GameTimer::draw() {
    window.draw(timerText);
}

/**
 * \brief Gets the elapsed time.
 * \return The elapsed time in seconds.
 */
std::time_t GameTimer::getElapsedTime() const {
    return elapsedTime;
}

/**
 * \brief Resets the game state.
 * \param p Reference to the player object.
 * \param clock Reference to the game clock.
 * \param Picture Reference to the player's texture.
 */
void resetGame(Player& p, Clock& clock, Texture& Picture) {
    p.rect = FloatRect(ts * 2, ts * 20, 50, 50);
    p.dx = p.dy = 0;
    p.down = true;
    p.up = p.left = p.right = false;

    game = true;
    win = false;
    sound.stop = false;

    clock.restart();

    float offsetX = ts * 0;
    float offsetY = ts * 12;
}