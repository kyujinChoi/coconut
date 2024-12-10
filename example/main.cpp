#include "Coconut.h"

int main(int argc, char **argv)
{
    coconut::coconut.cout("hello\n", coconut::Color::CYAN);
    coconut::coconut.cout(314, coconut::Color::MAGENTA, coconut::Style::UNDERLINE).endl().endl();
    coconut::coconut.cout(3.14159, coconut::Color::RED, coconut::Style::BOLD, coconut::Color::YELLOW).endl(3);
    for (int i = 0; i <= 50; ++i) {
        coconut::coconut.loadingBar(i, coconut::Color::RED); // update loading bar
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // delay
    coconut::coconut.loadingBar(90, coconut::Color::RED);
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // delay
    coconut::coconut.loadingBar(100, coconut::Color::RED);
    return 1;
}
