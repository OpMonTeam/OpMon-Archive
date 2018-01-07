#include "Enums.hpp"


namespace OpMon{
  namespace Model{

    namespace ArrayTypes {
      const float arrOneType[][18] = {

	{NE, VE, NE, NM, NM, NE, VE, NE, NE, NE, NE, IN, NE, NE, VE, NM, NM, NE},
	{NM, NM, NM, NM, NM, VE, NM, NM, NE, NM, NM, NM, VE, NE, NM, NM, NE, VE},
	{NM, NM, VE, NE, NE, VE, NE, VE, NM, NM, NE, NM, NM, NM, NM, NM, NM, NM},
	{NE, NM, NM, NE, VE, NM, NE, NE, NM, NM, VE, NM, NM, NM, NM, NM, NM, NM},
	{NE, NM, NM, NM, NE, NM, NM, NM, NM, NM, NM, NM, NM, NM, VE, NM, NM, NE},
	{VE, NE, IN, NM, NM, NM, NM, NM, NE, NM, NM, VE, NM, NM, NM, NM, NE, NM},
	{NE, NM, NM, VE, NM, NE, NE, NE, NE, NM, NE, NM, NM, VE, VE, NM, NM, NM},
	{VE, VE, NM, NM, NM, NM, VE, NE, NM, NM, NM, NM, NM, VE, NM, NM, NM, NM},
	{NM, NE, NM, NM, NM, NM, VE, NM, NM, NM, NE, NM, NM, VE, NE, NM, NM, VE},
	{NM, VE, NM, NM, NM, NM, NM, NM, NM, NM, NM, NM, NM, NM, NM, IN, NM, NM},
	{NM, NM, NM, NE, NE, NM, VE, VE, VE, NM, NE, VE, NM, NM, NE, NM, NM, VE},
	{NM, NE, NM, NM, NM, NE, NM, NM, NE, NM, NE, NE, VE, NM, VE, NM, NM, NM},
	{NM, NE, NM, NM, NM, NM, NM, NM, VE, NM, NM, NM, NE, NM, NM, VE, VE, NE},
	{VE, VE, NM, VE, NM, NM, NE, NM, NM, NE, VE, NE, NM, NM, VE, NM, NM, NE},
	{NM, NM, NM, VE, IN, NM, NM, VE, NM, NM, VE, NE, NM, NE, NM, NM, NM, NM},
	{NM, IN, NM, NM, NM, NM, NM, NM, NE, IN, NM, NE, NM, NM, NM, VE, VE, NM},
	{NM, VE, NM, NM, NM, VE, NM, NM, VE, NM, NM, NM, IN, NM, NM, NE, NE, NM},
	{NM, NE, NM, NM, VE, NM, NM, VE, NE, NM, NE, NM, NM, VE, IN, NM, NM, NM}
      };
      /**Un tableau qui réunit tous les tables a double type*/
      const float arrTwoTypes[][18][18] = {{
	  {VL, SE, VL, NM, NM, VL, SE, VL, VL, VL, VL, IN, VL, VL, SE, NM, NM, VL},
	  {NE, VE, NE, NM, NM, NM, VE, NE, VL, NE, NE, IN, NM, VL, VE, NM, NE, NM},
	  {NE, VE, NM, NE, NE, NM, NM, NM, NE, NE, VL, IN, NE, NE, VE, NM, NM, NE},
	  {VL, VE, NE, NE, VE, NE, NM, VL, NE, NE, NM, IN, NE, NE, VE, NM, NM, NE},
	  {VL, VE, NE, NM, NE, NE, VE, NE, NE, NE, NE, IN, NE, NE, SE, NM, NM, VL},
	  {NM, NM, IN, NM, NM, NE, VE, NE, VL, NE, NE, IN, NE, NE, VE, NM, NE, NE},
	  {VL, VE, NE, VE, NM, VL, NM, VL, VL, NE, VL, IN, NE, NM, SE, NM, NM, NE},
	  {NM, SE, NE, NM, NM, NE, SE, VL, NE, NE, NE, IN, NE, NM, VE, NM, NM, NE},
	  {NE, NM, NE, NM, NM, VL, SE, NE, NE, NE, VL, IN, NM, NM, NM, NE, NE, NM},
	  {NE, SE, NE, NM, NM, NE, VE, NE, NE, NE, NE, IN, NE, NE, VE, IN, NM, NE},
	  {NE, VE, NE, NE, NE, NE, SE, NM, NM, NE, VL, IN, NE, NE, NM, NM, NM, NM},
	  {NE, NM, NE, NM, NM, VL, VE, NE, VL, NE, VL, IN, NM, NE, SE, NM, NM, NE},
	  {NE, NM, NE, NM, NM, NE, VE, NE, NM, NE, NE, IN, VL, NE, VE, VE, VE, NE},
	  {NM, SE, NE, VE, NM, NE, NM, NE, NE, VL, NM, IN, NE, NE, SE, NM, NM, VL},
	  {NE, VE, NE, VE, IN, NE, VE, NM, NE, NE, NM, IN, NE, VL, VE, NM, NM, NE},
	  {NE, IN, NE, NM, NM, NE, VE, NE, VL, IN, NE, IN, NE, NE, VE, VE, VE, NE},
	  {NE, SE, NE, NM, NM, NM, VE, NE, NM, NE, NE, IN, IN, NE, VE, NE, NE, NE},
	  {NE, NM, NE, NM, VE, NE, VE, NM, VL, NE, VL, IN, NE, NM, IN, NM, NM, NE}
	}, {

	  {NE, VE, NE, NM, NM, NM, VE, NE, VL, NE, NE, IN, NM, VL, VE, NM, NE, NM},
	  {NM, NM, NM, NM, NM, VE, NM, NM, NE, NM, NM, NM, VE, NE, NM, NM, NE, VE},
	  {NM, NM, VE, NE, NE, SE, NE, VE, NE, NM, NE, NM, VE, NE, NM, NM, NE, VE},
	  {NE, NM, NM, NE, VE, VE, NE, NE, NE, NM, VE, NM, VE, NE, NM, NM, NE, VE},
	  {NE, NM, NM, NM, NE, VE, NM, NM, NE, NM, NM, NM, VE, NE, VE, NM, NE, NM},
	  {VE, NE, IN, NM, NM, VE, NM, NM, VL, NM, NM, VE, VE, NE, NM, NM, VL, VE},
	  {NE, NM, NM, VE, NM, NM, NE, NE, VL, NM, NE, NM, VE, NM, VE, NM, NE, VE},
	  {VE, VE, NM, NM, NM, VE, VE, NE, NE, NM, NM, NM, VE, NM, NM, NM, NE, VE},
	  {NM, NE, NM, NM, NM, VE, VE, NM, NE, NM, NE, NM, VE, NM, NE, NM, NE, SE},
	  {NM, VE, NM, NM, NM, VE, NM, NM, NE, NM, NM, NM, VE, NE, NM, IN, NE, VE},
	  {NM, NM, NM, NE, NE, VE, VE, VE, NM, NM, NE, VE, VE, NE, NE, NM, NE, SE},
	  {NM, NE, NM, NM, NM, NM, NM, NM, VL, NM, NE, NE, SE, NE, VE, NM, NE, VE},
	  {NM, NE, NM, NM, NM, VE, NM, NM, NM, NM, NM, NM, NM, NE, NM, VE, NM, VE},
	  {VE, VE, NM, VE, NM, VE, NE, NM, NE, NE, VE, NE, VE, NE, VE, NM, NE, NM},
	  {NM, NM, NM, VE, IN, VE, NM, VE, NE, NM, VE, NE, VE, VL, NM, NM, NE, VE},
	  {NM, IN, NM, NM, NM, VE, NM, NM, VL, IN, NM, NE, VE, NE, NM, VE, NM, VE},
	  {NM, VE, NM, NM, NM, SE, NM, NM, NM, NM, NM, NM, IN, NE, NM, NE, VL, VE},
	  {NM, NE, NM, NM, VE, VE, NM, VE, VL, NM, NE, NM, VE, NM, IN, NM, NE, VE}
	}, {

	  {NE, VE, NM, NE, NE, NM, NM, NM, NE, NE, VL, IN, NE, NE, VE, NM, NM, NE},
	  {NM, NM, VE, NE, NE, SE, NE, VE, NE, NM, NE, NM, VE, NE, NM, NM, NE, VE},
	  {NM, NM, VE, NE, NE, VE, NE, VE, NM, NM, NE, NM, NM, NM, NM, NM, NM, NM},
	  {NE, NM, VE, VL, NM, VE, VL, NM, NM, NM, NM, NM, NM, NM, NM, NM, NM, NM},
	  {NE, NM, VE, NE, VL, VE, NE, VE, NM, NM, NE, NM, NM, NM, VE, NM, NM, NE},
	  {VE, NE, IN, NE, NE, VE, NE, VE, NE, NM, NE, VE, NM, NM, NM, NM, NE, NM},
	  {NE, NM, VE, NM, NE, NM, VL, NM, NE, NM, VL, NM, NM, VE, VE, NM, NM, NM},
	  {VE, VE, VE, NE, NE, VE, NM, NM, NM, NM, NE, NM, NM, VE, NM, NM, NM, NM},
	  {NM, NE, VE, NE, NE, VE, NM, VE, NM, NM, VL, NM, NM, VE, NE, NM, NM, VE},
	  {NM, VE, VE, NE, NE, VE, NE, VE, NM, NM, NE, NM, NM, NM, NM, IN, NM, NM},
	  {NM, NM, VE, VL, VL, VE, NM, SE, VE, NM, VL, VE, NM, NM, NE, NM, NM, VE},
	  {NM, NE, VE, NE, NE, NM, NE, VE, NE, NM, VL, NE, VE, NM, VE, NM, NM, NM},
	  {NM, NE, VE, NE, NE, VE, NE, VE, VE, NM, NE, NM, NE, NM, NM, VE, VE, NM},
	  {VE, VE, VE, NM, NE, VE, VL, VE, NM, NE, NM, NE, NM, NM, VE, NM, NM, NE},
	  {NM, NM, VE, NM, IN, VE, NE, SE, NM, NM, NM, NE, NM, NE, NM, NM, NM, NM},
	  {NM, IN, VE, NE, NE, VE, NE, VE, NE, IN, NE, NE, NM, NM, NM, VE, VE, NM},
	  {NM, IN, VE, NE, NE, VE, NE, VE, NE, IN, NE, NE, NM, NM, NM, VE, VE, NM},
	  {NM, NE, VE, NE, NM, VE, NE, SE, NE, NM, VL, NM, NM, VE, IN, NM, NM, NM}
	}, {

	  {VL, VE, NE, NE, VE, NE, NM, VL, NE, NE, NM, IN, NE, NE, VE, NM, NM, NE},
	  {NE, NM, NM, NE, VE, VE, NE, NE, NE, NM, VE, NM, VE, NE, NM, NM, NE, VE},
	  {NE, NM, VE, VL, NM, VE, VL, NM, NM, NM, NM, NM, NM, NM, NM, NM, NM, NM},
	  {NE, NM, NM, NE, VE, NM, NE, NE, NM, NM, VE, NM, NM, NM, NM, NM, NM, NM},
	  {VL, NM, NM, NE, NM, NM, NE, NE, NM, NM, VE, NM, NM, NM, VE, NM, NM, NE},
	  {NM, NE, IN, NE, VE, NM, NE, NE, NE, NM, VE, VE, NM, NM, NM, NM, NE, NM},
	  {VL, NM, NM, NM, VE, NE, VL, VL, NE, NM, NM, NM, NM, VE, VE, NM, NM, NM},
	  {NM, VE, NM, NE, VE, NM, NM, VL, NM, NM, VE, NM, NM, VE, NM, NM, NM, NM},
	  {NE, NE, NM, NE, VE, NM, NM, NE, NM, NM, NM, NM, NM, VE, NE, NM, NM, VE},
	  {NE, VE, NM, NE, VE, NM, NE, NE, NM, NM, VE, NM, NM, NM, NM, IN, NM, NM},
	  {NE, NM, NM, VL, NM, NM, NM, NM, VE, NM, NM, VE, NM, NM, NE, NM, NM, VE},
	  {NE, NE, NM, NE, VE, NE, NE, NE, NE, NM, NM, NE, VE, NM, VE, NM, NM, NM},
	  {NE, NE, NM, NE, VE, NM, NE, NE, VE, NM, VE, NM, NE, NM, NM, VE, VE, NM},
	  {NM, VE, NM, NM, VE, NM, VL, NE, NM, NE, SE, NE, NM, NM, VE, NM, NM, NE},
	  {NE, NM, NM, NM, IN, NM, NE, NM, NM, NM, SE, NE, NM, NE, NM, NM, NM, NM},
	  {NE, IN, NM, NE, VE, NM, NE, NE, NE, IN, VE, NE, NM, NM, NM, VE, VE, NM},
	  {NE, VE, NM, NE, VE, VE, NE, NE, VE, NM, VE, NM, IN, NM, NM, NE, NE, NM},
	  {NE, NE, NM, NE, SE, NM, NE, NM, NE, NM, NM, NM, NM, VE, IN, NM, NM, NM}
	}, {
	  {VL, VE, NE, NM, NE, NE, VE, NE, NE, NE, NE, IN, NE, NE, SE, NM, NM, VL},
	  {NE, NM, NM, NM, NE, VE, NM, NM, NE, NM, NM, NM, VE, NE, VE, NM, NE, NM},
	  {NE, NM, VE, NE, VL, VE, NE, VE, NM, NM, NE, NM, NM, NM, VE, NM, NM, NE},
	  {VL, NM, NM, NE, NM, NM, NE, NE, NM, NM, VE, NM, NM, NM, VE, NM, NM, NE},
	  {NE, NM, NM, NM, NE, NM, NM, NM, NM, NM, NM, NM, NM, NM, VE, NM, NM, NE},
	  {NM, NE, IN, NM, NE, NM, NM, NM, NE, NM, NM, VE, NM, NM, VE, NM, NE, NE},
	  {VL, NM, NM, VE, NE, NE, NE, NE, NE, NM, NE, NM, NM, VE, SE, NM, NM, NE},
	  {NM, VE, NM, NM, NE, NM, VE, NE, NM, NM, NM, NM, NM, VE, VE, NM, NM, NE},
	  {NE, NE, NM, NM, NE, NM, VE, NM, NM, NM, NE, NM, NM, VE, NM, NM, NM, NM},
	  {NE, VE, NM, NM, NE, NM, NM, NM, NM, NM, NM, NM, NM, NM, VE, IN, NM, NE},
	  {NE, NM, NM, NE, VL, NM, VE, VE, VE, NM, NE, VE, NM, NM, NM, NM, NM, NM},
	  {NE, NE, NM, NM, NE, NE, NM, NM, NE, NM, NE, NE, VE, NM, SE, NM, NM, NE},
	  {NE, NE, NM, NM, NE, NM, NM, NM, VE, NM, NM, NM, NE, NM, VE, VE, VE, NE},
	  {NM, VE, NM, VE, NE, NM, NE, NM, NM, NE, VE, NE, NM, NM, SE, NM, NM, VL},
	  {NE, NM, NM, VE, IN, NM, NM, VE, NM, NM, VE, NE, NM, NE, VE, NM, NM, NE},
	  {NE, IN, NM, NM, NE, NM, NM, NM, NE, IN, NM, NE, NM, NM, VE, VE, VE, NE},
	  {NE, VE, NM, NM, NE, VE, NM, NM, VE, NM, NM, NM, IN, NM, VE, NE, NE, NE},
	  {NE, NE, NM, NM, NM, NM, NM, VE, NE, NM, NE, NM, NM, VE, IN, NM, NM, NE}
	}, {
	  {NM, NM, IN, NM, NM, NE, VE, NE, VL, NE, NE, IN, NE, NE, VE, NM, NE, NE},
	  {VE, NE, IN, NM, NM, VE, NM, NM, VL, NM, NM, VE, VE, NE, NM, NM, VL, VE},
	  {VE, NE, IN, NE, NE, VE, NE, VE, NE, NM, NE, VE, NM, NM, NM, NM, NE, NM},
	  {NM, NE, IN, NE, VE, NM, NE, NE, NE, NM, VE, VE, NM, NM, NM, NM, NE, NM},
	  {NM, NE, IN, NM, NE, NM, NM, NM, NE, NM, NM, VE, NM, NM, VE, NM, NE, NE},
	  {VE, NE, IN, NM, NM, NM, NM, NM, NE, NM, NM, VE, NM, NM, NM, NM, NE, NM},
	  {NM, NE, IN, VE, NM, NE, NE, NE, VL, NM, NE, VE, NM, VE, VE, NM, NE, NM},
	  {SE, NM, IN, NM, NM, NM, VE, NE, NE, NM, NM, VE, NM, VE, NM, NM, NE, NM},
	  {VE, VL, IN, NM, NM, NM, VE, NM, NE, NM, NE, VE, NM, VE, NE, NM, NE, VE},
	  {VE, NM, IN, NM, NM, NM, NM, NM, NE, NM, NM, VE, NM, NM, NM, IN, NE, NM},
	  {VE, NE, IN, NE, NE, NM, VE, VE, NM, NM, NE, SE, NM, NM, NE, NM, NE, VE},
	  {VE, VL, IN, NM, NM, NE, NM, NM, VL, NM, NE, NM, VE, NM, VE, NM, NE, NM},
	  {VE, VL, IN, NM, NM, NM, NM, NM, NM, NM, NM, VE, NE, NM, NM, VE, NM, NE},
	  {SE, NM, IN, VE, NM, NM, NE, NM, NE, NE, VE, NM, NM, NM, VE, NM, NE, NE},
	  {VE, NM, IN, VE, IN, NM, NM, VE, NE, NM, VE, NM, NM, NE, NM, NM, NE, NM},
	  {VE, IN, IN, NM, NM, NM, NM, NM, VL, IN, NM, NM, NM, NM, NM, VE, NM, NM},
	  {VE, NM, IN, NM, NM, VE, NM, NM, NM, NM, NM, VE, IN, NM, NM, NE, VL, NM},
	  {VE, VL, IN, NM, VE, NM, NM, VE, VL, NM, NE, VE, NM, VE, IN, NM, NE, NM}
	}, {
	  {VL, VE, NE, VE, NM, VL, NM, VL, VL, NE, VL, IN, NE, NM, SE, NM, NM, NE},
	  {NE, NM, NM, VE, NM, NM, NE, NE, VL, NM, NE, NM, VE, NM, VE, NM, NE, VE},
	  {NE, NM, VE, NM, NE, NM, VL, NM, NE, NM, VL, NM, NM, VE, VE, NM, NM, NM},
	  {VL, NM, NM, NM, VE, NE, VL, VL, NE, NM, NM, NM, NM, VE, VE, NM, NM, NM},
	  {VL, NM, NM, VE, NE, NE, NE, NE, NE, NM, NE, NM, NM, VE, SE, NM, NM, NE},
	  {NM, NE, IN, VE, NM, NE, NE, NE, VL, NM, NE, VE, NM, VE, VE, NM, NE, NM},
	  {NE, NM, NM, VE, NM, NE, NE, NE, NE, NM, NE, NM, NM, VE, VE, NM, NM, NM},
	  {NM, VE, NM, VE, NM, NE, NM, VL, NE, NM, NE, NM, NM, SE, VE, NM, NM, NM},
	  {NE, NE, NM, VE, NM, NE, NM, NE, NE, NM, VL, NM, NM, SE, NM, NM, NM, VE},
	  {NE, VE, NM, VE, NM, NE, NE, NE, NE, NM, NE, NM, NM, VE, VE, IN, NM, NM},
	  {NE, NM, NM, NM, NE, NE, NM, NM, NM, NM, VL, VE, NM, VE, NM, NM, NM, VE},
	  {NE, NE, NM, VE, NM, VL, NE, NE, VL, NM, VL, NE, VE, VE, SE, NM, NM, NM},
	  {NE, NE, NM, VE, NM, NE, NE, NE, NM, NM, NE, NM, NE, VE, VE, VE, VE, NM},
	  {NM, VE, NM, SE, NM, NE, VL, NE, NE, NE, NM, NE, NM, VE, SE, NM, NM, NE},
	  {NE, NM, NM, SE, IN, NE, NE, NM, NE, NM, NM, NE, NM, NM, VE, NM, NM, NM},
	  {NE, IN, NM, VE, NM, NE, NE, NE, VL, IN, NE, NE, NM, VE, VE, VE, VE, NM},
	  {NE, VE, NM, VE, NM, NM, NE, NE, NM, NM, NE, NM, IN, VE, VE, NE, NE, NM},
	  {NE, NE, NM, VE, VE, NE, NE, NM, VL, NM, VL, NM, NM, SE, IN, NM, NM, NM}
	}, {
	  {NM, SE, NE, NM, NM, NE, SE, VL, NE, NE, NE, IN, NE, NM, VE, NM, NM, NE},
	  {VE, VE, NM, NM, NM, VE, VE, NE, NE, NM, NM, NM, VE, NM, NM, NM, NE, VE},
	  {VE, VE, VE, NE, NE, VE, NM, NM, NM, NM, NE, NM, NM, VE, NM, NM, NM, NM},
	  {NM, VE, NM, NE, VE, NM, NM, VL, NM, NM, VE, NM, NM, VE, NM, NM, NM, NM},
	  {NM, VE, NM, NM, NE, NM, VE, NE, NM, NM, NM, NM, NM, VE, VE, NM, NM, NE},
	  {SE, NM, IN, NM, NM, NM, VE, NE, NE, NM, NM, VE, NM, VE, NM, NM, NE, NM},
	  {NM, VE, NM, VE, NM, NE, NM, VL, NE, NM, NE, NM, NM, SE, VE, NM, NM, NM},
	  {VE, VE, NM, NM, NM, NM, VE, NE, NM, NM, NM, NM, NM, VE, NM, NM, NM, NM},
	  {VE, NM, NM, NM, NM, NM, SE, NE, NM, NM, NE, NM, NM, SE, NE, NM, NM, VE},
	  {VE, SE, NM, NM, NM, NM, VE, NE, NM, NM, NM, NM, NM, VE, NM, IN, NM, NM},
	  {VE, VE, NM, NE, NE, NM, SE, NM, VE, NM, NE, VE, NM, VE, NE, NM, NM, VE},
	  {VE, NM, NM, NM, NM, NE, VE, NE, NE, NM, NE, NE, VE, VE, VE, NM, NM, NM},
	  {VE, NM, NM, NM, NM, NM, VE, NE, VE, NM, NM, NM, NE, VE, NM, VE, VE, NM},
	  {SE, SE, NM, VE, NM, NM, NM, NE, NM, NE, VE, NE, NM, VE, VE, NM, NM, NE},
	  {VE, VE, NM, VE, IN, NM, VE, NM, NM, NM, VE, NE, NM, NM, NM, NM, NM, NM},
	  {VE, IN, NM, NM, NM, NM, VE, NE, NE, IN, NM, NE, NM, VE, NM, VE, VE, NM},
	  {VE, SE, NM, NM, NM, VE, VE, NE, VE, NM, NM, NM, IN, VE, NM, NE, NE, NM},
	  {VE, NM, NM, NM, VE, NM, VE, NM, NE, NM, NE, NM, NM, SE, IN, NM, NM, NM}
	}, {
	  {NE, NM, NE, NM, NM, NE, SE, NE, NE, NE, VL, IN, NE, NM, NM, NM, NM, NM},
	  {NM, NE, NM, NM, NM, VE, VE, NM, NE, NM, NE, NM, VE, NM, NE, NM, NE, SE},
	  {NM, NE, VE, NE, NE, VE, NM, VE, NM, NM, VL, NM, NM, VE, NE, NM, NM, VE},
	  {NE, NE, NM, NE, VE, NM, NM, NE, NM, NM, NM, NM, NM, VE, NE, NM, NM, VE},
	  {NE, NE, NM, NM, NE, NM, VE, NM, NM, NM, NE, NM, NM, VE, NM, NM, NM, NM},
	  {VE, VL, IN, NM, NM, NM, VE, NM, NE, NM, NE, VE, NM, VE, NE, NM, NE, VE},
	  {NE, NE, NM, VE, NM, NE, NM, NE, NE, NM, VL, NM, NM, SE, NM, NM, NM, VE},
	  {VE, NM, NM, NM, NM, NM, SE, NE, NM, NM, NE, NM, NM, SE, NE, NM, NM, VE},
	  {NM, NE, NM, NM, NM, NM, VE, NM, NM, NM, NE, NM, NM, VE, NE, NM, NM, VE},
	  {NM, NM, NM, NM, NM, NM, VE, NM, NM, NM, NE, NM, NM, VE, NE, IN, NM, VE},
	  {NM, NE, NM, NE, NE, NM, SE, VE, VE, NM, VL, VE, NM, VE, VL, NM, NM, SE},
	  {NM, VL, NM, NM, NM, NE, VE, NM, NE, NM, VL, NE, VE, VE, NM, NM, NM, VE},
	  {NM, VL, NM, NM, NM, NM, VE, NM, VE, NM, NE, NM, NE, VE, NE, VE, VE, VE},
	  {VE, NM, NM, VE, NM, NM, NM, NM, NM, NE, NM, NE, NM, VE, NM, NM, NM, NM},
	  {NM, NE, NM, VE, IN, NM, VE, VE, NM, NM, NM, NE, NM, NM, NE, NM, NM, VE},
	  {NM, IN, NM, NM, NM, NM, VE, NM, NE, IN, NE, NE, NM, VE, NE, VE, VE, VE},
	  {NM, NM, NM, NM, NM, VE, VE, NM, VE, NM, NE, NM, IN, VE, NE, NE, NE, VE},
	  {NM, VL, NM, NM, VE, NM, VE, VE, NE, NM, VL, NM, NM, SE, IN, NM, NM, VE}
	}, {
	  {NE, SE, NE, NM, NM, NE, VE, NE, NE, NE, NE, IN, NM, NE, VE, IN, NE, NE},
	  {NM, VE, NM, NM, NM, VE, NM, NM, NE, NM, NM, NM, VE, NE, NM, IN, NE, VE},
	  {NM, VE, VE, NE, NE, VE, NE, VE, NM, NM, NE, NM, NM, NM, NM, IN, NM, NM},
	  {NE, VE, NM, NE, VE, NM, NE, NE, NM, NM, VE, NM, NM, NM, NM, IN, NM, NM},
	  {NE, VE, NM, NM, NE, NM, NM, NM, NM, NM, NM, NM, NM, NM, VE, IN, NM, NE},
	  {VE, NM, IN, NM, NM, NM, NM, NM, NE, NM, NM, VE, NM, NM, NM, IN, NE, NM},
	  {NE, VE, NM, VE, NM, NE, NE, NE, NE, NM, NE, NM, NM, VE, VE, IN, NM, NM},
	  {VE, SE, NM, NM, NM, NM, VE, NE, NM, NM, NM, NM, NM, VE, NM, IN, NM, NM},
	  {NM, NM, NM, NM, NM, NM, VE, NM, NM, NM, NE, NM, NM, VE, NE, IN, NM, VE},
	  {NM, VE, NM, NM, NM, NM, NM, NM, NM, NM, NM, NM, NM, NM, NM, IN, IN, IN},
	  {NM, VE, NM, NE, NE, NM, VE, VE, VE, NM, NE, VE, NM, NM, NE, IN, NM, VE},
	  {NM, NM, NM, NM, NM, NE, NM, NM, NE, NM, NE, NE, VE, NM, VE, IN, NM, NM},
	  {NM, NM, NM, NM, NM, NM, NM, NM, VE, NM, NM, NM, NE, NM, NM, IN, VE, NM},
	  {VE, SE, NM, VE, NM, NM, NE, NM, NM, NE, VE, NE, NM, NM, VE, IN, NM, NE},
	  {NM, VE, NM, VE, IN, NM, NM, VE, NM, NM, VE, NE, NM, NE, NM, IN, NM, NM},
	  {NM, IN, NM, NM, NM, NM, NM, NM, NE, IN, NM, NE, NM, NM, NM, IN, VE, NM},
	  {NM, SE, NM, NM, NM, VE, NM, NM, VE, NM, NM, NM, IN, NM, NM, IN, NE, NM},
	  {NM, NM, NM, NM, VE, NM, NM, VE, NE, NM, NE, NM, NM, VE, IN, IN, NM, NM}
	}, {
	  {NE, VE, NE, NE, NE, NE, SE, NM, NM, NE, VL, IN, NE, NE, NM, NM, NM, NM},
	  {NM, NM, NM, NE, NE, VE, VE, VE, NM, NM, NE, VE, VE, NE, NE, NM, NE, SE},
	  {NM, NM, VE, VL, VL, VE, NM, SE, VE, NM, VL, VE, NM, NM, NE, NM, NM, VE},
	  {NE, NM, NM, VL, NM, NM, NM, NM, VE, NM, NM, VE, NM, NM, NE, NM, NM, VE},
	  {NE, NM, NM, NE, VL, NM, VE, VE, VE, NM, NE, VE, NM, NM, NM, NM, NM, NM},
	  {VE, NE, IN, NE, NE, NM, VE, VE, NM, NM, NE, SE, NM, NM, NE, NM, NE, VE},
	  {NE, NM, NM, NM, NE, NE, NM, NM, NM, NM, VL, VE, NM, VE, NM, NM, NM, VE},
	  {VE, VE, NM, NE, NE, NM, SE, NM, VE, NM, NE, VE, NM, VE, NE, NM, NM, VE},
	  {NM, NE, NM, NE, NE, NM, SE, VE, VE, NM, VL, VE, NM, VE, VL, NM, NM, SE},
	  {NM, VE, NM, NE, NE, NM, VE, VE, VE, NM, NE, VE, NM, NM, NE, IN, NM, VE},
	  {NM, NM, NM, NE, NE, NM, VE, VE, VE, NM, NE, VE, NM, NM, NE, NM, NM, VE},
	  {NM, NE, NM, NE, NE, NE, VE, VE, NM, NM, VL, NM, VE, NM, NM, NM, NM, VE},
	  {NM, NE, NM, NE, NE, NM, VE, VE, SE, NM, NE, VE, NE, NM, NE, VE, VE, VE},
	  {VE, VE, NM, NM, NE, NM, NM, VE, VE, NE, NM, NM, NM, NM, NM, NM, NM, NM},
	  {NM, NM, NM, NM, IN, NM, VE, SE, VE, NM, NM, NM, NM, NE, NE, NM, NM, VE},
	  {NM, IN, NM, NE, NE, NM, VE, VE, NM, IN, NE, NM, NM, NM, NE, VE, VE, VE},
	  {NM, VE, NM, NE, NE, VE, VE, VE, SE, NM, NE, VE, IN, NM, NE, NE, NE, VE},
	  {NM, NE, NM, NE, NM, NM, VE, SE, NM, NM, VL, VE, NM, VE, IN, NM, NM, VE}
	}, {
	  {NE, NM, NE, NM, NM, VL, VE, NE, VL, NE, VL, IN, NM, NE, SE, NM, NM, NE},
	  {NM, NE, NM, NM, NM, NM, NM, NM, VL, NM, NE, NE, SE, NE, VE, NM, NE, VE},
	  {NM, NE, VE, NE, NE, NM, NE, VE, NE, NM, VL, NE, VE, NM, VE, NM, NM, NM},
	  {NE, NE, NM, NE, VE, NE, NE, NE, NE, NM, NM, NE, VE, NM, VE, NM, NM, NM},
	  {NE, NE, NM, NM, NE, NE, NM, NM, NE, NM, NE, NE, VE, NM, SE, NM, NM, NE},
	  {VE, VL, IN, NM, NM, NE, NM, NM, VL, NM, NE, NM, VE, NM, VE, NM, NE, NM},
	  {NE, NE, NM, VE, NM, VL, NE, NE, VL, NM, VL, NE, VE, VE, SE, NM, NM, NM},
	  {VE, NM, NM, NM, NM, NE, VE, NE, NE, NM, NE, NE, VE, VE, VE, NM, NM, NM},
	  {NM, VL, NM, NM, NM, NE, VE, NM, NE, NM, VL, NE, VE, VE, NM, NM, NM, VE},
	  {NM, NM, NM, NM, NM, NE, NM, NM, NE, NM, NE, NE, VE, NM, VE, IN, NM, NM},
	  {NM, NE, NM, NE, NE, NE, VE, VE, NM, NM, VL, NM, VE, NM, NM, NM, NM, VE},
	  {NM, NE, NM, NM, NM, NE, NM, NM, NE, NM, NE, NE, VE, NM, VE, NM, NM, NM},
	  {NM, VL, NM, NM, NM, NE, NM, NM, NM, NM, NE, NE, NM, NM, VE, VE, VE, NM},
	  {VE, NM, NM, VE, NM, NE, NE, NM, NE, NE, NM, VL, VE, NM, SE, NM, NM, NE},
	  {NM, NE, NM, VE, IN, NE, NM, VE, NE, NM, NM, VL, VE, NE, VE, NM, NM, NM},
	  {NM, IN, NM, NM, NM, NE, NM, NM, VL, IN, NE, VL, VE, NM, VE, VE, VE, NM},
	  {NM, NM, NM, NM, NM, NM, NM, NM, NM, NM, NE, NE, IN, NM, VE, NE, NE, NM},
	  {NM, VL, NM, NM, VE, NE, NM, VE, VL, NM, VL, NE, VE, VE, IN, NM, NM, NM}
	}, {
	  {NE, NM, NE, NM, NM, NE, VE, NE, NM, NE, NE, IN, VL, NE, VE, VE, VE, NE},
	  {NM, NE, NM, NM, NM, VE, NM, NM, NM, NM, NM, NM, NM, NE, NM, VE, NM, VE},
	  {NM, NE, VE, NE, NE, VE, NE, VE, VE, NM, NE, NM, NE, NM, NM, VE, VE, NM},
	  {NE, NE, NM, NE, VE, NM, NE, NE, VE, NM, VE, NM, NE, NM, NM, VE, VE, NM},
	  {NE, NE, NM, NM, NE, NM, NM, NM, VE, NM, NM, NM, NE, NM, VE, VE, VE, NE},
	  {VE, VL, IN, NM, NM, NM, NM, NM, NM, NM, NM, VE, NE, NM, NM, VE, NM, NE},
	  {NE, NE, NM, VE, NM, NE, NE, NE, NM, NM, NE, NM, NE, VE, VE, VE, VE, NM},
	  {VE, NM, NM, NM, NM, NM, VE, NE, VE, NM, NM, NM, NE, VE, NM, VE, VE, NM},
	  {NM, VL, NM, NM, NM, NM, VE, NM, VE, NM, NE, NM, NE, VE, NE, VE, VE, VE},
	  {NM, NM, NM, NM, NM, NM, NM, NM, VE, NM, NM, NM, NE, NM, NM, IN, VE, NM},
	  {NM, NE, NM, NE, NE, NM, VE, VE, SE, NM, NE, VE, NE, NM, NE, VE, VE, VE},
	  {NM, VL, NM, NM, NM, NE, NM, NM, NM, NM, NE, NE, NM, NM, VE, VE, VE, NM},
	  {NM, NE, NM, NM, NM, NM, NM, NM, VE, NM, NM, NM, NE, NM, NM, VE, VE, NM},
	  {VE, NM, NM, VE, NM, NM, NE, NM, VE, NE, VE, NE, NE, NM, VE, VE, VE, NE},
	  {NM, NE, NM, VE, IN, NM, NM, VE, VE, NM, VE, NE, NE, NE, NM, VE, VE, NM},
	  {NM, IN, NM, NM, NM, NM, NM, NM, NM, IN, NM, NE, NE, NM, NM, SE, SE, NM},
	  {NM, NM, NM, NM, NM, VE, NM, NM, SE, NM, NM, NM, IN, NM, NM, IN, IN, IN},
	  {NM, VL, NM, NM, VE, NM, NM, VE, NM, NM, NE, NM, NE, VE, IN, VE, VE, NM}
	}, {
	  {NM, SE, NE, VE, NM, NE, NM, NE, NE, VL, NM, IN, NE, NE, SE, NM, NM, VL},
	  {VE, VE, NM, VE, NM, VE, NE, NM, NE, NE, VE, NE, VE, NE, VE, NM, NE, NM},
	  {VE, VE, VE, NM, NE, VE, VL, VE, NM, NE, NM, NE, NM, NM, VE, NM, NM, NE},
	  {NM, VE, NM, NM, VE, NM, VL, NE, NM, NE, SE, NE, NM, NM, VE, NM, NM, NE},
	  {NM, VE, NM, VE, NE, NM, NE, NM, NM, NE, VE, NE, NM, NM, SE, NM, NM, VL},
	  {SE, NM, IN, VE, NM, NM, NE, NM, NE, NE, VE, NM, NM, NM, VE, NM, NE, NE},
	  {NM, VE, NM, SE, NM, NE, VL, NE, NE, NE, NM, NE, NM, VE, SE, NM, NM, NE},
	  {SE, SE, NM, VE, NM, NM, NM, NE, NM, NE, VE, NE, NM, VE, VE, NM, NM, NE},
	  {VE, NM, NM, VE, NM, NM, NM, NM, NM, NE, NM, NE, NM, VE, NM, NM, NM, NM},
	  {VE, SE, NM, VE, NM, NM, NE, NM, NM, NE, VE, NE, NM, NM, VE, IN, NM, NE},
	  {VE, VE, NM, NM, NE, NM, NM, VE, VE, NE, NM, NM, NM, NM, NM, NM, NM, NM},
	  {VE, NM, NM, VE, NM, NE, NE, NM, NE, NE, NM, VL, VE, NM, SE, NM, NM, NE},
	  {VE, NM, NM, VE, NM, NM, NE, NM, VE, NE, VE, NE, NE, NM, VE, VE, VE, NE},
	  {VE, VE, NM, VE, NM, NM, NE, NM, NM, NE, VE, NE, NM, NM, VE, NM, NM, NE},
	  {VE, VE, NM, SE, IN, NM, NE, VE, NM, NE, SE, VL, NM, NE, VE, NM, NM, NE},
	  {VE, IN, NM, VE, NM, NM, NE, NM, NE, IN, VE, VL, NM, NM, VE, VE, VE, NE},
	  {VE, SE, NM, VE, NM, VE, NE, NM, VE, NE, VE, NE, IN, NM, VE, NE, NE, NE},
	  {VE, NM, NM, VE, VE, NM, NE, VE, NE, NE, NM, NE, NM, VE, IN, NM, NM, NE}
	}, {
	  {NE, VE, NE, VE, IN, NE, VE, NM, NE, NE, NM, IN, NE, VL, VE, NM, NM, NE},
	  {NM, NM, NM, VE, IN, VE, NM, VE, NE, NM, VE, NE, VE, VL, NM, NM, NE, VE},
	  {NM, NM, VE, NM, IN, VE, NE, SE, NM, NM, NM, NE, NM, NE, NM, NM, NM, NM},
	  {NE, NM, NM, NM, IN, NM, NE, NM, NM, NM, SE, NE, NM, NE, NM, NM, NM, NM},
	  {NE, NM, NM, VE, IN, NM, NM, VE, NM, NM, VE, NE, NM, NE, VE, NM, NM, NE},
	  {VE, NM, IN, VE, IN, NM, NM, VE, NE, NM, VE, NM, NM, NE, NM, NM, NE, NM},
	  {NE, NM, NM, SE, IN, NE, NE, NM, NE, NM, NM, NE, NM, NM, VE, NM, NM, NM},
	  {VE, VE, NM, VE, IN, NM, VE, NM, NM, NM, VE, NE, NM, NM, NM, NM, NM, NM},
	  {NM, NE, NM, VE, IN, NM, VE, VE, NM, NM, NM, NE, NM, NM, NE, NM, NM, VE},
	  {NM, VE, NM, VE, IN, NM, NM, VE, NM, NM, VE, NE, NM, NE, NM, IN, NM, NM},
	  {NM, NM, NM, NM, IN, NM, VE, SE, VE, NM, NM, NM, NM, NE, NE, NM, NM, VE},
	  {NM, NE, NM, VE, IN, NE, NM, VE, NE, NM, NM, VL, VE, NE, VE, NM, NM, NM},
	  {NM, NE, NM, VE, IN, NM, NM, VE, VE, NM, VE, NE, NE, NE, NM, VE, VE, NM},
	  {VE, VE, NM, SE, IN, NM, NE, VE, NM, NE, SE, VL, NM, NE, VE, NM, NM, NE},
	  {NM, NM, NM, VE, IN, NM, NM, VE, NM, NM, VE, NE, NM, NE, NM, NM, NM, NM},
	  {NM, IN, NM, VE, IN, NM, NM, VE, NE, IN, VE, VL, NM, NE, NM, VE, VE, NM},
	  {NM, VE, NM, VE, IN, VE, NM, VE, VE, NM, VE, NE, IN, NE, NM, NE, NE, NM},
	  {NM, NE, NM, VE, IN, NM, NM, SE, NE, NM, NM, NE, NM, NM, IN, NM, NM, NM}
	}, {
	  {NE, IN, NE, NM, NM, NE, VE, NE, VL, IN, NE, IN, NE, NE, VE, VE, VE, NE},
	  {NM, IN, NM, NM, NM, VE, NM, NM, VL, IN, NM, NE, VE, NE, NM, VE, NM, VE},
	  {NM, IN, VE, NE, NE, VE, NE, VE, NE, IN, NE, NE, NM, NM, NM, VE, VE, NM},
	  {NE, IN, NM, NE, VE, NM, NE, NE, NE, IN, VE, NE, NM, NM, NM, VE, VE, NM},
	  {NE, IN, NM, NM, NE, NM, NM, NM, NE, IN, NM, NE, NM, NM, VE, VE, VE, NE},
	  {VE, IN, IN, NM, NM, NM, NM, NM, VL, IN, NM, NM, NM, NM, NM, VE, NM, NM},
	  {NE, IN, NM, VE, NM, NE, NE, NE, VL, IN, NE, NE, NM, VE, VE, VE, VE, NM},
	  {VE, IN, NM, NM, NM, NM, VE, NE, NE, IN, NM, NE, NM, VE, NM, VE, VE, NM},
	  {NM, IN, NM, NM, NM, NM, VE, NM, NE, IN, NE, NE, NM, VE, NE, VE, VE, VE},
	  {NM, IN, NM, NM, NM, NM, NM, NM, NE, IN, NM, NE, NM, NM, NM, IN, VE, NM},
	  {NM, IN, NM, NE, NE, NM, VE, VE, NM, IN, NE, NM, NM, NM, NE, VE, VE, VE},
	  {NM, IN, NM, NM, NM, NE, NM, NM, VL, IN, NE, VL, VE, NM, VE, VE, VE, NM},
	  {NM, IN, NM, NM, NM, NM, NM, NM, NM, IN, NM, NE, NE, NM, NM, SE, SE, NM},
	  {VE, IN, NM, VE, NM, NM, NE, NM, NE, IN, VE, VL, NM, NM, VE, VE, VE, NE},
	  {NM, IN, NM, VE, IN, NM, NM, VE, NE, IN, VE, VL, NM, NE, NM, VE, VE, NM},
	  {NM, IN, NM, NM, NM, NM, NM, NM, NE, IN, NM, NE, NM, NM, NM, VE, VE, NM},
	  {NM, IN, NM, NM, NM, VE, NM, NM, NM, IN, NM, NE, IN, NM, NM, NM, NM, NM},
	  {NM, IN, NM, NM, VE, NM, NM, VE, VL, IN, NE, NE, NM, VE, IN, VE, VE, NM}
	}, {
	  {NE, SE, NE, NM, NM, NM, VE, NE, NM, NE, NE, IN, IN, NE, VE, NE, NE, NE},
	  {NM, VE, NM, NM, NM, SE, NM, NM, NM, NM, NM, NM, IN, NE, NM, NE, VL, VE},
	  {NM, VE, VE, NE, NE, SE, NE, VE, VE, NM, NE, NM, IN, NM, NM, NE, NE, NM},
	  {NE, VE, NM, NE, VE, VE, NE, NE, VE, NM, VE, NM, IN, NM, NM, NE, NE, NM},
	  {NE, VE, NM, NM, NE, VE, NM, NM, VE, NM, NM, NM, IN, NM, VE, NE, NE, NE},
	  {VE, NM, IN, NM, NM, VE, NM, NM, NM, NM, NM, VE, IN, NM, NM, NE, VL, NM},
	  {NE, VE, NM, VE, NM, NM, NE, NE, NM, NM, NE, NM, IN, VE, VE, NE, NE, NM},
	  {VE, SE, NM, NM, NM, VE, VE, NE, VE, NM, NM, NM, IN, VE, NM, NE, NE, NM},
	  {NM, NM, NM, NM, NM, VE, VE, NM, VE, NM, NE, NM, IN, VE, NE, NE, NE, VE},
	  {NM, SE, NM, NM, NM, VE, NM, NM, VE, NM, NM, NM, IN, NM, NM, IN, NE, NM},
	  {NM, VE, NM, NE, NE, VE, VE, VE, SE, NM, NE, VE, IN, NM, NE, NE, NE, VE},
	  {NM, NM, NM, NM, NM, NM, NM, NM, NM, NM, NE, NE, IN, NM, VE, NE, NE, NM},
	  {NM, NM, NM, NM, NM, VE, NM, NM, SE, NM, NM, NM, IN, NM, NM, IN, IN, IN},
	  {VE, SE, NM, VE, NM, VE, NE, NM, VE, NE, VE, NE, IN, NM, VE, NE, NE, NE},
	  {NM, VE, NM, VE, IN, VE, NM, VE, VE, NM, VE, NE, IN, NE, NM, NE, NE, NM},
	  {NM, IN, NM, NM, NM, VE, NM, NM, NM, IN, NM, NE, IN, NM, NM, NM, NM, NM},
	  {NM, VE, NM, NM, NM, VE, NM, NM, VE, NM, NM, NM, IN, NM, NM, NE, NE, NM},
	  {NM, NM, NM, NM, VE, VE, NM, VE, NM, NM, NE, NM, IN, VE, IN, NE, NE, NM}
	}, {
	  {NE, NM, NE, NM, VE, NE, VE, NM, VL, NE, VL, IN, NE, NM, IN, NM, NM, NE},
	  {NM, NE, NM, NM, VE, VE, NM, VE, VL, NM, NE, NM, VE, NM, IN, NM, NE, VE},
	  {NM, NE, VE, NE, NM, VE, NE, SE, NE, NM, VL, NM, NM, VE, IN, NM, NM, NM},
	  {NE, NE, NM, NE, SE, NM, NE, NM, NE, NM, NM, NM, NM, VE, IN, NM, NM, NM},
	  {NE, NE, NM, NM, NM, NM, NM, VE, NE, NM, NE, NM, NM, VE, IN, NM, NM, NE},
	  {VE, VL, IN, NM, VE, NM, NM, VE, VL, NM, NE, VE, NM, VE, IN, NM, NE, NM},
	  {NE, NE, NM, VE, VE, NE, NE, NM, VL, NM, VL, NM, NM, SE, IN, NM, NM, NM},
	  {VE, NM, NM, NM, VE, NM, VE, NM, NE, NM, NE, NM, NM, SE, IN, NM, NM, NM},
	  {NM, VL, NM, NM, VE, NM, VE, VE, NE, NM, VL, NM, NM, SE, IN, NM, NM, VE},
	  {NM, NM, NM, NM, VE, NM, NM, VE, NE, NM, NE, NM, NM, VE, IN, IN, NM, NM},
	  {NM, NE, NM, NE, NM, NM, VE, SE, NM, NM, VL, VE, NM, VE, IN, NM, NM, VE},
	  {NM, VL, NM, NM, VE, NE, NM, VE, VL, NM, VL, NE, VE, VE, IN, NM, NM, NM},
	  {NM, VL, NM, NM, VE, NM, NM, VE, NM, NM, NE, NM, NE, VE, IN, VE, VE, NM},
	  {VE, NM, NM, VE, VE, NM, NE, VE, NE, NE, NM, NE, NM, VE, IN, NM, NM, NE},
	  {NM, NE, NM, VE, IN, NM, NM, SE, NE, NM, NM, NE, NM, NM, IN, NM, NM, NM},
	  {NM, IN, NM, NM, VE, NM, NM, VE, VL, IN, NE, NE, NM, VE, IN, VE, VE, NM},
	  {NM, NM, NM, NM, VE, VE, NM, VE, NM, NM, NE, NM, IN, VE, IN, NE, NE, NM},
	  {NM, NE, NM, NM, VE, NM, NM, VE, NE, NM, NE, NM, NM, VE, IN, NM, NM, NM}
	}
      };


