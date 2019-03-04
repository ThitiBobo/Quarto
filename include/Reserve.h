#ifndef RESERVE_H
#define RESERVE_H


class Reserve
{
    public:
        Reserve();
        virtual ~Reserve();
        const int defaultSize = 4;
        void removePion(int, int, Pion*);
        Pion* getPion(int, int);

        friend std::ostream& operator<<(std::ostream&, const Reserve&);



    private:
        Case plateau[4][4];
};

#endif // RESERVE_H
