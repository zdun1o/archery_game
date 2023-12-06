#include <iostream>
#include <random>

#include "Engine.h"

std::random_device rd;
std::mt19937 e(rd());
std::uniform_real_distribution<> dist(30, 640);

Engine::Engine()
    :m_Lives(3), m_Score(0), m_Shoot(false)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    m_Window.create(sf::VideoMode(1280, 720), "Archery Game", sf::Style::Titlebar | sf::Style::Close, settings);
    m_Window.setVerticalSyncEnabled(true);
    m_Window.setFramerateLimit(60);
    
    m_Font.loadFromFile("fonts/ChivoMono.ttf");

    m_LogoText.setCharacterSize(60);
    m_LogoText.setPosition(50, 20);
    m_LogoText.setString("ARCHERY GAME");
    m_LogoText.setFillColor(sf::Color::Black);
    m_LogoText.setOutlineColor(sf::Color::Red);
    m_LogoText.setOutlineThickness(10);

    m_LivesText.setFont(m_Font);
    m_LivesText.setPosition(20, 150);
    m_LivesText.setFillColor(sf::Color::Black);

    m_ScoreText.setFont(m_Font);
    m_ScoreText.setPosition(20, 200);
    m_ScoreText.setFillColor(sf::Color::Black);

    m_Author.setCharacterSize(20);
    m_Author.setPosition(5, 2);
    m_Author.setFont(m_Font);
    m_Author.setString("Author: Adam Zdunczyk");
    m_Author.setFillColor(sf::Color::Black);

    borderOfPower.setSize(sf::Vector2f(505, 25));
    borderOfPower.setFillColor(sf::Color::Transparent);
    borderOfPower.setPosition(17.5f, m_Window.getSize().y - 40);
    borderOfPower.setOutlineThickness(5);
    borderOfPower.setOutlineColor(sf::Color::Black);

    Power.setSize(sf::Vector2f(0, 20));
    Power.setFillColor(sf::Color::Black);
    Power.setPosition(20, m_Window.getSize().y - 37.5f);;
}

void Engine::RotateArrow(float angle) {
    m_Arrow.m_Stem.setRotation(angle);
    m_Arrow.m_TopOfArrow.setRotation(angle);
}

void Engine::MoveArrow() {
    m_Arrow.m_Stem.move(m_Arrow.arrowVelocity * 0.4f);
    m_Arrow.m_TopOfArrow.move(m_Arrow.arrowVelocity * 0.4f);
    m_Arrow.arrowVelocity.y += 9.81f * 0.2f;

    float arrowRotation = atan2(m_Arrow.arrowVelocity.y, m_Arrow.arrowVelocity.x) * 180 / 3.14159;
    RotateArrow(arrowRotation);
}

void Engine::RotateArms() {
    m_Archer.UpdateArms(m_Controls.GetAngle());
    if(!m_Shoot)
        RotateArrow(m_Controls.GetAngle());
}

void Engine::ShootArrow(sf::Vector2f posMouse) {
    m_Arrow.arrowSpeed = m_Controls.arrowSpeed;
    sf::Vector2f arrowPos = m_Archer.GetPosition();
    float angle = 0.0f;
    angle = atan2(posMouse.y - arrowPos.y, posMouse.x - arrowPos.x);
    m_Arrow.SetPosition(arrowPos.x, arrowPos.y);
    m_Arrow.arrowVelocity = sf::Vector2f(cos(angle) * m_Arrow.arrowSpeed, sin(angle) * m_Arrow.arrowSpeed);
}

bool Engine::CheckCollision() {
    sf::Vector2f centerOfArrow(m_Arrow.m_TopOfArrow.getGlobalBounds().left + 4, m_Arrow.m_TopOfArrow.getGlobalBounds().top + 4);
    sf::Vector2f centerOfStem(m_Arrow.m_Stem.getPosition().x, m_Arrow.m_Stem.getPosition().y);

    if (centerOfArrow.x >= m_Enemy.GetPosition().x + 23.0f && centerOfArrow.x <= m_Enemy.GetPosition().x + 53.0f &&
        centerOfArrow.y >= m_Enemy.GetPosition().y - 30.0f && centerOfArrow.y <= m_Enemy.GetPosition().y) {
        return 1;
    }
    else if (centerOfStem.x >= m_Enemy.GetPosition().x && centerOfStem.x <= m_Enemy.GetPosition().x + 80.0f &&
            centerOfStem.y >= m_Enemy.GetPosition().y && centerOfStem.y <= m_Enemy.GetPosition().y + 70.0f) {
        return 1;
    }
    else {
        return 0;
    }
}

