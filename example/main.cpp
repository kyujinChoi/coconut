#include "Coconut.h"

int main(int argc, char **argv)
{
    coconut::coconut.cout("hello\n", coconut::Color::RED);
    coconut::coconut.cout(359, coconut::Color::RED).endl().endl();
    coconut::coconut.cout(1453.687, coconut::Color::RED, coconut::Style::BOLD).endl(3);
    return 1;
}