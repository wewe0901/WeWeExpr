/*
 * ZTable.h
 *
 *  Created on: 2011/7/26
 *      Author: wewe0901
 */

#ifndef ZTABLE_H_
#define ZTABLE_H_

#define WIDTH 10
#define HEIGHT 31

namespace WeWeExpr {

class ZTable
    {
    public:
        static const double table[WIDTH*HEIGHT];
        static const double zValueX[WIDTH];
        static const double zValueY[HEIGHT];
        static double zValue(double confidence/* ex: 0.05 */);
    private:

    };

}

#endif /* ZTABLE_H_ */