void Engine::GameOver() {
    sf::RectangleShape bg(sf::Vector2f(700.0f, 400.0f));
    bg.setOrigin(350.0f, 200.0f);
    bg.setPosition(640, 360);
    bg.setFillColor(sf::Color::White);
    bg.setOutlineThickness(10);
    bg.setOutlineColor(sf::Color::Black);

    sf::Font font;
    font.loadFromFile("fonts/logoFont.ttf");

    sf::Text main_text("GAME OVER!!!", font, 70);
    main_text.setFillColor(sf::Color::Black);
    main_text.setOutlineColor(sf::Color::Red);
    main_text.setOutlineThickness(10);
    main_text.setOrigin(main_text.getGlobalBounds().width / 2, main_text.getGlobalBounds().height / 2);
    main_text.setPosition(640, 220);

    sf::Text score_text("Your score: " + std::to_string(m_Score), m_Font, 40);
    score_text.setStyle(sf::Text::Bold);
    score_text.setFillColor(sf::Color::Black);
    score_text.setPosition(340, 330);


    sf::RectangleShape exit(sf::Vector2f(100.0f, 40.0f));
    exit.setFillColor(sf::Color(169, 169, 169));
    exit.setOutlineColor(sf::Color::Black);
    exit.setOutlineThickness(4);
    exit.setOrigin(50.0f, 20.0f);
    exit.setPosition(740, 500);

    sf::Text text_exit("EXIT",m_Font, 20);
    text_exit.setPosition(740 - (text_exit.getGlobalBounds().width / 2), 500 - (text_exit.getGlobalBounds().height));

    sf::RectangleShape again(sf::Vector2f(100.0f, 40.0f));
    again.setFillColor(sf::Color(169, 169, 169));
    again.setOutlineColor(sf::Color::Black);
    again.setOutlineThickness(4);
    again.setOrigin(50.0f, 20.0f);
    again.setPosition(540, 500);

    sf::Text text_again("PLAY AGAIN", m_Font, 15);
    text_again.setPosition(540 - (text_again.getGlobalBounds().width / 2), 500 - (text_again.getGlobalBounds().height));

    while (m_Window.isOpen()) {
        bool state = m_Controls.MouseInputGameOver(m_Window);
        
        if (state == 1) {
            if (exit.getGlobalBounds().contains(m_Controls.GetPosition())) {
                m_Window.close();
                return;
            }
            else if (again.getGlobalBounds().contains(m_Controls.GetPosition())) {
                m_Arrow.SetPosition(m_Archer.GetPosition().x, 1900.0f);
                m_Lives = 3;
                m_Score = 0;
                return;
            }
        }

        if (exit.getGlobalBounds().contains(m_Controls.GetPosition())) {
            exit.setFillColor(sf::Color(105, 105, 105));
        }
        else if (again.getGlobalBounds().contains(m_Controls.GetPosition())) {
            again.setFillColor(sf::Color(105, 105, 105));
        }
        else {
            exit.setFillColor(sf::Color(169, 169, 169));
            again.setFillColor(sf::Color(169, 169, 169));
        }

        m_Window.clear(sf::Color(88, 88, 88, 240));

        m_Window.draw(bg);
        m_Window.draw(main_text);
        m_Window.draw(score_text);
        m_Window.draw(m_Author);
        m_Window.draw(exit);
        m_Window.draw(again);
        m_Window.draw(text_exit);
        m_Window.draw(text_again);
        m_Window.display();
    }
}

void Engine::Play() {
    m_Archer.Init(20, 500);
    m_Enemy.Init(m_Window.getSize().x - 100 , 500);
    m_Arrow.Init(m_Archer.GetPosition().x, m_Archer.GetPosition().y);

    sf::Font logoFont;
    logoFont.loadFromFile("fonts/logoFont.ttf");
    m_LogoText.setFont(logoFont);

    while (m_Window.isOpen())
    {
        if (m_Lives != 0) {
            m_LivesText.setString("Lives: " + std::to_string(m_Lives));
            m_ScoreText.setString("Score: " + std::to_string(m_Score));

            m_Controls.MouseInput(m_Window, m_Shoot);

            if (m_Controls.canRotate) {
                m_Controls.SetAngle(m_Archer.GetPosition());
                RotateArms();
            }
            if (m_Controls.canShoot) {
                ShootArrow(m_Controls.GetClickPosition());
                m_Controls.canShoot = false;
                Power.setSize(sf::Vector2f(0.0f, 20));
            }

            if (m_Controls.resetArrow) {
                m_Arrow.SetPosition(m_Archer.GetPosition().x, m_Archer.GetPosition().y);
                m_Controls.resetArrow = false;
            }

            if (m_Controls.buttonPressed) {
                float x = m_Controls.GetPosition().x - m_Controls.GetClickPosition().x;
                float y = m_Controls.GetPosition().y - m_Controls.GetClickPosition().y;
                float s = sqrt(x * x + y * y) / 2;
                if (s < 150.0f) {
                    m_Controls.arrowSpeed = s;
                }
                Power.setSize(sf::Vector2f(3.33f * m_Controls.arrowSpeed, 20));
            }

            if (m_Shoot) {
                if (CheckCollision()) {
                    m_Blood.Init(sf::Vector2f(m_Enemy.GetPosition().x + 35.0f, m_Enemy.GetPosition().y - 15.0f));
                    m_Score++;
                    sf::sleep(sf::milliseconds(1000));
                    m_Shoot = false;
                    m_Arrow.SetPosition(m_Archer.GetPosition().x, m_Archer.GetPosition().y);
                    m_Enemy.Init(m_Window.getSize().x - 100, dist(e));
                }
                else {
                    MoveArrow();
                    if (m_Arrow.m_Stem.getPosition().y > 2000 || m_Arrow.m_Stem.getPosition().x > 4000) {
                        m_Shoot = false;
                        m_Lives--;
                        m_Arrow.SetPosition(m_Archer.GetPosition().x, m_Archer.GetPosition().y);
                        m_Enemy.Init(m_Window.getSize().x - 100, dist(e));
                    }
                }
            }
            
            m_Blood.Update();

            m_Window.clear(sf::Color::White);

            m_Window.draw(m_LogoText);
            m_Window.draw(m_LivesText);
            m_Window.draw(m_ScoreText);
            m_Window.draw(m_Author);
            m_Window.draw(Power);
            m_Window.draw(borderOfPower);

            m_Blood.Draw(m_Window);
            m_Archer.Draw(m_Window);
            m_Arrow.Draw(m_Window);
            m_Enemy.Draw(m_Window);

            m_Window.display();
        }
        else {
            m_Controls.canPlay = false;
            GameOver();
        }
    }
}