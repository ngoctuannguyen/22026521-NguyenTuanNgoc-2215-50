#include "header/common.h"

SDL_Rect operator+(const SDL_Rect& a, const float& b) {
    return {a.x + int(b), a.y, a.w, a.h};
}