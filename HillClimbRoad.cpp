/* Includes
*/
#include "HillClimbRoad.h"
#include "HillClimbUtility.h"
namespace hillclimb{
    
   HillClimbRoad::HillClimbRoad(const double  winWidth, const double winHeight){
   }
   
   std::vector<Coordinates> HillClimbRoad::getPartCoords(){
       return this->partCoords;
   }
   
   int HillClimbRoad::getPartCount(){
       return this->partCoords.size();
   }

   void HillClimbRoad::addPart(double x, double y){
       this->partCoords.push_back({.x =x ,.y=y});
   }
   
   void HillClimbRoad::move(double x) {
       for(auto coords:partCoords){
           coords.x -= x;
       }
       //deletePartsBehind
       //generatePartsAhead
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

   function generatePartsAhead {
      generate parts as many as MAX_PART_COUNT - currentPartCount
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


