#include <SFML/System/Vector2.hpp>
#include <velvet/base/Widget.hpp>
#include <SFML/Graphics/Color.hpp>

class Image : public Widget {
private:
    sf::Sprite imageSprite;
    sf::Texture imageTexture;

    void draw(sf::RenderWindow &window) override;
    void update(sf::RenderWindow &window) override;

public:
    void render(sf::RenderWindow &window) override;
    void setPosition(float x, float y) override;
    sf::Vector2f getDimensions() override;
    Image(std::string filePath);
    void setScale(float scaleFactorX, float scaleFactorY);
};
