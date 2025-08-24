#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

typedef int ColorIndex;

class QuadrominoColor {
public:
    int red;
    int green;
    int blue;
    int alpha;

    QuadrominoColor(int red, int green, int blue, int alpha = 255)
        : red(red), green(green), blue(blue), alpha(alpha) {};

    QuadrominoColor() : red(0), green(0), blue(0), alpha(255) {};
    
    sf::Color toSFMLColor() const {
        return sf::Color(red, green, blue, alpha);
    }

    const static ColorIndex GRAY = -1;
};

class ColorPalette {
private:
    std::vector<QuadrominoColor> colors;

public:
    std::string name;

    ColorIndex getPaletteLength() {
        return colors.size() - 1; // Exclude GRAY
    }

    QuadrominoColor getColor(ColorIndex index) {
        return colors.at((index + colors.size()) % colors.size());
    }

    sf::Color getSFMLColor(ColorIndex index) {
        return getColor(index).toSFMLColor();
    }

    sf::Glsl::Vec4 getGlslColor(ColorIndex index) {
        QuadrominoColor color = getColor(index);
        return sf::Glsl::Vec4(
            color.red / 255.0f,
            color.green / 255.0f,
            color.blue / 255.0f,
            color.alpha / 255.0f
        );
    }

    ColorPalette() : name("paletteName"), colors({}) {};
    ColorPalette(std::string name, std::vector<QuadrominoColor> colors) : name(name), colors(colors) {};

    void addColor(const QuadrominoColor& color) {
        colors.push_back(color);
    }

    static ColorPalette &currentPalette;

    static std::vector<ColorPalette> palettes;
};