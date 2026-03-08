#include <velvet/core>

/*
int main() {
    Window window(800, 600, "Velvet");
    //VStack vstack(window, 10);
    VStack vstack(10);

    Button btn1(200, 120, "click me", sf::Color::White, 2);
    Button btn2(200, 120, "poggies!", sf::Color::White, 2);
    Button btn3(200, 120, "poggies!", sf::Color::White, 2);

    vstack.add(&btn1);
    vstack.add(&btn2);

    window.add(&vstack);

    window.run();
}
*/

///*
int main() {
    Window window(800, 600, "Velvet");

    Button btn1(300, 120, "[1] im in V1", sf::Color::White, 2);
    Button btn2(300, 120, "[2] im in V1", sf::Color::White, 2);

    Button btn3(365, 100, "[3] im in V2", sf::Color::White, 2);
    Button btn4(365, 100, "[4] im in V2", sf::Color::White, 2);

    Button btn5(250, 150, "[4] im in V3", sf::Color::White, 2);
    Button btn6(220, 100, "[5] im in V3", sf::Color::White, 2);

    VStack mainStack(10);
    VStack v1(10);
    HStack v2(10);
    VStack v3(10);

    v1.add(&btn1);
    v1.add(&btn2);
    v2.add(&btn3);
    v2.add(&btn4);
    v3.add(&btn5);
    v3.add(&btn6);

    mainStack.add(&v1);
    mainStack.add(&v2);
    mainStack.add(&v3);

    window.add(&mainStack);

    window.run();
}
//*/