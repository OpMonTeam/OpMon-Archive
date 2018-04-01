#include "Enums.hpp"

namespace OpMon {
    namespace Model {

        namespace ArrayTypes {
            const float arrOneType[][18] = {

              {LO_, HI_, LO_, AVG, AVG, LO_, HI_, LO_, LO_, LO_, LO_, NOT, LO_, LO_, HI_, AVG, AVG, LO_},
              {AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, LO_, AVG, AVG, AVG, HI_, LO_, AVG, AVG, LO_, HI_},
              {AVG, AVG, HI_, LO_, LO_, HI_, LO_, HI_, AVG, AVG, LO_, AVG, AVG, AVG, AVG, AVG, AVG, AVG},
              {LO_, AVG, AVG, LO_, HI_, AVG, LO_, LO_, AVG, AVG, HI_, AVG, AVG, AVG, AVG, AVG, AVG, AVG},
              {LO_, AVG, AVG, AVG, LO_, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, LO_},
              {HI_, LO_, NOT, AVG, AVG, AVG, AVG, AVG, LO_, AVG, AVG, HI_, AVG, AVG, AVG, AVG, LO_, AVG},
              {LO_, AVG, AVG, HI_, AVG, LO_, LO_, LO_, LO_, AVG, LO_, AVG, AVG, HI_, HI_, AVG, AVG, AVG},
              {HI_, HI_, AVG, AVG, AVG, AVG, HI_, LO_, AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, AVG, AVG},
              {AVG, LO_, AVG, AVG, AVG, AVG, HI_, AVG, AVG, AVG, LO_, AVG, AVG, HI_, LO_, AVG, AVG, HI_},
              {AVG, HI_, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, NOT, AVG, AVG},
              {AVG, AVG, AVG, LO_, LO_, AVG, HI_, HI_, HI_, AVG, LO_, HI_, AVG, AVG, LO_, AVG, AVG, HI_},
              {AVG, LO_, AVG, AVG, AVG, LO_, AVG, AVG, LO_, AVG, LO_, LO_, HI_, AVG, HI_, AVG, AVG, AVG},
              {AVG, LO_, AVG, AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, AVG, LO_, AVG, AVG, HI_, HI_, LO_},
              {HI_, HI_, AVG, HI_, AVG, AVG, LO_, AVG, AVG, LO_, HI_, LO_, AVG, AVG, HI_, AVG, AVG, LO_},
              {AVG, AVG, AVG, HI_, NOT, AVG, AVG, HI_, AVG, AVG, HI_, LO_, AVG, LO_, AVG, AVG, AVG, AVG},
              {AVG, NOT, AVG, AVG, AVG, AVG, AVG, AVG, LO_, NOT, AVG, LO_, AVG, AVG, AVG, HI_, HI_, AVG},
              {AVG, HI_, AVG, AVG, AVG, HI_, AVG, AVG, HI_, AVG, AVG, AVG, NOT, AVG, AVG, LO_, LO_, AVG},
              {AVG, LO_, AVG, AVG, HI_, AVG, AVG, HI_, LO_, AVG, LO_, AVG, AVG, HI_, NOT, AVG, AVG, AVG}};
            /**Un tableau qui réunit tous les tables a double type*/
            const float arrTwoTypes[][18][18] = {{{VLO, VHI, VLO, AVG, AVG, VLO, VHI, VLO, VLO, VLO, VLO, NOT, VLO, VLO, VHI, AVG, AVG, VLO},
                                                  {LO_, HI_, LO_, AVG, AVG, AVG, HI_, LO_, VLO, LO_, LO_, NOT, AVG, VLO, HI_, AVG, LO_, AVG},
                                                  {LO_, HI_, AVG, LO_, LO_, AVG, AVG, AVG, LO_, LO_, VLO, NOT, LO_, LO_, HI_, AVG, AVG, LO_},
                                                  {VLO, HI_, LO_, LO_, HI_, LO_, AVG, VLO, LO_, LO_, AVG, NOT, LO_, LO_, HI_, AVG, AVG, LO_},
                                                  {VLO, HI_, LO_, AVG, LO_, LO_, HI_, LO_, LO_, LO_, LO_, NOT, LO_, LO_, VHI, AVG, AVG, VLO},
                                                  {AVG, AVG, NOT, AVG, AVG, LO_, HI_, LO_, VLO, LO_, LO_, NOT, LO_, LO_, HI_, AVG, LO_, LO_},
                                                  {VLO, HI_, LO_, HI_, AVG, VLO, AVG, VLO, VLO, LO_, VLO, NOT, LO_, AVG, VHI, AVG, AVG, LO_},
                                                  {AVG, VHI, LO_, AVG, AVG, LO_, VHI, VLO, LO_, LO_, LO_, NOT, LO_, AVG, HI_, AVG, AVG, LO_},
                                                  {LO_, AVG, LO_, AVG, AVG, VLO, VHI, LO_, LO_, LO_, VLO, NOT, AVG, AVG, AVG, LO_, LO_, AVG},
                                                  {LO_, VHI, LO_, AVG, AVG, LO_, HI_, LO_, LO_, LO_, LO_, NOT, LO_, LO_, HI_, NOT, AVG, LO_},
                                                  {LO_, HI_, LO_, LO_, LO_, LO_, VHI, AVG, AVG, LO_, VLO, NOT, LO_, LO_, AVG, AVG, AVG, AVG},
                                                  {LO_, AVG, LO_, AVG, AVG, VLO, HI_, LO_, VLO, LO_, VLO, NOT, AVG, LO_, VHI, AVG, AVG, LO_},
                                                  {LO_, AVG, LO_, AVG, AVG, LO_, HI_, LO_, AVG, LO_, LO_, NOT, VLO, LO_, HI_, HI_, HI_, LO_},
                                                  {AVG, VHI, LO_, HI_, AVG, LO_, AVG, LO_, LO_, VLO, AVG, NOT, LO_, LO_, VHI, AVG, AVG, VLO},
                                                  {LO_, HI_, LO_, HI_, NOT, LO_, HI_, AVG, LO_, LO_, AVG, NOT, LO_, VLO, HI_, AVG, AVG, LO_},
                                                  {LO_, NOT, LO_, AVG, AVG, LO_, HI_, LO_, VLO, NOT, LO_, NOT, LO_, LO_, HI_, HI_, HI_, LO_},
                                                  {LO_, VHI, LO_, AVG, AVG, AVG, HI_, LO_, AVG, LO_, LO_, NOT, NOT, LO_, HI_, LO_, LO_, LO_},
                                                  {LO_, AVG, LO_, AVG, HI_, LO_, HI_, AVG, VLO, LO_, VLO, NOT, LO_, AVG, NOT, AVG, AVG, LO_}},
                                                 {

                                                   {LO_, HI_, LO_, AVG, AVG, AVG, HI_, LO_, VLO, LO_, LO_, NOT, AVG, VLO, HI_, AVG, LO_, AVG},
                                                   {AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, LO_, AVG, AVG, AVG, HI_, LO_, AVG, AVG, LO_, HI_},
                                                   {AVG, AVG, HI_, LO_, LO_, VHI, LO_, HI_, LO_, AVG, LO_, AVG, HI_, LO_, AVG, AVG, LO_, HI_},
                                                   {LO_, AVG, AVG, LO_, HI_, HI_, LO_, LO_, LO_, AVG, HI_, AVG, HI_, LO_, AVG, AVG, LO_, HI_},
                                                   {LO_, AVG, AVG, AVG, LO_, HI_, AVG, AVG, LO_, AVG, AVG, AVG, HI_, LO_, HI_, AVG, LO_, AVG},
                                                   {HI_, LO_, NOT, AVG, AVG, HI_, AVG, AVG, VLO, AVG, AVG, HI_, HI_, LO_, AVG, AVG, VLO, HI_},
                                                   {LO_, AVG, AVG, HI_, AVG, AVG, LO_, LO_, VLO, AVG, LO_, AVG, HI_, AVG, HI_, AVG, LO_, HI_},
                                                   {HI_, HI_, AVG, AVG, AVG, HI_, HI_, LO_, LO_, AVG, AVG, AVG, HI_, AVG, AVG, AVG, LO_, HI_},
                                                   {AVG, LO_, AVG, AVG, AVG, HI_, HI_, AVG, LO_, AVG, LO_, AVG, HI_, AVG, LO_, AVG, LO_, VHI},
                                                   {AVG, HI_, AVG, AVG, AVG, HI_, AVG, AVG, LO_, AVG, AVG, AVG, HI_, LO_, AVG, NOT, LO_, HI_},
                                                   {AVG, AVG, AVG, LO_, LO_, HI_, HI_, HI_, AVG, AVG, LO_, HI_, HI_, LO_, LO_, AVG, LO_, VHI},
                                                   {AVG, LO_, AVG, AVG, AVG, AVG, AVG, AVG, VLO, AVG, LO_, LO_, VHI, LO_, HI_, AVG, LO_, HI_},
                                                   {AVG, LO_, AVG, AVG, AVG, HI_, AVG, AVG, AVG, AVG, AVG, AVG, AVG, LO_, AVG, HI_, AVG, HI_},
                                                   {HI_, HI_, AVG, HI_, AVG, HI_, LO_, AVG, LO_, LO_, HI_, LO_, HI_, LO_, HI_, AVG, LO_, AVG},
                                                   {AVG, AVG, AVG, HI_, NOT, HI_, AVG, HI_, LO_, AVG, HI_, LO_, HI_, VLO, AVG, AVG, LO_, HI_},
                                                   {AVG, NOT, AVG, AVG, AVG, HI_, AVG, AVG, VLO, NOT, AVG, LO_, HI_, LO_, AVG, HI_, AVG, HI_},
                                                   {AVG, HI_, AVG, AVG, AVG, VHI, AVG, AVG, AVG, AVG, AVG, AVG, NOT, LO_, AVG, LO_, VLO, HI_},
                                                   {AVG, LO_, AVG, AVG, HI_, HI_, AVG, HI_, VLO, AVG, LO_, AVG, HI_, AVG, NOT, AVG, LO_, HI_}},
                                                 {

                                                   {LO_, HI_, AVG, LO_, LO_, AVG, AVG, AVG, LO_, LO_, VLO, NOT, LO_, LO_, HI_, AVG, AVG, LO_},
                                                   {AVG, AVG, HI_, LO_, LO_, VHI, LO_, HI_, LO_, AVG, LO_, AVG, HI_, LO_, AVG, AVG, LO_, HI_},
                                                   {AVG, AVG, HI_, LO_, LO_, HI_, LO_, HI_, AVG, AVG, LO_, AVG, AVG, AVG, AVG, AVG, AVG, AVG},
                                                   {LO_, AVG, HI_, VLO, AVG, HI_, VLO, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG},
                                                   {LO_, AVG, HI_, LO_, VLO, HI_, LO_, HI_, AVG, AVG, LO_, AVG, AVG, AVG, HI_, AVG, AVG, LO_},
                                                   {HI_, LO_, NOT, LO_, LO_, HI_, LO_, HI_, LO_, AVG, LO_, HI_, AVG, AVG, AVG, AVG, LO_, AVG},
                                                   {LO_, AVG, HI_, AVG, LO_, AVG, VLO, AVG, LO_, AVG, VLO, AVG, AVG, HI_, HI_, AVG, AVG, AVG},
                                                   {HI_, HI_, HI_, LO_, LO_, HI_, AVG, AVG, AVG, AVG, LO_, AVG, AVG, HI_, AVG, AVG, AVG, AVG},
                                                   {AVG, LO_, HI_, LO_, LO_, HI_, AVG, HI_, AVG, AVG, VLO, AVG, AVG, HI_, LO_, AVG, AVG, HI_},
                                                   {AVG, HI_, HI_, LO_, LO_, HI_, LO_, HI_, AVG, AVG, LO_, AVG, AVG, AVG, AVG, NOT, AVG, AVG},
                                                   {AVG, AVG, HI_, VLO, VLO, HI_, AVG, VHI, HI_, AVG, VLO, HI_, AVG, AVG, LO_, AVG, AVG, HI_},
                                                   {AVG, LO_, HI_, LO_, LO_, AVG, LO_, HI_, LO_, AVG, VLO, LO_, HI_, AVG, HI_, AVG, AVG, AVG},
                                                   {AVG, LO_, HI_, LO_, LO_, HI_, LO_, HI_, HI_, AVG, LO_, AVG, LO_, AVG, AVG, HI_, HI_, AVG},
                                                   {HI_, HI_, HI_, AVG, LO_, HI_, VLO, HI_, AVG, LO_, AVG, LO_, AVG, AVG, HI_, AVG, AVG, LO_},
                                                   {AVG, AVG, HI_, AVG, NOT, HI_, LO_, VHI, AVG, AVG, AVG, LO_, AVG, LO_, AVG, AVG, AVG, AVG},
                                                   {AVG, NOT, HI_, LO_, LO_, HI_, LO_, HI_, LO_, NOT, LO_, LO_, AVG, AVG, AVG, HI_, HI_, AVG},
                                                   {AVG, NOT, HI_, LO_, LO_, HI_, LO_, HI_, LO_, NOT, LO_, LO_, AVG, AVG, AVG, HI_, HI_, AVG},
                                                   {AVG, LO_, HI_, LO_, AVG, HI_, LO_, VHI, LO_, AVG, VLO, AVG, AVG, HI_, NOT, AVG, AVG, AVG}},
                                                 {

                                                   {VLO, HI_, LO_, LO_, HI_, LO_, AVG, VLO, LO_, LO_, AVG, NOT, LO_, LO_, HI_, AVG, AVG, LO_},
                                                   {LO_, AVG, AVG, LO_, HI_, HI_, LO_, LO_, LO_, AVG, HI_, AVG, HI_, LO_, AVG, AVG, LO_, HI_},
                                                   {LO_, AVG, HI_, VLO, AVG, HI_, VLO, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG},
                                                   {LO_, AVG, AVG, LO_, HI_, AVG, LO_, LO_, AVG, AVG, HI_, AVG, AVG, AVG, AVG, AVG, AVG, AVG},
                                                   {VLO, AVG, AVG, LO_, AVG, AVG, LO_, LO_, AVG, AVG, HI_, AVG, AVG, AVG, HI_, AVG, AVG, LO_},
                                                   {AVG, LO_, NOT, LO_, HI_, AVG, LO_, LO_, LO_, AVG, HI_, HI_, AVG, AVG, AVG, AVG, LO_, AVG},
                                                   {VLO, AVG, AVG, AVG, HI_, LO_, VLO, VLO, LO_, AVG, AVG, AVG, AVG, HI_, HI_, AVG, AVG, AVG},
                                                   {AVG, HI_, AVG, LO_, HI_, AVG, AVG, VLO, AVG, AVG, HI_, AVG, AVG, HI_, AVG, AVG, AVG, AVG},
                                                   {LO_, LO_, AVG, LO_, HI_, AVG, AVG, LO_, AVG, AVG, AVG, AVG, AVG, HI_, LO_, AVG, AVG, HI_},
                                                   {LO_, HI_, AVG, LO_, HI_, AVG, LO_, LO_, AVG, AVG, HI_, AVG, AVG, AVG, AVG, NOT, AVG, AVG},
                                                   {LO_, AVG, AVG, VLO, AVG, AVG, AVG, AVG, HI_, AVG, AVG, HI_, AVG, AVG, LO_, AVG, AVG, HI_},
                                                   {LO_, LO_, AVG, LO_, HI_, LO_, LO_, LO_, LO_, AVG, AVG, LO_, HI_, AVG, HI_, AVG, AVG, AVG},
                                                   {LO_, LO_, AVG, LO_, HI_, AVG, LO_, LO_, HI_, AVG, HI_, AVG, LO_, AVG, AVG, HI_, HI_, AVG},
                                                   {AVG, HI_, AVG, AVG, HI_, AVG, VLO, LO_, AVG, LO_, VHI, LO_, AVG, AVG, HI_, AVG, AVG, LO_},
                                                   {LO_, AVG, AVG, AVG, NOT, AVG, LO_, AVG, AVG, AVG, VHI, LO_, AVG, LO_, AVG, AVG, AVG, AVG},
                                                   {LO_, NOT, AVG, LO_, HI_, AVG, LO_, LO_, LO_, NOT, HI_, LO_, AVG, AVG, AVG, HI_, HI_, AVG},
                                                   {LO_, HI_, AVG, LO_, HI_, HI_, LO_, LO_, HI_, AVG, HI_, AVG, NOT, AVG, AVG, LO_, LO_, AVG},
                                                   {LO_, LO_, AVG, LO_, VHI, AVG, LO_, AVG, LO_, AVG, AVG, AVG, AVG, HI_, NOT, AVG, AVG, AVG}},
                                                 {{VLO, HI_, LO_, AVG, LO_, LO_, HI_, LO_, LO_, LO_, LO_, NOT, LO_, LO_, VHI, AVG, AVG, VLO},
                                                  {LO_, AVG, AVG, AVG, LO_, HI_, AVG, AVG, LO_, AVG, AVG, AVG, HI_, LO_, HI_, AVG, LO_, AVG},
                                                  {LO_, AVG, HI_, LO_, VLO, HI_, LO_, HI_, AVG, AVG, LO_, AVG, AVG, AVG, HI_, AVG, AVG, LO_},
                                                  {VLO, AVG, AVG, LO_, AVG, AVG, LO_, LO_, AVG, AVG, HI_, AVG, AVG, AVG, HI_, AVG, AVG, LO_},
                                                  {LO_, AVG, AVG, AVG, LO_, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, LO_},
                                                  {AVG, LO_, NOT, AVG, LO_, AVG, AVG, AVG, LO_, AVG, AVG, HI_, AVG, AVG, HI_, AVG, LO_, LO_},
                                                  {VLO, AVG, AVG, HI_, LO_, LO_, LO_, LO_, LO_, AVG, LO_, AVG, AVG, HI_, VHI, AVG, AVG, LO_},
                                                  {AVG, HI_, AVG, AVG, LO_, AVG, HI_, LO_, AVG, AVG, AVG, AVG, AVG, HI_, HI_, AVG, AVG, LO_},
                                                  {LO_, LO_, AVG, AVG, LO_, AVG, HI_, AVG, AVG, AVG, LO_, AVG, AVG, HI_, AVG, AVG, AVG, AVG},
                                                  {LO_, HI_, AVG, AVG, LO_, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, HI_, NOT, AVG, LO_},
                                                  {LO_, AVG, AVG, LO_, VLO, AVG, HI_, HI_, HI_, AVG, LO_, HI_, AVG, AVG, AVG, AVG, AVG, AVG},
                                                  {LO_, LO_, AVG, AVG, LO_, LO_, AVG, AVG, LO_, AVG, LO_, LO_, HI_, AVG, VHI, AVG, AVG, LO_},
                                                  {LO_, LO_, AVG, AVG, LO_, AVG, AVG, AVG, HI_, AVG, AVG, AVG, LO_, AVG, HI_, HI_, HI_, LO_},
                                                  {AVG, HI_, AVG, HI_, LO_, AVG, LO_, AVG, AVG, LO_, HI_, LO_, AVG, AVG, VHI, AVG, AVG, VLO},
                                                  {LO_, AVG, AVG, HI_, NOT, AVG, AVG, HI_, AVG, AVG, HI_, LO_, AVG, LO_, HI_, AVG, AVG, LO_},
                                                  {LO_, NOT, AVG, AVG, LO_, AVG, AVG, AVG, LO_, NOT, AVG, LO_, AVG, AVG, HI_, HI_, HI_, LO_},
                                                  {LO_, HI_, AVG, AVG, LO_, HI_, AVG, AVG, HI_, AVG, AVG, AVG, NOT, AVG, HI_, LO_, LO_, LO_},
                                                  {LO_, LO_, AVG, AVG, AVG, AVG, AVG, HI_, LO_, AVG, LO_, AVG, AVG, HI_, NOT, AVG, AVG, LO_}},
                                                 {{AVG, AVG, NOT, AVG, AVG, LO_, HI_, LO_, VLO, LO_, LO_, NOT, LO_, LO_, HI_, AVG, LO_, LO_},
                                                  {HI_, LO_, NOT, AVG, AVG, HI_, AVG, AVG, VLO, AVG, AVG, HI_, HI_, LO_, AVG, AVG, VLO, HI_},
                                                  {HI_, LO_, NOT, LO_, LO_, HI_, LO_, HI_, LO_, AVG, LO_, HI_, AVG, AVG, AVG, AVG, LO_, AVG},
                                                  {AVG, LO_, NOT, LO_, HI_, AVG, LO_, LO_, LO_, AVG, HI_, HI_, AVG, AVG, AVG, AVG, LO_, AVG},
                                                  {AVG, LO_, NOT, AVG, LO_, AVG, AVG, AVG, LO_, AVG, AVG, HI_, AVG, AVG, HI_, AVG, LO_, LO_},
                                                  {HI_, LO_, NOT, AVG, AVG, AVG, AVG, AVG, LO_, AVG, AVG, HI_, AVG, AVG, AVG, AVG, LO_, AVG},
                                                  {AVG, LO_, NOT, HI_, AVG, LO_, LO_, LO_, VLO, AVG, LO_, HI_, AVG, HI_, HI_, AVG, LO_, AVG},
                                                  {VHI, AVG, NOT, AVG, AVG, AVG, HI_, LO_, LO_, AVG, AVG, HI_, AVG, HI_, AVG, AVG, LO_, AVG},
                                                  {HI_, VLO, NOT, AVG, AVG, AVG, HI_, AVG, LO_, AVG, LO_, HI_, AVG, HI_, LO_, AVG, LO_, HI_},
                                                  {HI_, AVG, NOT, AVG, AVG, AVG, AVG, AVG, LO_, AVG, AVG, HI_, AVG, AVG, AVG, NOT, LO_, AVG},
                                                  {HI_, LO_, NOT, LO_, LO_, AVG, HI_, HI_, AVG, AVG, LO_, VHI, AVG, AVG, LO_, AVG, LO_, HI_},
                                                  {HI_, VLO, NOT, AVG, AVG, LO_, AVG, AVG, VLO, AVG, LO_, AVG, HI_, AVG, HI_, AVG, LO_, AVG},
                                                  {HI_, VLO, NOT, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, HI_, LO_, AVG, AVG, HI_, AVG, LO_},
                                                  {VHI, AVG, NOT, HI_, AVG, AVG, LO_, AVG, LO_, LO_, HI_, AVG, AVG, AVG, HI_, AVG, LO_, LO_},
                                                  {HI_, AVG, NOT, HI_, NOT, AVG, AVG, HI_, LO_, AVG, HI_, AVG, AVG, LO_, AVG, AVG, LO_, AVG},
                                                  {HI_, NOT, NOT, AVG, AVG, AVG, AVG, AVG, VLO, NOT, AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG},
                                                  {HI_, AVG, NOT, AVG, AVG, HI_, AVG, AVG, AVG, AVG, AVG, HI_, NOT, AVG, AVG, LO_, VLO, AVG},
                                                  {HI_, VLO, NOT, AVG, HI_, AVG, AVG, HI_, VLO, AVG, LO_, HI_, AVG, HI_, NOT, AVG, LO_, AVG}},
                                                 {{VLO, HI_, LO_, HI_, AVG, VLO, AVG, VLO, VLO, LO_, VLO, NOT, LO_, AVG, VHI, AVG, AVG, LO_},
                                                  {LO_, AVG, AVG, HI_, AVG, AVG, LO_, LO_, VLO, AVG, LO_, AVG, HI_, AVG, HI_, AVG, LO_, HI_},
                                                  {LO_, AVG, HI_, AVG, LO_, AVG, VLO, AVG, LO_, AVG, VLO, AVG, AVG, HI_, HI_, AVG, AVG, AVG},
                                                  {VLO, AVG, AVG, AVG, HI_, LO_, VLO, VLO, LO_, AVG, AVG, AVG, AVG, HI_, HI_, AVG, AVG, AVG},
                                                  {VLO, AVG, AVG, HI_, LO_, LO_, LO_, LO_, LO_, AVG, LO_, AVG, AVG, HI_, VHI, AVG, AVG, LO_},
                                                  {AVG, LO_, NOT, HI_, AVG, LO_, LO_, LO_, VLO, AVG, LO_, HI_, AVG, HI_, HI_, AVG, LO_, AVG},
                                                  {LO_, AVG, AVG, HI_, AVG, LO_, LO_, LO_, LO_, AVG, LO_, AVG, AVG, HI_, HI_, AVG, AVG, AVG},
                                                  {AVG, HI_, AVG, HI_, AVG, LO_, AVG, VLO, LO_, AVG, LO_, AVG, AVG, VHI, HI_, AVG, AVG, AVG},
                                                  {LO_, LO_, AVG, HI_, AVG, LO_, AVG, LO_, LO_, AVG, VLO, AVG, AVG, VHI, AVG, AVG, AVG, HI_},
                                                  {LO_, HI_, AVG, HI_, AVG, LO_, LO_, LO_, LO_, AVG, LO_, AVG, AVG, HI_, HI_, NOT, AVG, AVG},
                                                  {LO_, AVG, AVG, AVG, LO_, LO_, AVG, AVG, AVG, AVG, VLO, HI_, AVG, HI_, AVG, AVG, AVG, HI_},
                                                  {LO_, LO_, AVG, HI_, AVG, VLO, LO_, LO_, VLO, AVG, VLO, LO_, HI_, HI_, VHI, AVG, AVG, AVG},
                                                  {LO_, LO_, AVG, HI_, AVG, LO_, LO_, LO_, AVG, AVG, LO_, AVG, LO_, HI_, HI_, HI_, HI_, AVG},
                                                  {AVG, HI_, AVG, VHI, AVG, LO_, VLO, LO_, LO_, LO_, AVG, LO_, AVG, HI_, VHI, AVG, AVG, LO_},
                                                  {LO_, AVG, AVG, VHI, NOT, LO_, LO_, AVG, LO_, AVG, AVG, LO_, AVG, AVG, HI_, AVG, AVG, AVG},
                                                  {LO_, NOT, AVG, HI_, AVG, LO_, LO_, LO_, VLO, NOT, LO_, LO_, AVG, HI_, HI_, HI_, HI_, AVG},
                                                  {LO_, HI_, AVG, HI_, AVG, AVG, LO_, LO_, AVG, AVG, LO_, AVG, NOT, HI_, HI_, LO_, LO_, AVG},
                                                  {LO_, LO_, AVG, HI_, HI_, LO_, LO_, AVG, VLO, AVG, VLO, AVG, AVG, VHI, NOT, AVG, AVG, AVG}},
                                                 {{AVG, VHI, LO_, AVG, AVG, LO_, VHI, VLO, LO_, LO_, LO_, NOT, LO_, AVG, HI_, AVG, AVG, LO_},
                                                  {HI_, HI_, AVG, AVG, AVG, HI_, HI_, LO_, LO_, AVG, AVG, AVG, HI_, AVG, AVG, AVG, LO_, HI_},
                                                  {HI_, HI_, HI_, LO_, LO_, HI_, AVG, AVG, AVG, AVG, LO_, AVG, AVG, HI_, AVG, AVG, AVG, AVG},
                                                  {AVG, HI_, AVG, LO_, HI_, AVG, AVG, VLO, AVG, AVG, HI_, AVG, AVG, HI_, AVG, AVG, AVG, AVG},
                                                  {AVG, HI_, AVG, AVG, LO_, AVG, HI_, LO_, AVG, AVG, AVG, AVG, AVG, HI_, HI_, AVG, AVG, LO_},
                                                  {VHI, AVG, NOT, AVG, AVG, AVG, HI_, LO_, LO_, AVG, AVG, HI_, AVG, HI_, AVG, AVG, LO_, AVG},
                                                  {AVG, HI_, AVG, HI_, AVG, LO_, AVG, VLO, LO_, AVG, LO_, AVG, AVG, VHI, HI_, AVG, AVG, AVG},
                                                  {HI_, HI_, AVG, AVG, AVG, AVG, HI_, LO_, AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, AVG, AVG},
                                                  {HI_, AVG, AVG, AVG, AVG, AVG, VHI, LO_, AVG, AVG, LO_, AVG, AVG, VHI, LO_, AVG, AVG, HI_},
                                                  {HI_, VHI, AVG, AVG, AVG, AVG, HI_, LO_, AVG, AVG, AVG, AVG, AVG, HI_, AVG, NOT, AVG, AVG},
                                                  {HI_, HI_, AVG, LO_, LO_, AVG, VHI, AVG, HI_, AVG, LO_, HI_, AVG, HI_, LO_, AVG, AVG, HI_},
                                                  {HI_, AVG, AVG, AVG, AVG, LO_, HI_, LO_, LO_, AVG, LO_, LO_, HI_, HI_, HI_, AVG, AVG, AVG},
                                                  {HI_, AVG, AVG, AVG, AVG, AVG, HI_, LO_, HI_, AVG, AVG, AVG, LO_, HI_, AVG, HI_, HI_, AVG},
                                                  {VHI, VHI, AVG, HI_, AVG, AVG, AVG, LO_, AVG, LO_, HI_, LO_, AVG, HI_, HI_, AVG, AVG, LO_},
                                                  {HI_, HI_, AVG, HI_, NOT, AVG, HI_, AVG, AVG, AVG, HI_, LO_, AVG, AVG, AVG, AVG, AVG, AVG},
                                                  {HI_, NOT, AVG, AVG, AVG, AVG, HI_, LO_, LO_, NOT, AVG, LO_, AVG, HI_, AVG, HI_, HI_, AVG},
                                                  {HI_, VHI, AVG, AVG, AVG, HI_, HI_, LO_, HI_, AVG, AVG, AVG, NOT, HI_, AVG, LO_, LO_, AVG},
                                                  {HI_, AVG, AVG, AVG, HI_, AVG, HI_, AVG, LO_, AVG, LO_, AVG, AVG, VHI, NOT, AVG, AVG, AVG}},
                                                 {{LO_, AVG, LO_, AVG, AVG, LO_, VHI, LO_, LO_, LO_, VLO, NOT, LO_, AVG, AVG, AVG, AVG, AVG},
                                                  {AVG, LO_, AVG, AVG, AVG, HI_, HI_, AVG, LO_, AVG, LO_, AVG, HI_, AVG, LO_, AVG, LO_, VHI},
                                                  {AVG, LO_, HI_, LO_, LO_, HI_, AVG, HI_, AVG, AVG, VLO, AVG, AVG, HI_, LO_, AVG, AVG, HI_},
                                                  {LO_, LO_, AVG, LO_, HI_, AVG, AVG, LO_, AVG, AVG, AVG, AVG, AVG, HI_, LO_, AVG, AVG, HI_},
                                                  {LO_, LO_, AVG, AVG, LO_, AVG, HI_, AVG, AVG, AVG, LO_, AVG, AVG, HI_, AVG, AVG, AVG, AVG},
                                                  {HI_, VLO, NOT, AVG, AVG, AVG, HI_, AVG, LO_, AVG, LO_, HI_, AVG, HI_, LO_, AVG, LO_, HI_},
                                                  {LO_, LO_, AVG, HI_, AVG, LO_, AVG, LO_, LO_, AVG, VLO, AVG, AVG, VHI, AVG, AVG, AVG, HI_},
                                                  {HI_, AVG, AVG, AVG, AVG, AVG, VHI, LO_, AVG, AVG, LO_, AVG, AVG, VHI, LO_, AVG, AVG, HI_},
                                                  {AVG, LO_, AVG, AVG, AVG, AVG, HI_, AVG, AVG, AVG, LO_, AVG, AVG, HI_, LO_, AVG, AVG, HI_},
                                                  {AVG, AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, AVG, LO_, AVG, AVG, HI_, LO_, NOT, AVG, HI_},
                                                  {AVG, LO_, AVG, LO_, LO_, AVG, VHI, HI_, HI_, AVG, VLO, HI_, AVG, HI_, VLO, AVG, AVG, VHI},
                                                  {AVG, VLO, AVG, AVG, AVG, LO_, HI_, AVG, LO_, AVG, VLO, LO_, HI_, HI_, AVG, AVG, AVG, HI_},
                                                  {AVG, VLO, AVG, AVG, AVG, AVG, HI_, AVG, HI_, AVG, LO_, AVG, LO_, HI_, LO_, HI_, HI_, HI_},
                                                  {HI_, AVG, AVG, HI_, AVG, AVG, AVG, AVG, AVG, LO_, AVG, LO_, AVG, HI_, AVG, AVG, AVG, AVG},
                                                  {AVG, LO_, AVG, HI_, NOT, AVG, HI_, HI_, AVG, AVG, AVG, LO_, AVG, AVG, LO_, AVG, AVG, HI_},
                                                  {AVG, NOT, AVG, AVG, AVG, AVG, HI_, AVG, LO_, NOT, LO_, LO_, AVG, HI_, LO_, HI_, HI_, HI_},
                                                  {AVG, AVG, AVG, AVG, AVG, HI_, HI_, AVG, HI_, AVG, LO_, AVG, NOT, HI_, LO_, LO_, LO_, HI_},
                                                  {AVG, VLO, AVG, AVG, HI_, AVG, HI_, HI_, LO_, AVG, VLO, AVG, AVG, VHI, NOT, AVG, AVG, HI_}},
                                                 {{LO_, VHI, LO_, AVG, AVG, LO_, HI_, LO_, LO_, LO_, LO_, NOT, AVG, LO_, HI_, NOT, LO_, LO_},
                                                  {AVG, HI_, AVG, AVG, AVG, HI_, AVG, AVG, LO_, AVG, AVG, AVG, HI_, LO_, AVG, NOT, LO_, HI_},
                                                  {AVG, HI_, HI_, LO_, LO_, HI_, LO_, HI_, AVG, AVG, LO_, AVG, AVG, AVG, AVG, NOT, AVG, AVG},
                                                  {LO_, HI_, AVG, LO_, HI_, AVG, LO_, LO_, AVG, AVG, HI_, AVG, AVG, AVG, AVG, NOT, AVG, AVG},
                                                  {LO_, HI_, AVG, AVG, LO_, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, HI_, NOT, AVG, LO_},
                                                  {HI_, AVG, NOT, AVG, AVG, AVG, AVG, AVG, LO_, AVG, AVG, HI_, AVG, AVG, AVG, NOT, LO_, AVG},
                                                  {LO_, HI_, AVG, HI_, AVG, LO_, LO_, LO_, LO_, AVG, LO_, AVG, AVG, HI_, HI_, NOT, AVG, AVG},
                                                  {HI_, VHI, AVG, AVG, AVG, AVG, HI_, LO_, AVG, AVG, AVG, AVG, AVG, HI_, AVG, NOT, AVG, AVG},
                                                  {AVG, AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, AVG, LO_, AVG, AVG, HI_, LO_, NOT, AVG, HI_},
                                                  {AVG, HI_, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, NOT, NOT, NOT},
                                                  {AVG, HI_, AVG, LO_, LO_, AVG, HI_, HI_, HI_, AVG, LO_, HI_, AVG, AVG, LO_, NOT, AVG, HI_},
                                                  {AVG, AVG, AVG, AVG, AVG, LO_, AVG, AVG, LO_, AVG, LO_, LO_, HI_, AVG, HI_, NOT, AVG, AVG},
                                                  {AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, AVG, LO_, AVG, AVG, NOT, HI_, AVG},
                                                  {HI_, VHI, AVG, HI_, AVG, AVG, LO_, AVG, AVG, LO_, HI_, LO_, AVG, AVG, HI_, NOT, AVG, LO_},
                                                  {AVG, HI_, AVG, HI_, NOT, AVG, AVG, HI_, AVG, AVG, HI_, LO_, AVG, LO_, AVG, NOT, AVG, AVG},
                                                  {AVG, NOT, AVG, AVG, AVG, AVG, AVG, AVG, LO_, NOT, AVG, LO_, AVG, AVG, AVG, NOT, HI_, AVG},
                                                  {AVG, VHI, AVG, AVG, AVG, HI_, AVG, AVG, HI_, AVG, AVG, AVG, NOT, AVG, AVG, NOT, LO_, AVG},
                                                  {AVG, AVG, AVG, AVG, HI_, AVG, AVG, HI_, LO_, AVG, LO_, AVG, AVG, HI_, NOT, NOT, AVG, AVG}},
                                                 {{LO_, HI_, LO_, LO_, LO_, LO_, VHI, AVG, AVG, LO_, VLO, NOT, LO_, LO_, AVG, AVG, AVG, AVG},
                                                  {AVG, AVG, AVG, LO_, LO_, HI_, HI_, HI_, AVG, AVG, LO_, HI_, HI_, LO_, LO_, AVG, LO_, VHI},
                                                  {AVG, AVG, HI_, VLO, VLO, HI_, AVG, VHI, HI_, AVG, VLO, HI_, AVG, AVG, LO_, AVG, AVG, HI_},
                                                  {LO_, AVG, AVG, VLO, AVG, AVG, AVG, AVG, HI_, AVG, AVG, HI_, AVG, AVG, LO_, AVG, AVG, HI_},
                                                  {LO_, AVG, AVG, LO_, VLO, AVG, HI_, HI_, HI_, AVG, LO_, HI_, AVG, AVG, AVG, AVG, AVG, AVG},
                                                  {HI_, LO_, NOT, LO_, LO_, AVG, HI_, HI_, AVG, AVG, LO_, VHI, AVG, AVG, LO_, AVG, LO_, HI_},
                                                  {LO_, AVG, AVG, AVG, LO_, LO_, AVG, AVG, AVG, AVG, VLO, HI_, AVG, HI_, AVG, AVG, AVG, HI_},
                                                  {HI_, HI_, AVG, LO_, LO_, AVG, VHI, AVG, HI_, AVG, LO_, HI_, AVG, HI_, LO_, AVG, AVG, HI_},
                                                  {AVG, LO_, AVG, LO_, LO_, AVG, VHI, HI_, HI_, AVG, VLO, HI_, AVG, HI_, VLO, AVG, AVG, VHI},
                                                  {AVG, HI_, AVG, LO_, LO_, AVG, HI_, HI_, HI_, AVG, LO_, HI_, AVG, AVG, LO_, NOT, AVG, HI_},
                                                  {AVG, AVG, AVG, LO_, LO_, AVG, HI_, HI_, HI_, AVG, LO_, HI_, AVG, AVG, LO_, AVG, AVG, HI_},
                                                  {AVG, LO_, AVG, LO_, LO_, LO_, HI_, HI_, AVG, AVG, VLO, AVG, HI_, AVG, AVG, AVG, AVG, HI_},
                                                  {AVG, LO_, AVG, LO_, LO_, AVG, HI_, HI_, VHI, AVG, LO_, HI_, LO_, AVG, LO_, HI_, HI_, HI_},
                                                  {HI_, HI_, AVG, AVG, LO_, AVG, AVG, HI_, HI_, LO_, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG},
                                                  {AVG, AVG, AVG, AVG, NOT, AVG, HI_, VHI, HI_, AVG, AVG, AVG, AVG, LO_, LO_, AVG, AVG, HI_},
                                                  {AVG, NOT, AVG, LO_, LO_, AVG, HI_, HI_, AVG, NOT, LO_, AVG, AVG, AVG, LO_, HI_, HI_, HI_},
                                                  {AVG, HI_, AVG, LO_, LO_, HI_, HI_, HI_, VHI, AVG, LO_, HI_, NOT, AVG, LO_, LO_, LO_, HI_},
                                                  {AVG, LO_, AVG, LO_, AVG, AVG, HI_, VHI, AVG, AVG, VLO, HI_, AVG, HI_, NOT, AVG, AVG, HI_}},
                                                 {{LO_, AVG, LO_, AVG, AVG, VLO, HI_, LO_, VLO, LO_, VLO, NOT, AVG, LO_, VHI, AVG, AVG, LO_},
                                                  {AVG, LO_, AVG, AVG, AVG, AVG, AVG, AVG, VLO, AVG, LO_, LO_, VHI, LO_, HI_, AVG, LO_, HI_},
                                                  {AVG, LO_, HI_, LO_, LO_, AVG, LO_, HI_, LO_, AVG, VLO, LO_, HI_, AVG, HI_, AVG, AVG, AVG},
                                                  {LO_, LO_, AVG, LO_, HI_, LO_, LO_, LO_, LO_, AVG, AVG, LO_, HI_, AVG, HI_, AVG, AVG, AVG},
                                                  {LO_, LO_, AVG, AVG, LO_, LO_, AVG, AVG, LO_, AVG, LO_, LO_, HI_, AVG, VHI, AVG, AVG, LO_},
                                                  {HI_, VLO, NOT, AVG, AVG, LO_, AVG, AVG, VLO, AVG, LO_, AVG, HI_, AVG, HI_, AVG, LO_, AVG},
                                                  {LO_, LO_, AVG, HI_, AVG, VLO, LO_, LO_, VLO, AVG, VLO, LO_, HI_, HI_, VHI, AVG, AVG, AVG},
                                                  {HI_, AVG, AVG, AVG, AVG, LO_, HI_, LO_, LO_, AVG, LO_, LO_, HI_, HI_, HI_, AVG, AVG, AVG},
                                                  {AVG, VLO, AVG, AVG, AVG, LO_, HI_, AVG, LO_, AVG, VLO, LO_, HI_, HI_, AVG, AVG, AVG, HI_},
                                                  {AVG, AVG, AVG, AVG, AVG, LO_, AVG, AVG, LO_, AVG, LO_, LO_, HI_, AVG, HI_, NOT, AVG, AVG},
                                                  {AVG, LO_, AVG, LO_, LO_, LO_, HI_, HI_, AVG, AVG, VLO, AVG, HI_, AVG, AVG, AVG, AVG, HI_},
                                                  {AVG, LO_, AVG, AVG, AVG, LO_, AVG, AVG, LO_, AVG, LO_, LO_, HI_, AVG, HI_, AVG, AVG, AVG},
                                                  {AVG, VLO, AVG, AVG, AVG, LO_, AVG, AVG, AVG, AVG, LO_, LO_, AVG, AVG, HI_, HI_, HI_, AVG},
                                                  {HI_, AVG, AVG, HI_, AVG, LO_, LO_, AVG, LO_, LO_, AVG, VLO, HI_, AVG, VHI, AVG, AVG, LO_},
                                                  {AVG, LO_, AVG, HI_, NOT, LO_, AVG, HI_, LO_, AVG, AVG, VLO, HI_, LO_, HI_, AVG, AVG, AVG},
                                                  {AVG, NOT, AVG, AVG, AVG, LO_, AVG, AVG, VLO, NOT, LO_, VLO, HI_, AVG, HI_, HI_, HI_, AVG},
                                                  {AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, LO_, LO_, NOT, AVG, HI_, LO_, LO_, AVG},
                                                  {AVG, VLO, AVG, AVG, HI_, LO_, AVG, HI_, VLO, AVG, VLO, LO_, HI_, HI_, NOT, AVG, AVG, AVG}},
                                                 {{LO_, AVG, LO_, AVG, AVG, LO_, HI_, LO_, AVG, LO_, LO_, NOT, VLO, LO_, HI_, HI_, HI_, LO_},
                                                  {AVG, LO_, AVG, AVG, AVG, HI_, AVG, AVG, AVG, AVG, AVG, AVG, AVG, LO_, AVG, HI_, AVG, HI_},
                                                  {AVG, LO_, HI_, LO_, LO_, HI_, LO_, HI_, HI_, AVG, LO_, AVG, LO_, AVG, AVG, HI_, HI_, AVG},
                                                  {LO_, LO_, AVG, LO_, HI_, AVG, LO_, LO_, HI_, AVG, HI_, AVG, LO_, AVG, AVG, HI_, HI_, AVG},
                                                  {LO_, LO_, AVG, AVG, LO_, AVG, AVG, AVG, HI_, AVG, AVG, AVG, LO_, AVG, HI_, HI_, HI_, LO_},
                                                  {HI_, VLO, NOT, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, HI_, LO_, AVG, AVG, HI_, AVG, LO_},
                                                  {LO_, LO_, AVG, HI_, AVG, LO_, LO_, LO_, AVG, AVG, LO_, AVG, LO_, HI_, HI_, HI_, HI_, AVG},
                                                  {HI_, AVG, AVG, AVG, AVG, AVG, HI_, LO_, HI_, AVG, AVG, AVG, LO_, HI_, AVG, HI_, HI_, AVG},
                                                  {AVG, VLO, AVG, AVG, AVG, AVG, HI_, AVG, HI_, AVG, LO_, AVG, LO_, HI_, LO_, HI_, HI_, HI_},
                                                  {AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, AVG, LO_, AVG, AVG, NOT, HI_, AVG},
                                                  {AVG, LO_, AVG, LO_, LO_, AVG, HI_, HI_, VHI, AVG, LO_, HI_, LO_, AVG, LO_, HI_, HI_, HI_},
                                                  {AVG, VLO, AVG, AVG, AVG, LO_, AVG, AVG, AVG, AVG, LO_, LO_, AVG, AVG, HI_, HI_, HI_, AVG},
                                                  {AVG, LO_, AVG, AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, AVG, LO_, AVG, AVG, HI_, HI_, AVG},
                                                  {HI_, AVG, AVG, HI_, AVG, AVG, LO_, AVG, HI_, LO_, HI_, LO_, LO_, AVG, HI_, HI_, HI_, LO_},
                                                  {AVG, LO_, AVG, HI_, NOT, AVG, AVG, HI_, HI_, AVG, HI_, LO_, LO_, LO_, AVG, HI_, HI_, AVG},
                                                  {AVG, NOT, AVG, AVG, AVG, AVG, AVG, AVG, AVG, NOT, AVG, LO_, LO_, AVG, AVG, VHI, VHI, AVG},
                                                  {AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, VHI, AVG, AVG, AVG, NOT, AVG, AVG, NOT, NOT, NOT},
                                                  {AVG, VLO, AVG, AVG, HI_, AVG, AVG, HI_, AVG, AVG, LO_, AVG, LO_, HI_, NOT, HI_, HI_, AVG}},
                                                 {{AVG, VHI, LO_, HI_, AVG, LO_, AVG, LO_, LO_, VLO, AVG, NOT, LO_, LO_, VHI, AVG, AVG, VLO},
                                                  {HI_, HI_, AVG, HI_, AVG, HI_, LO_, AVG, LO_, LO_, HI_, LO_, HI_, LO_, HI_, AVG, LO_, AVG},
                                                  {HI_, HI_, HI_, AVG, LO_, HI_, VLO, HI_, AVG, LO_, AVG, LO_, AVG, AVG, HI_, AVG, AVG, LO_},
                                                  {AVG, HI_, AVG, AVG, HI_, AVG, VLO, LO_, AVG, LO_, VHI, LO_, AVG, AVG, HI_, AVG, AVG, LO_},
                                                  {AVG, HI_, AVG, HI_, LO_, AVG, LO_, AVG, AVG, LO_, HI_, LO_, AVG, AVG, VHI, AVG, AVG, VLO},
                                                  {VHI, AVG, NOT, HI_, AVG, AVG, LO_, AVG, LO_, LO_, HI_, AVG, AVG, AVG, HI_, AVG, LO_, LO_},
                                                  {AVG, HI_, AVG, VHI, AVG, LO_, VLO, LO_, LO_, LO_, AVG, LO_, AVG, HI_, VHI, AVG, AVG, LO_},
                                                  {VHI, VHI, AVG, HI_, AVG, AVG, AVG, LO_, AVG, LO_, HI_, LO_, AVG, HI_, HI_, AVG, AVG, LO_},
                                                  {HI_, AVG, AVG, HI_, AVG, AVG, AVG, AVG, AVG, LO_, AVG, LO_, AVG, HI_, AVG, AVG, AVG, AVG},
                                                  {HI_, VHI, AVG, HI_, AVG, AVG, LO_, AVG, AVG, LO_, HI_, LO_, AVG, AVG, HI_, NOT, AVG, LO_},
                                                  {HI_, HI_, AVG, AVG, LO_, AVG, AVG, HI_, HI_, LO_, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG},
                                                  {HI_, AVG, AVG, HI_, AVG, LO_, LO_, AVG, LO_, LO_, AVG, VLO, HI_, AVG, VHI, AVG, AVG, LO_},
                                                  {HI_, AVG, AVG, HI_, AVG, AVG, LO_, AVG, HI_, LO_, HI_, LO_, LO_, AVG, HI_, HI_, HI_, LO_},
                                                  {HI_, HI_, AVG, HI_, AVG, AVG, LO_, AVG, AVG, LO_, HI_, LO_, AVG, AVG, HI_, AVG, AVG, LO_},
                                                  {HI_, HI_, AVG, VHI, NOT, AVG, LO_, HI_, AVG, LO_, VHI, VLO, AVG, LO_, HI_, AVG, AVG, LO_},
                                                  {HI_, NOT, AVG, HI_, AVG, AVG, LO_, AVG, LO_, NOT, HI_, VLO, AVG, AVG, HI_, HI_, HI_, LO_},
                                                  {HI_, VHI, AVG, HI_, AVG, HI_, LO_, AVG, HI_, LO_, HI_, LO_, NOT, AVG, HI_, LO_, LO_, LO_},
                                                  {HI_, AVG, AVG, HI_, HI_, AVG, LO_, HI_, LO_, LO_, AVG, LO_, AVG, HI_, NOT, AVG, AVG, LO_}},
                                                 {{LO_, HI_, LO_, HI_, NOT, LO_, HI_, AVG, LO_, LO_, AVG, NOT, LO_, VLO, HI_, AVG, AVG, LO_},
                                                  {AVG, AVG, AVG, HI_, NOT, HI_, AVG, HI_, LO_, AVG, HI_, LO_, HI_, VLO, AVG, AVG, LO_, HI_},
                                                  {AVG, AVG, HI_, AVG, NOT, HI_, LO_, VHI, AVG, AVG, AVG, LO_, AVG, LO_, AVG, AVG, AVG, AVG},
                                                  {LO_, AVG, AVG, AVG, NOT, AVG, LO_, AVG, AVG, AVG, VHI, LO_, AVG, LO_, AVG, AVG, AVG, AVG},
                                                  {LO_, AVG, AVG, HI_, NOT, AVG, AVG, HI_, AVG, AVG, HI_, LO_, AVG, LO_, HI_, AVG, AVG, LO_},
                                                  {HI_, AVG, NOT, HI_, NOT, AVG, AVG, HI_, LO_, AVG, HI_, AVG, AVG, LO_, AVG, AVG, LO_, AVG},
                                                  {LO_, AVG, AVG, VHI, NOT, LO_, LO_, AVG, LO_, AVG, AVG, LO_, AVG, AVG, HI_, AVG, AVG, AVG},
                                                  {HI_, HI_, AVG, HI_, NOT, AVG, HI_, AVG, AVG, AVG, HI_, LO_, AVG, AVG, AVG, AVG, AVG, AVG},
                                                  {AVG, LO_, AVG, HI_, NOT, AVG, HI_, HI_, AVG, AVG, AVG, LO_, AVG, AVG, LO_, AVG, AVG, HI_},
                                                  {AVG, HI_, AVG, HI_, NOT, AVG, AVG, HI_, AVG, AVG, HI_, LO_, AVG, LO_, AVG, NOT, AVG, AVG},
                                                  {AVG, AVG, AVG, AVG, NOT, AVG, HI_, VHI, HI_, AVG, AVG, AVG, AVG, LO_, LO_, AVG, AVG, HI_},
                                                  {AVG, LO_, AVG, HI_, NOT, LO_, AVG, HI_, LO_, AVG, AVG, VLO, HI_, LO_, HI_, AVG, AVG, AVG},
                                                  {AVG, LO_, AVG, HI_, NOT, AVG, AVG, HI_, HI_, AVG, HI_, LO_, LO_, LO_, AVG, HI_, HI_, AVG},
                                                  {HI_, HI_, AVG, VHI, NOT, AVG, LO_, HI_, AVG, LO_, VHI, VLO, AVG, LO_, HI_, AVG, AVG, LO_},
                                                  {AVG, AVG, AVG, HI_, NOT, AVG, AVG, HI_, AVG, AVG, HI_, LO_, AVG, LO_, AVG, AVG, AVG, AVG},
                                                  {AVG, NOT, AVG, HI_, NOT, AVG, AVG, HI_, LO_, NOT, HI_, VLO, AVG, LO_, AVG, HI_, HI_, AVG},
                                                  {AVG, HI_, AVG, HI_, NOT, HI_, AVG, HI_, HI_, AVG, HI_, LO_, NOT, LO_, AVG, LO_, LO_, AVG},
                                                  {AVG, LO_, AVG, HI_, NOT, AVG, AVG, VHI, LO_, AVG, AVG, LO_, AVG, AVG, NOT, AVG, AVG, AVG}},
                                                 {{LO_, NOT, LO_, AVG, AVG, LO_, HI_, LO_, VLO, NOT, LO_, NOT, LO_, LO_, HI_, HI_, HI_, LO_},
                                                  {AVG, NOT, AVG, AVG, AVG, HI_, AVG, AVG, VLO, NOT, AVG, LO_, HI_, LO_, AVG, HI_, AVG, HI_},
                                                  {AVG, NOT, HI_, LO_, LO_, HI_, LO_, HI_, LO_, NOT, LO_, LO_, AVG, AVG, AVG, HI_, HI_, AVG},
                                                  {LO_, NOT, AVG, LO_, HI_, AVG, LO_, LO_, LO_, NOT, HI_, LO_, AVG, AVG, AVG, HI_, HI_, AVG},
                                                  {LO_, NOT, AVG, AVG, LO_, AVG, AVG, AVG, LO_, NOT, AVG, LO_, AVG, AVG, HI_, HI_, HI_, LO_},
                                                  {HI_, NOT, NOT, AVG, AVG, AVG, AVG, AVG, VLO, NOT, AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG},
                                                  {LO_, NOT, AVG, HI_, AVG, LO_, LO_, LO_, VLO, NOT, LO_, LO_, AVG, HI_, HI_, HI_, HI_, AVG},
                                                  {HI_, NOT, AVG, AVG, AVG, AVG, HI_, LO_, LO_, NOT, AVG, LO_, AVG, HI_, AVG, HI_, HI_, AVG},
                                                  {AVG, NOT, AVG, AVG, AVG, AVG, HI_, AVG, LO_, NOT, LO_, LO_, AVG, HI_, LO_, HI_, HI_, HI_},
                                                  {AVG, NOT, AVG, AVG, AVG, AVG, AVG, AVG, LO_, NOT, AVG, LO_, AVG, AVG, AVG, NOT, HI_, AVG},
                                                  {AVG, NOT, AVG, LO_, LO_, AVG, HI_, HI_, AVG, NOT, LO_, AVG, AVG, AVG, LO_, HI_, HI_, HI_},
                                                  {AVG, NOT, AVG, AVG, AVG, LO_, AVG, AVG, VLO, NOT, LO_, VLO, HI_, AVG, HI_, HI_, HI_, AVG},
                                                  {AVG, NOT, AVG, AVG, AVG, AVG, AVG, AVG, AVG, NOT, AVG, LO_, LO_, AVG, AVG, VHI, VHI, AVG},
                                                  {HI_, NOT, AVG, HI_, AVG, AVG, LO_, AVG, LO_, NOT, HI_, VLO, AVG, AVG, HI_, HI_, HI_, LO_},
                                                  {AVG, NOT, AVG, HI_, NOT, AVG, AVG, HI_, LO_, NOT, HI_, VLO, AVG, LO_, AVG, HI_, HI_, AVG},
                                                  {AVG, NOT, AVG, AVG, AVG, AVG, AVG, AVG, LO_, NOT, AVG, LO_, AVG, AVG, AVG, HI_, HI_, AVG},
                                                  {AVG, NOT, AVG, AVG, AVG, HI_, AVG, AVG, AVG, NOT, AVG, LO_, NOT, AVG, AVG, AVG, AVG, AVG},
                                                  {AVG, NOT, AVG, AVG, HI_, AVG, AVG, HI_, VLO, NOT, LO_, LO_, AVG, HI_, NOT, HI_, HI_, AVG}},
                                                 {{LO_, VHI, LO_, AVG, AVG, AVG, HI_, LO_, AVG, LO_, LO_, NOT, NOT, LO_, HI_, LO_, LO_, LO_},
                                                  {AVG, HI_, AVG, AVG, AVG, VHI, AVG, AVG, AVG, AVG, AVG, AVG, NOT, LO_, AVG, LO_, VLO, HI_},
                                                  {AVG, HI_, HI_, LO_, LO_, VHI, LO_, HI_, HI_, AVG, LO_, AVG, NOT, AVG, AVG, LO_, LO_, AVG},
                                                  {LO_, HI_, AVG, LO_, HI_, HI_, LO_, LO_, HI_, AVG, HI_, AVG, NOT, AVG, AVG, LO_, LO_, AVG},
                                                  {LO_, HI_, AVG, AVG, LO_, HI_, AVG, AVG, HI_, AVG, AVG, AVG, NOT, AVG, HI_, LO_, LO_, LO_},
                                                  {HI_, AVG, NOT, AVG, AVG, HI_, AVG, AVG, AVG, AVG, AVG, HI_, NOT, AVG, AVG, LO_, VLO, AVG},
                                                  {LO_, HI_, AVG, HI_, AVG, AVG, LO_, LO_, AVG, AVG, LO_, AVG, NOT, HI_, HI_, LO_, LO_, AVG},
                                                  {HI_, VHI, AVG, AVG, AVG, HI_, HI_, LO_, HI_, AVG, AVG, AVG, NOT, HI_, AVG, LO_, LO_, AVG},
                                                  {AVG, AVG, AVG, AVG, AVG, HI_, HI_, AVG, HI_, AVG, LO_, AVG, NOT, HI_, LO_, LO_, LO_, HI_},
                                                  {AVG, VHI, AVG, AVG, AVG, HI_, AVG, AVG, HI_, AVG, AVG, AVG, NOT, AVG, AVG, NOT, LO_, AVG},
                                                  {AVG, HI_, AVG, LO_, LO_, HI_, HI_, HI_, VHI, AVG, LO_, HI_, NOT, AVG, LO_, LO_, LO_, HI_},
                                                  {AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, LO_, LO_, NOT, AVG, HI_, LO_, LO_, AVG},
                                                  {AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, VHI, AVG, AVG, AVG, NOT, AVG, AVG, NOT, NOT, NOT},
                                                  {HI_, VHI, AVG, HI_, AVG, HI_, LO_, AVG, HI_, LO_, HI_, LO_, NOT, AVG, HI_, LO_, LO_, LO_},
                                                  {AVG, HI_, AVG, HI_, NOT, HI_, AVG, HI_, HI_, AVG, HI_, LO_, NOT, LO_, AVG, LO_, LO_, AVG},
                                                  {AVG, NOT, AVG, AVG, AVG, HI_, AVG, AVG, AVG, NOT, AVG, LO_, NOT, AVG, AVG, AVG, AVG, AVG},
                                                  {AVG, HI_, AVG, AVG, AVG, HI_, AVG, AVG, HI_, AVG, AVG, AVG, NOT, AVG, AVG, LO_, LO_, AVG},
                                                  {AVG, AVG, AVG, AVG, HI_, HI_, AVG, HI_, AVG, AVG, LO_, AVG, NOT, HI_, NOT, LO_, LO_, AVG}},
                                                 {{LO_, AVG, LO_, AVG, HI_, LO_, HI_, AVG, VLO, LO_, VLO, NOT, LO_, AVG, NOT, AVG, AVG, LO_},
                                                  {AVG, LO_, AVG, AVG, HI_, HI_, AVG, HI_, VLO, AVG, LO_, AVG, HI_, AVG, NOT, AVG, LO_, HI_},
                                                  {AVG, LO_, HI_, LO_, AVG, HI_, LO_, VHI, LO_, AVG, VLO, AVG, AVG, HI_, NOT, AVG, AVG, AVG},
                                                  {LO_, LO_, AVG, LO_, VHI, AVG, LO_, AVG, LO_, AVG, AVG, AVG, AVG, HI_, NOT, AVG, AVG, AVG},
                                                  {LO_, LO_, AVG, AVG, AVG, AVG, AVG, HI_, LO_, AVG, LO_, AVG, AVG, HI_, NOT, AVG, AVG, LO_},
                                                  {HI_, VLO, NOT, AVG, HI_, AVG, AVG, HI_, VLO, AVG, LO_, HI_, AVG, HI_, NOT, AVG, LO_, AVG},
                                                  {LO_, LO_, AVG, HI_, HI_, LO_, LO_, AVG, VLO, AVG, VLO, AVG, AVG, VHI, NOT, AVG, AVG, AVG},
                                                  {HI_, AVG, AVG, AVG, HI_, AVG, HI_, AVG, LO_, AVG, LO_, AVG, AVG, VHI, NOT, AVG, AVG, AVG},
                                                  {AVG, VLO, AVG, AVG, HI_, AVG, HI_, HI_, LO_, AVG, VLO, AVG, AVG, VHI, NOT, AVG, AVG, HI_},
                                                  {AVG, AVG, AVG, AVG, HI_, AVG, AVG, HI_, LO_, AVG, LO_, AVG, AVG, HI_, NOT, NOT, AVG, AVG},
                                                  {AVG, LO_, AVG, LO_, AVG, AVG, HI_, VHI, AVG, AVG, VLO, HI_, AVG, HI_, NOT, AVG, AVG, HI_},
                                                  {AVG, VLO, AVG, AVG, HI_, LO_, AVG, HI_, VLO, AVG, VLO, LO_, HI_, HI_, NOT, AVG, AVG, AVG},
                                                  {AVG, VLO, AVG, AVG, HI_, AVG, AVG, HI_, AVG, AVG, LO_, AVG, LO_, HI_, NOT, HI_, HI_, AVG},
                                                  {HI_, AVG, AVG, HI_, HI_, AVG, LO_, HI_, LO_, LO_, AVG, LO_, AVG, HI_, NOT, AVG, AVG, LO_},
                                                  {AVG, LO_, AVG, HI_, NOT, AVG, AVG, VHI, LO_, AVG, AVG, LO_, AVG, AVG, NOT, AVG, AVG, AVG},
                                                  {AVG, NOT, AVG, AVG, HI_, AVG, AVG, HI_, VLO, NOT, LO_, LO_, AVG, HI_, NOT, HI_, HI_, AVG},
                                                  {AVG, AVG, AVG, AVG, HI_, HI_, AVG, HI_, AVG, AVG, LO_, AVG, NOT, HI_, NOT, LO_, LO_, AVG},
                                                  {AVG, LO_, AVG, AVG, HI_, AVG, AVG, HI_, LO_, AVG, LO_, AVG, AVG, HI_, NOT, AVG, AVG, AVG}}};

            float calcEfficacite(Type atk, Type def1, Type def2) {
                int atkI((int)atk), type1I((int)def1), type2I((int)def2);
                if(def2 == Type::NOTHING) {
                    return arrOneType[type1I][atkI];
                } else {
                    return arrTwoTypes[type1I][type2I][atkI];
                }
            }
        } // namespace ArrayTypes

        bool operator==(Side side, int integer) {
            if(((int)side) == integer) {
                return true;
            } else {
                return false;
            }
        }

        bool operator!=(Side side, int integer) {
            return !(side == integer);
        }

        bool operator>=(Side side, int integer) {
            int sideInt = (int)side;
            return sideInt >= integer;
        }

        bool operator>(Side side, int integer) {
            int sideInt = (int)side;
            return sideInt > integer;
        }

        bool operator<(Side side, int integer) {
            int sideInt = (int)side;
            return sideInt < integer;
        }

        bool operator<=(Side side, int integer) {
            int sideInt = (int)side;
            return sideInt <= integer;
        }

        int operator+(Side side, int integer) {
            return ((int)side) + integer;
        }

        Side getSide(int id) {
            switch(id) {
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

        int operator-(Side side, int integer) {
            return ((int)side) - integer;
        }

    } // namespace Model
} // namespace OpMon
