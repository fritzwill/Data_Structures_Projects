// Interface for c4col class 
// Date: 1/24/2017
// Author: Will Fritz

#ifndef C4COL_H
#define C4COL_H

class C4Col {
    public:
        C4Col();
        ~C4Col();
        int isFull(); // 1 is full, 0 is not
        char getDisc(int);
        int getMaxDiscs();
        void addDiscs(char);
    private:
        int numDiscs;
        int maxDiscs;
        char * Discs;
};

#endif
