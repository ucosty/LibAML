// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include "Types.h"

namespace Lib {
    enum StatusCode {
        Empty,
        Unknown,
        EndOfFile
    };

    class Error {
    public:
        static Error from_code(uint64_t code) { return Error(code); }

        static Error from_status(StatusCode status) { return Error(status); }

        [[nodiscard]] bool is_code() const { return m_code > 0; }

        [[nodiscard]] uint64_t get_code() const { return m_code; }

    protected:
        explicit Error(uint64_t code) : m_code(code) {}

    private:
        uint64_t m_code{0};
    };
}// namespace Lib
