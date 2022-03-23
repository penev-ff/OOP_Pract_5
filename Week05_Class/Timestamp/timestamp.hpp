// Check https://en.wikipedia.org/wiki/Unix_time

#ifndef TIME_HPP_GUARD_
#define TIME_HPP_GUARD_

typedef unsigned long long u_ll;
typedef unsigned short u_short;

#define DEFAULT_TIME_VALUE 0

class Timestamp
{
private:
    u_short HH;
    u_short MM;
    u_short SS;

public:
    // Constructors
    Timestamp();
    Timestamp(u_short hours, u_short minutes, u_short seconds);
    Timestamp(u_ll seconds);
    //

    // Getters
    u_short getHH() const;
    u_short getMM() const;
    u_short getSS() const;
    //

    // Setters
    void setHH(u_short hours);
    void setMM(u_short minutes);
    void setSS(u_short seconds);
    void setBySeconds(u_ll seconds);
    //

    void addHH(u_short HH);

    void addMM(u_short MM);

    void addSS(u_short SS);

    u_ll toSeconds() const;

    u_ll toMilliseconds() const;

    void print_formated() const;

    void reset();

    // No need of explicitly declared destructor
    // ~Time();
};

#endif // TIME_HPP_GUARD_