/* Includes
 */
#include "HillClimbRoad.h"
#include "HillClimbUtility.h"
namespace hillclimb {

    HillClimbRoad::HillClimbRoad(const double winWidth, const double winHeight) {

    }

    std::vector<Coordinates> HillClimbRoad::getPartCoords() {
        return this->partCoords;
    }

    int HillClimbRoad::getPartCount() {
        return this->partCoords.size();
    }

    void HillClimbRoad::addPart(double x, double y) {
        this->partCoords.push_back({.x = x, .y = y});
    }

    void HillClimbRoad::move(double x) {
        for (auto& coords : this->partCoords) {
            coords.x -= x;
        }

        this->deletePartsBehind();
        this->generatePartsAhead();
        //deletePartsBehind
        //generatePartsAhead
    }

    std::vector<HillClimbRoadSegment> HillClimbRoad::getRoadSegments() {
        std::vector<HillClimbRoadSegment> segments;
        int count = this->getPartCount();
        if (count < 2) {
            return segments;
        }
        for (int i = 0; i < count - 1; i++) {
            segments.push_back({this->partCoords[i], this->partCoords[i + 1]});
        }
        return segments;
    }

    double HillClimbRoad::calculateNewPartX(double prevPartX) {
        return prevPartX + (rand() % 10) * ROAD_LENGTH_FACTOR;
    }

    double HillClimbRoad::calculateNewPartY(double prevPartY) {
        return prevPartY + (rand() % 10) * ROAD_LENGTH_FACTOR;
    }

    void HillClimbRoad::deletePartsBehind() {
        //delete parts whose x < -DEFAULT_ROAD_LENGTH * ROAD_LENGTH_FACTOR
        while (this->partCoords[0].x < -DEFAULT_ROAD_LENGTH * ROAD_LENGTH_FACTOR) {
            this->partCoords.erase(partCoords.begin());
        }
    }

    void HillClimbRoad::generatePartsAhead() {
        Coordinates lastCoordinate;
        while (this->getPartCount() < MAX_PART_COUNT) {
            lastCoordinate = this->partCoords.back();
            this->partCoords.push_back({.x = calculateNewPartX(lastCoordinate.x),
                .y = calculateNewPartY(lastCoordinate.y)});
        }
    }
    /*
   ROAD_LENGHT_FACTOR = choose some road length factor

   HillClimbRoad constructor




   function calculateNewPartX {
       randomize length of the new part using some factor
   }

   function calculateNewPartY {
       randomize y position of the end point of the new part
   }



   deletePartsBehind() {
      delete parts whose x < -DEFAULT_ROAD_LENGTH * ROAD_LENGTH_FACTOR
   }


   reset
       clear partCoords
       add two horizontal parts
       generatePartsAhead
   }
     */
}


