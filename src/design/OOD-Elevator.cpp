#include "../../util/common.h"

enum Direction {
    NONE,
    UP,
    DOWN
};

class Elevator {
public:
   
private:
    int currentFloor;
    Direction currentDir;
};

class Button {
public:
    Button(int f, Controller* c) {
        floor = f;
        controller = c;
    }
    void request(bool b) {
        pressed = true;
        dir = b;
        controller->requestElevator(floor, dir);
    }
    void reset() { pressed = false; }

private:
    int floor;
    bool dir; // up or down
    bool pressed;
    Controller* controller;
};

class Controller {
public:
    void setup(Elevator* e, Button* u, Button* d) {
        elevators.push_back(e);
        upButtons.push_back(u);
        downButtons.push_back(d);
    }
    void requestElevator(int floor, bool up) {
        if (up) upRequests.insert(floor);
        else downRequests.insert(floor);
    }
private:
    vector<Elevator*> elevators;
    vector<Button*> upButtons;
    vector<Button*> downButtons;
    set<int> upRequests;
    set<int> downRequests;
};

class Building {
public:
    Building(int m) : elevators(m), upButtons(m), downButtons(m) {
        for (int i=0; i<m; i++) {
            control.setup(&elevators[i], &upButtons[i], &downButtons[i]);
        }
    }
private:
    vector<Elevator> elevators;
    vector<Button> upButtons;
    vector<Button> downButtons;
    Controller control;
};

int main()
{
    return 0;
}