#include <iostream>
#include "timestamp.hpp"

int main()
{
    Timestamp time(13, 52, 44);

    time.print_formated();

    Timestamp invalid(23, 61, 12);

    invalid.print_formated();
    invalid.addHH(25);
    invalid.addSS(40);
    invalid.print_formated();

    // Greenwich Mean Time (GMT)
    Timestamp epoch(1647948007);

    epoch.print_formated();

    epoch.addHH(2);

    epoch.print_formated();

    Timestamp leading(7, 5, 3);
    leading.print_formated();

    return 0;
}