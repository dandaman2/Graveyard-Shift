// Engine includes
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "vs-2019/hero.h"
#include "vs-2019/gameStart.h"
#include "Object.h"
#include "vs-2019/Tombstone.h"
#include "Pause.h"
#include <stdio.h>


void populateWorld(void) {
	// Spawn GameStart object.
	new GameStart();
}

void loadResources(void) {
	// Load saucer sprite.
	RM.loadSprite("sprites/zombie-r-spr.txt", "zombie-r");
	RM.loadSprite("sprites/zombie-l-spr.txt", "zombie-l");
	RM.loadSprite("sprites/zombie-boss-r-spr.txt", "zombie-boss-r");
	RM.loadSprite("sprites/zombie-boss-l-spr.txt", "zombie-boss-l");
	RM.loadSprite("sprites/hero-r-spr.txt", "hero-r");
	RM.loadSprite("sprites/hero-l-spr.txt", "hero-l");
	RM.loadSprite("sprites/bullet-spr.txt", "bullet");
	RM.loadSprite("sprites/glob-spr.txt", "glob");
	RM.loadSprite("sprites/car-spr.txt", "car");
	RM.loadSprite("sprites/blob-spr.txt", "blob");
	RM.loadSprite("sprites/blob-def-spr.txt", "blob-def");
	RM.loadSprite("sprites/generator-spr.txt", "generator");
	RM.loadSprite("sprites/explosion-spr.txt", "explosion");
	RM.loadSprite("sprites/gameover-spr.txt", "GameOver");
	RM.loadSprite("sprites/gamewin-spr.txt", "GameWin");
	RM.loadSprite("sprites/gamestart-spr.txt", "GameStart");
	RM.loadSprite("sprites/tombstone-spr.txt", "tombstone");
	RM.loadSprite("sprites/plant-spr.txt", "plant");
	RM.loadSprite("sprites/gas-spr.txt", "gas"); 
	RM.loadSprite("sprites/frenzy-plant-spr.txt", "frenzy");
	RM.loadSprite("sprites/plant-rech-spr.txt", "plant-recharge");
	RM.loadSprite("sprites/revolver-spr.txt", "revolver");
	RM.loadSprite("sprites/speeditem-spr.txt", "speeditem");
	RM.loadSprite("sprites/healthitem-spr.txt", "healthitem");
	RM.loadSprite("sprites/gate-spr.txt", "gate");
	RM.loadSprite("sprites/tombstone-large-spr.txt", "tombstone-large");
	RM.loadSound("sounds/fire.wav", "fire");
	RM.loadSound("sounds/explode.wav", "explode");
	RM.loadSound("sounds/scream.wav", "scream");
	RM.loadSound("sounds/sos.wav", "sos");
	RM.loadSound("sounds/game-over.wav", "game over");
	RM.loadMusic("sounds/start-music.wav", "start music");
	RM.loadMusic("sounds/bgmusic.wav", "level music"); //music for the level
}

int main(int argc, char* argv[]) {

	// Start up Game Manager.
	if (GM.startUp()) {
		LM.writeLog("Error starting game manager!");
		GM.shutDown();
		return 0;
	}

	// Set flush of logfile during development (when done, make false).
	LM.setFlush(true);

	// Show splash screen.
	df::splash();

	// 
	loadResources();
	populateWorld();
	// Enable player to pause game.
	new df::Pause(df::Keyboard::F10);

	printf("STARTING-------------------------------");
	GM.run();

	// Shut everything down.
	GM.shutDown();
}