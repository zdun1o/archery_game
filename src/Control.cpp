#include "Control.h"

Control::Control()
    :m_Angle(0.0f), arrowSpeed(0.0f), canPlay(true), buttonPressed(false), canRotate(false), canShoot(false), resetArrow(false)
{
}

void Control::SetAngle(sf::Vector2f archerPos) {
    float angle = 0.0f;
    angle = atan2(m_Pos.y - archerPos.y, m_Pos.x - archerPos.x);
    m_Angle = angle * 180.0f / 3.14159f;
}

void Control::MouseInput(sf::RenderWindow& win, bool& shoot) {
    while (win.pollEvent(m_Event))
    {
        m_Pos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(win));

        if (m_Event.type == sf::Event::Closed)
            win.close();
        else if (m_Event.mouseButton.button == sf::Mouse::Left) {
            if (canPlay) {
                if (m_Event.type == sf::Event::MouseButtonPressed) {
                    m_ClickPos = sf::Vector2f(sf::Mouse::getPosition(win).x, sf::Mouse::getPosition(win).y);
                    buttonPressed = true;
                }
                else if (m_Event.type == sf::Event::MouseButtonReleased) {
                    buttonPressed = false;
                    if (!shoot) {
                        shoot = true;
                        canShoot = true;
                    }
                }
            }
            if (!canPlay && m_Event.type == sf::Event::MouseButtonReleased) {
                canPlay = true;
                resetArrow = true;
            }
        }

        if (m_Event.type == sf::Event::MouseMoved && !buttonPressed)
            canRotate = true;
        else
            canRotate = false;
    }
}

bool Control::MouseInputGameOver(sf::RenderWindow& win){
    while (win.pollEvent(m_Event)) {
        m_Pos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(win));

        if (m_Event.type == sf::Event::Closed)
            win.close();
        else if (m_Event.type == sf::Event::MouseButtonPressed && m_Event.mouseButton.button == sf::Mouse::Left)
            return 1;
        else
            return 0;
    }
}