#ifndef __HILL_CLIMB_ROAD_H__
#define __HILL_CLIMB_ROAD_H__
/* Guards
*/
#include <vector>
#include "HillClimbUtility.h"
namespace hillclimb
{
    struct HillClimbRoadSegment{
        Coordinates start;
        Coordinates end;
    };
    
    class HillClimbRoad
    {
    public:
        const int MAX_PART_COUNT = 100;
        const int X_ROAD_START = 0;
        const int Y_ROAD_START = 0;
        const int DEFAULT_ROAD_LENGTH = 10;
        const double ROAD_LENGTH_FACTOR = 10;
        HillClimbRoad( const double  winWidth, const double winHeight);
        std::vector<Coordinates> getPartCoords();
        int getPartCount();
        void addPart(double x, double y);
        void move(double x);
        std::vector<HillClimbRoadSegment>getRoadSegments();
        /*
        reset()
        */
    private:
        void generatePartsAhead();
        void deletePartsBehind();
        std::vector<Coordinates> partCoords;
        double calculateNewPartX(double prevPartX);
        double calculateNewPartY(double prevPartY);
        /*
         */
    };
}


#endif