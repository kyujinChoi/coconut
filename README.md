# `Coconut` is the Pokémon evolution of `cout` uwu ✨
`🥥` is a namespace that extends the functionality of `std::cout`. It allows you to easily change **text color**, **text style**, and **text background color**. Additionally, it supports a **loading bar** feature. 


## How to use
#### 1. change `text color`, `text style`, and `text background color`

![image](https://github.com/user-attachments/assets/14bd51a7-1d1c-4246-b6c0-2993d424587d)

```
#include "Coconut.h"

int main(int argc, char **argv)
{
  coconut::coconut.cout("hello\n", coconut::Color::CYAN);
  coconut::coconut.cout(314, coconut::Color::MAGENTA, coconut::Style::UNDERLINE).endl().endl();
  coconut::coconut.cout(3.14159, coconut::Color::RED, coconut::Style::BOLD, coconut::Color::YELLOW).endl(3);
}
```

#### 2. `loading bar`

![coconut-2024-12-12_16 15 51-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/abaf24b6-a430-4e1d-98e7-7311ddc568fd)

```
#include "Coconut.h"

int main(int argc, char **argv)
{
  for (int i = 0; i <= 50; ++i) 
    coconut::coconut.loadingBar(i, coconut::Color::GREEN); // update loading bar
    
  std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // delay
  coconut::coconut.loadingBar(90, coconut::Color::GREEN);
  std::this_thread::sleep_for(std::chrono::milliseconds(500)); // delay
  coconut::coconut.loadingBar(100, coconut::Color::GREEN);
}
```


## Build Example
```
git clone https://github.com/kyujinChoi/coconut.git
cd coconut/
mkdir build
cmake ..; make
```


## Run Example
```
cd build/
./coconut_example
```


## LICENSE
🍺🍺 THE BEER-WARE LICENSE 🍺🍺


## Collaborators
Dongkyu Lee(PigBroA) - https://github.com/PigBroA
