#include "TextInput.h"
#include "../States/StateMenu.h"
#include "../Game.h"

TextInput::TextInput(StateMenu *stateMenu, sf::Vector2f pos, std::string placeHolder, unsigned maxSize) : Gui(nullptr)
    , stateMenu(stateMenu)
    , pos(pos)
    , inputText(placeHolder)
    , maxSize(maxSize)
{

    //BACKGROUND
    background = sf::RectangleShape();
    background.setFillColor(sf::Color(0, 0, 0, 100));
    background.setSize(sf::Vector2f(500, 100));
    background.setPosition(pos.x - background.getSize().x / 2,
                           pos.y - background.getSize().y / 2 + 13);


    //TEXT
    font.loadFromFile("Res/Font/lucon.ttf");
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(45);
    text.setString(placeHolder);
    text.setPosition(-background.getSize().x * 0.5f + text.getLocalBounds().width * 0.5f- text.getLocalBounds().width / 2 + margin,
                     pos.y - text.getLocalBounds().height / 2);

    //CURSOR ( | )
    cursor = sf::RectangleShape();
    cursor.setFillColor(sf::Color::White);
    cursor.setSize(sf::Vector2f(2, 60));
    cursor.setPosition(pos.x + text.getLocalBounds().width + 10 - background.getSize().x / 2 + margin,
                       pos.y - background.getSize().y / 2 + 13 + 20);


}

void TextInput::update(float dt) {
    cursorTime += dt;
    //Reset after 2 secs
    cursorTime = cursorTime > 1.06f ? 0 : cursorTime;
}

void TextInput::draw(sf::RenderWindow &window) {
    window.draw(background);
    window.draw(text);
    if(active && cursorTime <= 0.53f) {
        window.draw(cursor);
    }
}

bool TextInput::isActive(sf::Vector2i mousePos) {

    sf::Vector2f pixelPos = stateMenu->getGame()->getWindow().mapPixelToCoords(mousePos);

    wasActive = active;

    active = pixelPos.x > background.getPosition().x &&
             pixelPos.x < background.getPosition().x + background.getSize().x &&
             pixelPos.y > background.getPosition().y &&
             pixelPos.y < background.getPosition().y + background.getSize().y;

    //Just got active
    if(!wasActive && active) {
        cursorTime = 0;
    }

    return active;
}

void TextInput::eventResize() {
    if(wasActive) {
        active = true;
    }
}

void TextInput::eventInput(short unicode) {
    if(active) {
        //First time typing something
        if(isPlaceHolder) {
            isPlaceHolder = false;
            inputText = "";
        }
        //Erase key
        if(unicode == 8) {
            if(inputText.length() >= 1) {
                inputText = inputText.substr(0, inputText.length() - 1);
            }
        } else if(maxSize == 0 || inputText.length() < maxSize){
            std::string input = unicodeConvert.to_bytes(unicode);
            inputText+= input;
        }

        text.setString(inputText);
        cursor.setPosition(pos.x + text.getLocalBounds().width + 10 - background.getSize().x / 2 + margin,
                           pos.y - background.getSize().y / 2 + 13 + 20);
    }
}

const std::string &TextInput::getInputText() const {
    return inputText;
}