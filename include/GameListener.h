#ifndef GAMELISTENER_H
#define GAMELISTENER_H


class GameListener
{
    public:
        GameListener();
        virtual ~GameListener();

        virtual void gameChanged() = 0;

    protected:

    private:
};

#endif // GAMELISTENER_H
