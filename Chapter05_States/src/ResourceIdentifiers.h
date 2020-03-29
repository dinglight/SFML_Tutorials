#ifndef RESOURCE_IDENTIFIERS_H
#define RESOURCE_IDENTIFIERS_H

namespace sf {
    class Texture;
    class Font;
}

enum class TextureID {
    Eagle,
    Raptor,
    Desert,
    TitleScreen,
};

enum class FontID {
    Main,
};

template<typename Resource, typename identifier>
class ResourceHolder;

using TextureHolder = ResourceHolder<sf::Texture, TextureID>;
using FontHolder = ResourceHolder<sf::Font, FontID>;

#endif // RESOURCE_IDENTIFIERS_H