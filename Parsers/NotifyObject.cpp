// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// NotifyObject := SuperName => ThermalZone | Processor | Device
Result<Element *> Parser::parse_notify_object() {
    return parse_super_name();
}
