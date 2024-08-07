#pragma once

#include "module.h"

class Input : public Module {

public:

    Input() = default;
    bool update() override;
};