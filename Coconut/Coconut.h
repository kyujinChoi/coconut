#ifndef _COCONUT_H_
#define _COCONUT_H_
#include <iostream>
#include <chrono> 
#include <thread>
#include <boost/variant.hpp>


//!
//!                         HOW TO USE
//! --------------------------------------------------------------
//! coconut::coconut.cout("hello\n", coconut::Color::RED);
//! coconut::coconut.cout(359, coconut::Color::RED).endl().endl();
//! coconut::coconut.cout(1453.687, coconut::Color::RED, coconut::Style::BOLD).endl(3);
//!

// TODO: Find Root(GROOT)

namespace coconut // colorcout looks similar to coconut :) uwu
{
    enum class Style
    {
        DEFAULT = 0,
        BOLD = 1,
        UNDERLINE = 4,
        // REVERSED = 7
    };

    // Foreground color enumeration
    enum class Color
    {
        BLACK = 30,
        RED = 31,
        GREEN = 32,
        YELLOW = 33,
        BLUE = 34,
        MAGENTA = 35,
        CYAN = 36,
        WHITE = 37,
        DEFAULT = 39
    };
    class ConsoleColor
    {
    public:
        ConsoleColor &cout(boost::variant<int, std::string, double> text, Color fg = Color::DEFAULT, Style style = Style::DEFAULT, Color bg = Color::DEFAULT)
        {
            std::cout << setStyle(style, fg, bg) << text << reset();
            return *this;
        }
        ConsoleColor &endl()
        {
            std::cout << reset() << std::endl;
            return *this;
        }
        ConsoleColor &endl(int count)
        {
            std::cout << reset();
            for (int i = 0; i < count; ++i)
            {
                std::cout << std::endl;
            }
            return *this;
        }
        std::string setStyle(Style style = Style::DEFAULT, Color fg = Color::DEFAULT, Color bg = Color::DEFAULT)
        {
            return "\e[" + std::to_string(static_cast<int>(style)) + ";" +
                   std::to_string(static_cast<int>(fg)) + ";" +
                   std::to_string(static_cast<int>(bg) + 10) + "m";
        }
        std::string reset()
        {
            return "\e[0m";
        }
        void loadingBar(int progress, Color fg = Color::DEFAULT, Style style = Style::DEFAULT, Color bg = Color::DEFAULT)
        {
            if (progress < 0)
                progress = 0;
            if (progress > 100)
                progress = 100;

            const int barWidth = 50;               
            int pos = (progress * barWidth) / 100; 

            std::cout << setStyle(style, fg, bg) << "\r[";
            for (int i = 0; i < barWidth; ++i)
            {
                if (i < pos)
                    std::cout << setStyle(style, fg, bg) << "=" ;
                else if (i == pos)
                    std::cout << setStyle(style, fg, bg) << ">" ;
                else
                    std::cout << setStyle(style, fg, bg) << " " ;
            }
            std::cout << setStyle(style, fg, bg) << "] " << progress << "%" << std::flush << reset();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            if (progress == 100)
                std::cout << setStyle(style, fg, bg) <<"\nDone!\n" << reset();

            return;
        }
    };
    static ConsoleColor coconut;
};
#endif