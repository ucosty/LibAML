// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Timer.h"

void Timer::print(int depth) {
    indent(depth * 2);
    fmt::print("- Timer\n");
}

std::string Timer::value_string() {
    return "[Timer]";
}
