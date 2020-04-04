#ifndef RESOURCE_IDENTIFIERS_H
#define RESOURCE_IDENTIFIERS_H

#include "ResourceHolder.h"

namespace sf {
    class Texture;
    class Font;
}

enum class TextureID {
    Eagle,
    Raptor,
    Desert,
    TitleScreen,
    MenuScreen,
};

enum class FontID {
    Main,
};

using TextureHolder = ResourceHolder<sf::Texture, TextureID>;
using FontHolder = ResourceHolder<sf::Font, FontID>;

#endif // RESOURCE_IDENTIFIERS_H