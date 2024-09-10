#ifndef _COCONUT_H_
#define _COCONUT_H_
#include <iostream>
#include <boost/variant.hpp>

// std::cout << "\033[1;30m" << "black " << "\033[0m" << std::endl;
// std::cout << "\033[1;31m" << "red " << "\033[0m" << std::endl;
// std::cout << "\033[1;32m" << "green " << "\033[0m" << std::endl;
// std::cout << "\033[1;33m" << "yellow " << "\033[0m" << std::endl;
// std::cout << "\033[1;34m" << "blue " << "\033[0m" << std::endl;
// std::cout << "\033[1;35m" << "magenta " << "\033[0m" << std::endl;
// std::cout << "\033[1;36m" << "cyan " << "\033[0m" << std::endl;
// std::cout << "\033[1;37m" << "white " << "\033[0m" << std::endl;

// \e : Escape Letter, for calling special func to terminal
// [ : start of the sequence
// 0 : revert,1 : Bold , 4 : UnderLined
// 30 ~ 37 : color mapped
// m : end of the sequence

//!
//!                         HOW TO USE
//! --------------------------------------------------------------
//! coconut::coconut.cout("hello\n", coconut::Color::RED);
//! coconut::coconut.cout(359, coconut::Color::RED).endl().endl();
//! coconut::coconut.cout(1453.687, coconut::Color::RED, coconut::Style::BOLD).endl(3);
//!

// TODO: update on same line
// TODO: Find Root(GROOT)

namespace coconut // colorcout looks similar to coconut :) cute
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
        std::string setStyle(Style style, Color fg = Color::DEFAULT, Color bg = Color::DEFAULT)
        {
            return "\e[" + std::to_string(static_cast<int>(style)) + ";" +
                   std::to_string(static_cast<int>(fg)) + ";" +
                   std::to_string(static_cast<int>(bg) + 10) + "m";
        }
        std::string reset()
        {
            return "\e[0m";
        }
    };
    static ConsoleColor coconut;
};
#endif