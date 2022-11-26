#include "player.h"
#include "dominik.h"
#include "human_player.h"

class PlayerFactory {

public:
    PlayerFactory() {  }
    player *getPlayer(const std::string &type) {
        if (type=="dominik") return new dominik<playfield>();
        else if (type=="human") return new human_player<playfield>();
    }
};