      float calcEfficacite(Type atk, Type def1, Type def2) {
	int atkI((int)atk), type1I((int)def1), type2I((int)def2);
	if (def2 == Type::NOTHING) {
	  return arrOneType[type1I][atkI];
	} else {
	  return arrTwoTypes[type1I][type2I][atkI];
	}
      }
    }

    bool operator==(Side side, int integer){
      if(((int) side) == integer){
	return true;
      }else{
	return false;
      }
    }

    bool operator!=(Side side, int integer){
      return !(side == integer);
    }

    bool operator>=(Side side, int integer){
      int sideInt = (int) side;
      return sideInt >= integer;
    }

    bool operator>(Side side, int integer){
      int sideInt = (int) side;
      return sideInt > integer;
    }

    bool operator<(Side side, int integer){
      int sideInt = (int) side;
      return sideInt < integer;
    }

    bool operator<=(Side side, int integer){
      int sideInt = (int) side;
      return sideInt <= integer;
    }

    int operator+(Side side, int integer){
      return ((int) side) + integer;
    }

    Side getSide(int id){
      switch(id){
      case -1:
	return Side::NO_MOVE;
      case 0:
	return Side::TO_DOWN;
      case 1:
	return Side::TO_RIGHT;
      case 2:
	return Side::TO_LEFT;
      case 3:
	return Side::TO_UP;
      case -2:
	return Side::STAY;
      default:
	return Side::NO_MOVE;
      }
    }

    int operator-(Side side, int integer){
      return ((int)side) - integer;
    }

  }
}
