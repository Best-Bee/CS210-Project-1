class Clock {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Clock(int h, int m, int s);
    void addHour();
    void addMinute();
    void addSecond();
    void displayTime();
    void trimmedTime();
    void displayMenu();
};