#ifndef DURATION_HPP
#define DURATION_HPP

class Duration
{
    private:
        int time;
        int alarm;
        bool alarmHasBeenSet;

    public:
        Duration(); // constructor
        ~Duration(); // destructor
        int getDuration(); // returns the value of the time attribute for an object instance
        Duration(int t); // constructor
        bool tick();
        bool tick(int dt);
        void setAlarm(int t);
        bool checkAndUpdateAlarm();
        bool HasAlarmBeenSet();
        

};

#endif