#include <SFML/System/Vector2.hpp>
#include <unordered_map>
#include <variant>
#include <velvet/base/Widget.hpp>
#include <SFML/Graphics/Color.hpp>

class Label : public Widget {
private:
    sf::Text LText;
    sf::RectangleShape labelBackground;
    sf::Font font;

    // std::variant<int, float, std::string> values;
    std::unordered_map<std::string, std::variant<unsigned int, float, std::string>> styles = {
        {"fontSize", 20.f},
        {"lineSpacing", 1.f},
        {"letterSpacing", 1.f},
        {"fillColor", 0x000000FFu},
        {"outlineColor", 0xFFFFFFFFu},
        {"outlineThickness", 0.f},
        {"fontStyle", "regular"}
    };

    void draw(sf::RenderWindow &window) override;
    void update(sf::RenderWindow &window) override;

public:
    void render(sf::RenderWindow &window) override;
    void setPosition(float x, float y) override;
    sf::Vector2f getDimensions() override;
    Label(std::string text, std::unordered_map<std::string, std::variant<unsigned int, float, std::string>> styling = {
        {"fontSize", 20.f},
        {"lineSpacing", 1.f},
        {"letterSpacing", 1.f},
        {"fillColor", 0x000000FFu},
        {"outlineColor", 0xFFFFFFFFu},
        {"outlineThickness", 0.f},
        {"fontStyle", "regular"}
    });
    void setText(const std::string txt);

    // void setLineSpacing(float spacingFactor) { LText.setLineSpacing(spacingFactor); }
    void overrideStyling(std::unordered_map<std::string, std::variant<unsigned int, float, std::string>> styling);
};
