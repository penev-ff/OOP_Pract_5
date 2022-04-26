#include <iostream>
#include <fstream>

// 'friend' isn't bad itself,
// but it's often a symptom of bad design elsewhere.

// Forward declaration
// Allows classes that refer to each other
class Elevator;

class ElevatorController
{
public:
    void floorUp(Elevator &elevator);
    void floorDown(Elevator &elevator);

    // Why this won't compile?
    // void floorUp(Elevator &elevator) {
    //     ++elevator.floor;
    // }
};

class Elevator
{
    // Variant A
    // friend void floorUp(Elevator& elevator);

    // Variant B
    // friend void ElevatorController::floorUp(Elevator &elevator);
    // friend void ElevatorController::floorDown(Elevator &elevator);

    // Variant C
    friend class ElevatorController;

    // Variant D
    // With template functions. We will discuss this topic soon.

private:
    u_int floor = 0;

public:
    // void printFloor()
    // {
    //     std::cout << "Current floor: " << this->floor << std::endl;
    // }

    // Do we need const after the signature since operator<< is not a member-function?
    friend std::ostream &operator<<(std::ostream &out, const Elevator &elevator)
    {
        // out << "Current floor: " << elevator.floor << std::endl;
        return out << "Current floor: " << elevator.floor << std::endl;
    }

    friend std::istream &operator>>(std::istream &in, Elevator &elevator)
    {
        // in >> elevator.floor;
        return in >> elevator.floor;
    }
};

// Variant A
// void floorUp(Elevator& elevator) {
//     ++elevator.floor;
// }

// Variant B
void ElevatorController::floorUp(Elevator &elevator)
{
    ++elevator.floor;
}

// Variant C
// class ElevatorController
// {
// public:
//     void floorUp(Elevator &elevator)
//     {
//         ++elevator.floor;
//     }

//     void floorDown(Elevator &elevator)
//     {
//         if (elevator.floor >= 1)
//         {
//             --elevator.floor;
//         }
//     }
// };

int main()
{
    Elevator elevator;
    ElevatorController controller;

    // elevator.printFloor();

    std::cout << elevator;

    // floorUp(elevator);
    controller.floorUp(elevator);

    // elevator.printFloor();
    std::cout << elevator;

    std::ofstream ofs("floors.txt");

    if (!ofs.is_open())
    {
        return 1;
    }

    ofs << elevator;

    ofs.close();

    return 0;
}