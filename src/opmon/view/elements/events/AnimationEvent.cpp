#include "AnimationEvent.hpp"

#include "src/utils/exceptions.hpp"
#include "src/utils/log.hpp"

namespace OpMon {
    namespace Elements {

        AnimationEvent::AnimationEvent(sf::Texture &texture,
                                       std::vector<sf::IntRect> rectangles,
                                       EventTrigger eventTrigger,
                                       sf::Vector2f const &position,
                                       unsigned int framerate, bool loop,
                                       bool passable, bool lastTexture,
                                       int sides)
            : AbstractEvent(texture, rectangles, eventTrigger, position, sides,
                            passable),
              framerate(framerate),
              loop(loop),
              lastTexture(lastTexture) {}

        AnimationEvent::AnimationEvent(OverworldData &data,
                                       nlohmann::json jsonData,
                                       std::vector<sf::IntRect> rectangles)
            : AbstractEvent(data, jsonData),
              framerate(jsonData.value("framerate", 0)),
              loop(jsonData.value("loop", false)),
              lastTexture(jsonData.value("lastTexture", true)) {
            if(rectangles.size() == 0) {
                for(nlohmann::json rect :
                    jsonData.value("rectangles", nlohmann::json())) {
                    this->rectangles.push_back(
                        sf::IntRect(rect[0], rect[1], rect[2], rect[3]));
                }
                if(this->rectangles.size() == 0) {
                    Utils::Log::warn("Empty rectangle in AnimationEvent.");
                    rectangles.push_back(sf::IntRect());
                }
            } else
                this->rectangles = rectangles;
        }

        void AnimationEvent::action(Overworld &overworld) {
            playing = !(playing && loop); // Stops playing only if it's a loop.
                                          // Else, stay playing or start playing.
            resetFrame();
        }

        void AnimationEvent::update(Overworld &overworld) {
            if(playing && (framecount >= framerate)) {
                ++currentFrame;
                framecount = 0;
                if(currentFrame == rectangles.end()) {
                    currentFrame = rectangles.begin();
                    playing = loop; // If loop, continue playing, else, stop.
                    if(!playing && lastTexture)
                        currentFrame = rectangles.end() - 1;
                }
            } else if(playing && (framecount < framerate)) {
                framecount++;
            }
        }

    } /* namespace Elements */
} /* namespace OpMon */
