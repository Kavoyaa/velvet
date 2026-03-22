#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <velvet/widgets/Label.hpp>
#include <iostream>

Label::Label(std::string text, std::unordered_map<std::string, std::variant<unsigned int, float>> styling) {
    std::string fontPath = "src/assets/AdwaitaSans-Regular.ttf";
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "\033[33mWarning: Failed to load font: '" << fontPath << "'\033[0m" << std::endl;
    }

    for (auto& [key, val] : styling) {
        if(styles.contains(key)) {
            styles[key] = val;
        }
        else {
            std::cerr << "\033[33mWarning: Invalid style property: '" << key << "'\033[0m" << std::endl;
       }
    } 

    LText.setFont(font);
    LText.setString(text);
    // LText.setStyle(sf::Text::Bold);

    LText.setCharacterSize(std::get<float>(styles.at("fontSize")));
    LText.setLineSpacing(std::get<float>(styles.at("lineSpacing")));
    LText.setLetterSpacing(std::get<float>(styles.at("letterSpacing")));
    LText.setFillColor(sf::Color(std::get<unsigned int>(styles.at("fillColor"))));
    LText.setOutlineColor(sf::Color(std::get<unsigned int>(styles.at("outlineColor"))));
    LText.setOutlineThickness(std::get<float>(styles.at("outlineThickness")));

    LText.setPosition(x, y);
}

void Label::draw(sf::RenderWindow &window) {
    window.draw(LText);
}

void Label::update(sf::RenderWindow &window) {
    
}
void Label::setText(const std::string txt) {
    LText.setString(txt);
}

void Label::render(sf::RenderWindow &window) {
    update(window);
    draw(window);
}

void Label::setPosition(float x, float y) {
    LText.setPosition(x, y);
}

sf::Vector2f Label::getDimensions() {
    sf::FloatRect textBounds = LText.getLocalBounds();


    return sf::Vector2f(textBounds.width + textBounds.left, textBounds.height + textBounds.top);
}

void Label::overrideStyling(std::unordered_map<std::string, std::variant<unsigned int, float>> styling) {

    for (auto& [key, val] : styling) {
        if(styles.contains(key)) {
            styles[key] = val;
        }
        else {
            std::cerr << "\033[33mWarning: Invalid style property: '" << key << "'\033[0m" << std::endl;
       }
    } 

    LText.setCharacterSize(std::get<float>(styles.at("fontSize")));
    LText.setLineSpacing(std::get<float>(styles.at("lineSpacing")));
    LText.setLetterSpacing(std::get<float>(styles.at("letterSpacing")));
    LText.setFillColor(sf::Color(std::get<unsigned int>(styles.at("fillColor"))));
    LText.setOutlineColor(sf::Color(std::get<unsigned int>(styles.at("outlineColor"))));
    LText.setOutlineThickness(std::get<float>(styles.at("outlineThickness")));
}