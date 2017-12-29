#ifndef POSITION_HPP
#define POSITION_HPP

namespace OpMon{
  namespace Model{
    class Position{
    public:
      Position();
      Position(std::string mapId, sf::Vector2i position, Side dir = Side::TO_UP);

      sf::Vector2i getPosition(){
	return sf::Vector2i(posX, posY);
      }

      sf::Vector2i getPositionPixel(){
	return sf::Vector2i(posX SQUARES, posY SQUARES);
      }

      Side getDir(){
	return dir;
      }

      bool isAnim(){
	return anim;
      }

      bool isMoving(){
	return movement;
      }

      void stopMove(){
	anim = false;
	movement = false;
      }

      void stopAnim(){
	anim = false;
      }

      void tp(sf::Vector2i position);

      void move(Side dir);
      
    private:

      bool checkPass(Side dir);
      
      int posX;
      int posY;
      Side dir;
      bool anim;
      bool movement;
      bool moveLock;
    }
  }
}

#endif
