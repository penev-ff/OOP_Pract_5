#include "timestamp.hpp"

#include <iostream>
#include <iomanip> // another way of formmating

Timestamp::Timestamp()
    : HH(DEFAULT_TIME_VALUE),
      MM(DEFAULT_TIME_VALUE),
      SS(DEFAULT_TIME_VALUE) {}

// Timestamp::Timestamp()
//     : Timestamp(0, 0, 0) {}

Timestamp::Timestamp(u_short HH, u_short MM, u_short SS)
{
    setHH(HH);
    setMM(MM);
    setSS(SS);
}

Timestamp::Timestamp(u_ll seconds)
{
    setBySeconds(seconds);
}

void Timestamp::reset()
{
    setHH(DEFAULT_TIME_VALUE);
    setMM(DEFAULT_TIME_VALUE);
    setSS(DEFAULT_TIME_VALUE);
}

void Timestamp::setHH(u_short HH)
{
    this->HH = (HH <= 23) ? HH : DEFAULT_TIME_VALUE;
}

void Timestamp::setMM(u_short MM)
{
    this->MM = (MM <= 59) ? MM : DEFAULT_TIME_VALUE;
}

void Timestamp::setSS(u_short SS)
{
    this->SS = (SS <= 59) ? SS : DEFAULT_TIME_VALUE;
}

u_short Timestamp::getHH() const
{
    return HH;
}

u_short Timestamp::getMM() const
{
    return MM;
}

u_short Timestamp::getSS() const
{
    return SS;
}

void Timestamp::setBySeconds(u_ll seconds)
{
    this->HH = (seconds / 3600) % 24;
    this->MM = (seconds / 60) % 60;
    this->SS = seconds % 60;
}

u_ll Timestamp::toSeconds() const
{
    return this->HH * 3600 + this->MM * 60 + this->SS;
}

u_ll Timestamp::toMilliseconds() const
{
    return toSeconds() * 1000;
}

void Timestamp::addHH(u_short HH)
{
    u_ll totalSeconds = this->toSeconds();
    setBySeconds(totalSeconds + HH * 3600);
}

void Timestamp::addMM(u_short MM)
{
    u_ll totalSeconds = this->toSeconds();
    setBySeconds(totalSeconds + MM * 60);
}

void Timestamp::addSS(u_short SS)
{
    u_ll totalSeconds = this->toSeconds();
    setBySeconds(totalSeconds + SS);
}

void Timestamp::print_formated() const
{
    // Using <iomanip>.
    // std::cout << std::setw(2) << std::setfill('0') << HH << ':';
    // std::cout << std::setw(2) << std::setfill('0') << MM << ':';
    // std::cout << std::setw(2) << std::setfill('0') << SS << std::endl;
    
    // Manual check
    if (HH < 10)
    {
        std::cout << '0';
    }

    std::cout << HH << ':';

    if (MM < 10)
    {
        std::cout << '0';
    }

    std::cout << MM << ':';

    if (SS < 10)
    {
        std::cout << '0';
    }

    std::cout << SS << std::endl;
}