#ifndef CONFIG_H
#define CONFIG_H

class CONFIG
{
    private:
        static const int refreshRateMilli = 15;
    public:
        static int GameSpeed(){return refreshRateMilli;}

};

#endif // CONFIG_H
