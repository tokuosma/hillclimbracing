#ifndef __HILL_CLIMB_CAR_H__
#define __HILL_CLIMB_CAR_H__
#include <memory>
#include "HillClimbCarWheel.h"

namespace hillclimb{
    
    class HillClimbCar{
    public:
        HillClimbCar(const double x,const  double y,const double scale);
        void updateThrottle(double throttle);
        /*
        update(road, dt)
        getPositionY()
        getTransitionX(dt)
        getAngle()
        touchesRoad()
        reset(y)
         */
    private:
        double X_POS;
        double Y_POS;
        double SCALE;
        double v_x;
        double v_y;
        double a_x;
        double a_y;
        double throttle;
        std::unique_ptr<HillClimbCarWheel> leftWheel;
        std::unique_ptr<HillClimbCarWheel> rightWheel;
        void updatePosY(double dt);
        void updateVelocityY(double dt);
        void updateVelocityX(double dt);
        /*
        angle
        v_ang
        a_ang
        
        roadPartsTouching
    
        updateAccelerations(dt)
        updateAngle(dt)
        updateAngularVelocity(dt)
        updateAngularAcceleration(dt)
        updateRoadPartsTouching()
        updateWheels(road)
        */
    };
    
}

#endif
/*
 Guards

includes 

namespace

    class HillClimbCar
      public
        HillClimbCar(x, y, scale)
        update(road, dt)
        updateThrottle(dthrottle)
        getPositionY()
        getTransitionX(dt)
        getAngle()
        touchesRoad()
        reset(y)
      private
        X_POS
        SCALE
        y
        v_x
        v_y
        a_x
        a_y
        angle
        v_ang
        a_ang
        throttle
        leftWheel
        rightWheel
        roadPartsTouching
    
        updatePosY(dt)
        updateVelocityY(dt)
        updateVelocityX(dt)
        updateAccelerations(dt)
        updateAngle(dt)
        updateAngularVelocity(dt)
        updateAngularAcceleration(dt)
        updateRoadPartsTouching()
        updateWheels(road)

Guards end
*/
