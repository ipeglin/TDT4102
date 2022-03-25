#pragma once

enum class Campus {
    Trondheim = 0,
    Gjøvik,
    Ålesund
};

std::ostream &operator<<(std::ostream &os, const Campus &campus);

