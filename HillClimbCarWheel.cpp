#include "HillClimbCarWheel.h"


namespace hillclimb {

    HillClimbCarWheel::HillClimbCarWheel(double x_offset, double y_offset, double radius)
    : X_OFFSET(x_offset), Y_OFFSET(y_offset), RADIUS(radius) {

    }

    double HillClimbCarWheel::getForceX() {
        return this->force_x;
    }

    double HillClimbCarWheel::getForceY() {
        return this->force_y;
    }

    void HillClimbCarWheel::updateRoadPartsTouching(HillClimbRoad road) {
        this->roadPartsTouching.clear();
        /*
        use calculateDistanceToLineSegment for each road part on the road
        check if they are closer than RADIUS
        if they are calculateSlope and wheelSubmersion (RADIUS - distance) and generate RoadPartTouching
         */
        std::vector<Coordinates> roadParts = road.getPartCoords();
        int count = roadParts.size();
        if (count < 2) {
            return;
        }

        double submersion;
        double slope;
        for (int i = 0; i < count - 1; i++) {
            double dist = calculateDistanceToLineSegment(this->x, this->y, roadParts[i], roadParts[i + 1]);
            if (dist < this->RADIUS) {
                submersion = this->RADIUS - dist;
                slope = calculateSlope(roadParts[i], roadParts[i + 1]);
                this->roadPartsTouching.push_back({.wheelSubmersion = submersion,
                    .slope = slope});
            }
        }
    }

    std::vector<RoadPartTouching> HillClimbCarWheel::getRoadPartsTouching() {
        return this->roadPartsTouching;
    }
}
/* Includes

namespace

   function getRoadPartsTouching

   function updatePosX

   function updatePosY

   function touchesRoad

   function clearPreviousState

   function updateForces(throttle) {
      if count of road parts touching > 0
          divide throttle by count of road parts touching

      loop through road parts touching
          get slope and slopeAngle
          if slope >= 0
              friction = SOME_FRICTION_CONST * (slope + 1)
          else
              friction = SOME_FRICTION_CONST / (abs(slope) + 1)
          resThrottle = throttle - friction
          increment force_x with cos(slopeAngle) * resThrottle
          increment force_y with sin(slopeAngle) * resThrottle
   }



   function updateState
 */
