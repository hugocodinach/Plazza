/*
** EPITECH PROJECT, 2018
** Interface.cpp
** File description:
** src/Interface.cpp
*/

#include "Interface.hpp"

Interface::Interface()
{
    _name = "SFML";
    if (!_font.loadFromFile("./resources/vanilla_whale.ttf")) {
        std::cout << "SFML: can't load font ./resources/font.ttf" << std::endl;
    }
    _window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window");
    _clock.restart();
    if (!_window) {
        std::cout << "SFML: can't open window" << std::endl;
        return;
    }
    _isOpen = true;
    _window->setFramerateLimit(90);
    runManager();
}

Interface::~Interface()
{
}

void Interface::stop(void)
{
    _window->close();
    _isOpen = false;
}

void Interface::drawRectangle(int x, int y, int width, int height, sf::Color color)
{
    _rectangle.setSize(sf::Vector2f(width, height));
    _rectangle.setFillColor(color);
    _rectangle.setPosition(x, y);
    _window->draw(_rectangle);
}

int Interface::getKitchensStatus(void)
{
    std::ifstream files("../graphical.log" , std::ios::in);
    std::string line;
    std::string kitchenId;
    int kitchenIdInt = 0;
    std::string cookId;
    std::string cookStatu;
    size_t prevSep = 0;
    std::vector<std::string> cooksStatu;

    _status.clear();
    while (std::getline(files, line)) {
        kitchenId = line.substr(1, line.find(']') - 1);
        kitchenIdInt = std::stoi(kitchenId);
        for (int i = 0; prevSep < line.size() - 4; i += 1) {
            cookId = line.substr(line.find('(', prevSep) + 1,
            line.find(',', prevSep) - line.find('(', prevSep) - 1);
            cookStatu = line.substr(line.find(',', prevSep) + 1,
            line.find(')', prevSep) - line.find(',', prevSep) - 1);
            prevSep = line.find(')', prevSep) + 2;
            cooksStatu.push_back(cookStatu);
        }
        _status.insert(std::pair<int,std::vector<std::string>>(kitchenIdInt, cooksStatu));
        cooksStatu.clear();
        prevSep = 0;
    }
    return (0);
}

int Interface::drawCooks(void)
{
    return (0);
}

void Interface::getAndDrawKitchens(void)
{
    getKitchensStatus();
    if (_status.size() == 0)
        return;
    double nbKitchen = _status.size();
    double divisorKitchen = 0;
    for (; divisorKitchen * divisorKitchen < nbKitchen; divisorKitchen += 1);
    double margin_width = (SCREEN_WIDTH * 15) / 100;
    double margin_height = (SCREEN_HEIGHT * 15) / 100;
    double reception_width = SCREEN_WIDTH - (2 * margin_width);
    double ecart_width = ((reception_width * 15) / 100) / divisorKitchen;
    double kitchen_width = (reception_width - (ecart_width * (divisorKitchen - 1))) / divisorKitchen;
    double reception_height = SCREEN_HEIGHT - (2 * margin_height);
    double ecart_height = ((reception_height * 15) / 100) / divisorKitchen;
    double kitchen_height = (reception_height - (ecart_height * (divisorKitchen - 1))) / divisorKitchen;

    std::map<int, std::vector<std::string>>::iterator it = _status.begin();
    double divisorCooks = 0;
    for (; divisorCooks * divisorCooks < it->second.size(); divisorCooks += 1);
    double kitchen_margin_width = (kitchen_width * 15) / 100;
    double kitchen_margin_height = (kitchen_height * 15) / 100;
    double kitchen_ecart_width = ((kitchen_width * 15) / 100) / divisorCooks;
    double cook_width = (kitchen_width - (kitchen_ecart_width * (divisorCooks - 1))
    - (2 * kitchen_margin_width)) / divisorCooks;
    double kitchen_ecart_height = ((kitchen_height * 15) / 100) / divisorCooks;
    double cook_height = (kitchen_height - (kitchen_ecart_height * (divisorCooks - 1))
    - (2 * kitchen_margin_height)) / divisorCooks;
    int i_cooks_width = 0;
    int i_cooks_height = 0;

    int i_width = 0;
    int i_height = 0;

    int kitchenX = 0;
    int kitchenY = 0;
    int cookX = 0;
    int cookY = 0;

    for (;it != _status.end(); it++, i_width += 1) {
        if (i_width >= divisorKitchen) {
            i_width = 0;
            i_height += 1;
        }
        kitchenX = margin_width + i_width * (ecart_width + kitchen_width);
        kitchenY = margin_height + i_height * (ecart_height + kitchen_height);
        drawRectangle(kitchenX, kitchenY, kitchen_width, kitchen_height, sf::Color::Blue);
        for (size_t i = 0 ; i < it->second.size(); i += 1, i_cooks_width += 1) {
            if (i_cooks_width >= divisorCooks) {
                i_cooks_width = 0;
                i_cooks_height += 1;
            }
            cookX = kitchenX + kitchen_margin_width + i_cooks_width * (kitchen_ecart_width + cook_width);
            cookY = kitchen_margin_height + i_cooks_height * (kitchen_ecart_height + cook_height);
            if (it->second[i].compare("Cooking") == 0)
                drawRectangle(cookX, kitchenY + cookY, cook_width, cook_height, sf::Color::Yellow);
            else if (it->second[i].compare("Waiting for a pizza") == 0)
                drawRectangle(cookX, kitchenY + cookY, cook_width, cook_height, sf::Color::White);
            else
                drawRectangle(cookX, kitchenY + cookY, cook_width, cook_height, sf::Color::Red);
        }
        i_cooks_width = 0;
        i_cooks_height = 0;
    }
}

void Interface::displayHUD(void)
{
    double margin_width = (SCREEN_WIDTH * 13) / 100;
    double margin_height = (SCREEN_HEIGHT * 13) / 100;
    double text_x = (SCREEN_WIDTH * 15) / 100;
    double text_y = (SCREEN_HEIGHT * 2) / 100;
    sf::Text text;

    drawRectangle(margin_width, margin_height, 2, SCREEN_HEIGHT - (margin_height * 2), sf::Color::Red);
    drawRectangle(SCREEN_WIDTH - margin_width, margin_height, 2, SCREEN_HEIGHT - (margin_height * 2), sf::Color::Red);
    drawRectangle(margin_width, margin_height, SCREEN_WIDTH - (margin_width * 2) + 2, 2, sf::Color::Red);
    drawRectangle(margin_width, SCREEN_HEIGHT - margin_height, SCREEN_WIDTH - (margin_width * 2) + 2, 2, sf::Color::Red);
    text.setFont(_font);
    text.setCharacterSize(SCREEN_WIDTH / 13);
    text.setColor(sf::Color::White);
    text.setString("Benvenuto a la Piazza Papa");
    text.setPosition(text_x, text_y);
    _window->draw(text);
}


void Interface::runManager()
{
    while (_isOpen) {
        while (_window->pollEvent(_event)) {
            if (_event.type == sf::Event::Closed)
                stop();
        }
        _window->clear();
        getAndDrawKitchens();
        displayHUD();
        _window->display();
    }
}