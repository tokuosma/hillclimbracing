#ifndef __HILL_CLIMB_WHEEL_H__
#define __HILL_CLIMB_WHEEL_H__

#include "HillClimbRoad.h"
namespace hillclimb{
    
    struct RoadPartTouching{
        double wheelSubmersion;
        double slope;
    };
    
    class HillClimbCarWheel{
    public:
        HillClimbCarWheel(double x_offset, double y_offset, double radius);
        double getForceX();
        double getForceY();
        std::vector<RoadPartTouching> getRoadPartsTouching();
        //updateState(throttle, carPos, carAngle, road)
        //clearPreviousState()
    private:
        double X_OFFSET;
        double Y_OFFSET;
        double OFFSET_ANGLE;
        double RADIUS;
        double x;
        double y;
        double force_x;
        double force_y;
        std::vector<RoadPartTouching> roadPartsTouching;
        void updateRoadPartsTouching(HillClimbRoad road);
    
        //touchesRoad()
        //updatePosX(carX, carAngle)
        //updatePosY(carY, carAngle)
        //void updateForces(throttle)
    };
    
}
#endif
/* Guards
  
Includes

Namespace

    struct RoadPartTouching
        wheelSubmersion (how much wheel has submerged beneath the surface of the road)
        slope

    class CarWheel
      public
        CarWheel(x_offset, y_offset, radius)
        getForceX()
        getForceY()
        getRoadPartsTouching()
        updateState(throttle, carPos, carAngle, road)
        clearPreviousState()
      private:
        OFFSET
        OFFSET_ANGLE
        RADIUS
        x
        y
        force_x
        force_y
        roadPartsTouching
    
        touchesRoad()
        updatePosX(carX, carAngle)
        updatePosY(carY, carAngle)
        updateRoadPartsTouching(road)
        void updateForces(throttle)

Guards end
*/
