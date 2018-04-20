#ifndef __HILL_CLIMB_ROAD_H__
#define __HILL_CLIMB_ROAD_H__
/* Guards
*/
#include <vector>
#include "HillClimbUtility.h"
namespace hillclimb
{
    class HillClimbRoad
    {
    public:
        const int MAX_PART_COUNT = 10;
        const int X_ROAD_START = 0;
        const int Y_ROAD_START = 0;
        const int DEFAULT_ROAD_LENGTH = 2;

        HillClimbRoad( const double  winWidth, const double winHeight);
        std::vector<Coordinates> getPartCoords();
        int getPartCount();
        void addPart(double x, double y);
        void move(double x);
        /*
        reset()
        */
    private:
        void generatePartsAhead();
        std::vector<Coordinates> partCoords;
        /*
        calculateNewPartX(prevPartX)
        double calculateNewPartY()
        deletePartsBehind()
         */
    };
}


#endif