#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Game.h"

TEST_CASE("Player initialization") {
    Texture playerTexture;
    Player player(playerTexture);

    CHECK(player.rect.left == ts * 2);
    CHECK(player.rect.top == ts * 20);
    CHECK(player.rect.width == 50);
    CHECK(player.rect.height == 50);
    CHECK(player.dx == 0);
    CHECK(player.dy == 0);
    CHECK(player.down == true);
    CHECK(player.up == false);
    CHECK(player.left == false);
    CHECK(player.right == false);
}

TEST_CASE("resetGame function") {
    Texture playerTexture;
    Player player(playerTexture);
    Clock clock;

    player.rect.left = 100;
    player.rect.top = 100;
    player.dx = 1;
    player.dy = 1;
    player.down = false;
    player.up = true;
    player.left = true;
    player.right = false;
    game = false;
    win = true;
    sound.stop = true;

    resetGame(player, clock, playerTexture);

    CHECK(player.rect.left == ts * 2);
    CHECK(player.rect.top == ts * 20);
    CHECK(player.dx == 0);
    CHECK(player.dy == 0);
    CHECK(player.down == true);
    CHECK(player.up == false);
    CHECK(player.left == false);
    CHECK(player.right == false);
    CHECK(game == true);
    CHECK(win == false);
    CHECK(sound.stop == false);
}

TEST_CASE("Player::update updates player position correctly") {
    Texture image;
    Player p(image);
    p.dx = 1.0f;
    p.dy = 1.0f;
    float time = 0.1f;
    p.update(time);
    CHECK(p.rect.left == doctest::Approx(100.1f).epsilon(0.01f));
    CHECK(p.rect.top == doctest::Approx(1000.0f).epsilon(0.01f));
}

TEST_CASE("Player::Collision handles collision correctly") {
    Texture image;
    Player p(image);
    p.rect = FloatRect(50, 200, 50, 50);
    p.dx = 1.0f;
    p.dy = 1.0f;
    p.Collision(0);
    CHECK(p.dx == 1.0f);
    CHECK(p.dy == 1.0f);
}

TEST_CASE("Arrow::update updates arrow position correctly") {
    Texture image;
    Arrow a;
    a.set(image, 100, 100, 1);
    a.pusk = true;
    float time = 0.1f;
    a.update(time);
    CHECK(a.rect.left == doctest::Approx(100.2f).epsilon(0.01f));
    CHECK(a.rect.top == doctest::Approx(100.0f).epsilon(0.01f));
}

TEST_CASE("Arrow::Collision handles collision correctly") {
    Texture image;
    Arrow a;
    a.set(image, 100, 100, 1);
    a.pusk = true;
    a.dx = 1.0f;
    a.Collision(0);
    CHECK(a.pusk == true);
}

TEST_CASE("Box::update updates box state correctly") {
    Texture image;
    Box b;
    b.set(image, 150, 150);
    b.update();
    CHECK(b.timer == 1999);
}

TEST_CASE("Bat::update updates bat position correctly") {
    Texture image;
    Bat b;
    b.set(image, 200, 200, true);
    float time = 0.1f;
    b.update(time);
    CHECK(b.rect.left == doctest::Approx(199.9f).epsilon(0.01f));
    CHECK(b.rect.top == doctest::Approx(200.0f).epsilon(0.01f));
}