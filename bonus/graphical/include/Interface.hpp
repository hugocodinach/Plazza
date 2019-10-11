/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Interface
*/

#ifndef INTERFACE_HPP
    #define INTERFACE_HPP

    #include <SFML/Audio.hpp>
    #include <SFML/Graphics.hpp>
    #include <SFML/Window/Event.hpp>
    #include <iostream>
    #include <fstream>
    #include <map>
    #include <vector>
    #include <cmath>

    #define SCREEN_WIDTH    1000
    #define SCREEN_HEIGHT   1000

    class Interface {
        public:
            Interface();
            ~Interface();

            void runManager(void);
            void stop(void);
            void drawRectangle(int x, int y, int width, int height, sf::Color color);
            void getAndDrawKitchens(void);
            int getKitchensStatus(void);
            int drawCooks(void);
            void displayHUD(void);

        private:
            sf::RenderWindow *_window;
            sf::Event _event;
            std::string _name;
            sf::Clock _clock;
            sf::Font _font;
            bool _isOpen;
            std::map<int, std::vector<std::string>> _status;
            sf::RectangleShape _rectangle;
    };

#endif /* !INTERFACE_HPP */
