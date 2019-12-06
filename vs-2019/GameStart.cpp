#include "gameStart.h"
#include "Zombie.h"
#include "hero.h"
#include "points.h"
#include "Color.h"
#include "EventKeyboard.h"
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "DataManager.h"

GameStart::GameStart() {
	// Put in center of window.
	setLocation(df::CENTER_CENTER);
	setSprite("GameStart");
	setType("GameStart");
	registerInterest(df::KEYBOARD_EVENT);

	// Play start music.
	p_music = RM.getMusic("start music");
	playMusic();
}

int GameStart::eventHandler(const df::Event* p_e) {

	if (p_e->getType() == df::KEYBOARD_EVENT) {
		df::EventKeyboard* p_keyboard_event = (df::EventKeyboard*) p_e;
		switch (p_keyboard_event->getKey()) {
		case df::Keyboard::P: 			// play
			start();
			break;
		case df::Keyboard::Q:			// quit
			GM.setGameOver();
			break;
		default: // Key is not handled.
			break;
		}
		return 1;
	}

	// If get here, have ignored this event.
	return 0;
}

void GameStart::start() {

	DATA.setHero(new Hero());

	
	new Zombie();

	// Setup heads-up display.
	new Points;	// points display

	df::ViewObject* p_vo = new df::ViewObject; // Count of nukes.
	p_vo->setLocation(df::TOP_LEFT);
	p_vo->setViewString("Nukes");
	p_vo->setValue(1);
	p_vo->setColor(df::YELLOW);

	// When game starts, become inactive.
	setActive(false);
	// Pause start music.
	p_music->pause();
}

// Override default draw so as not to display "value".
int GameStart::draw() {
	return df::Object::draw();
}

void GameStart::playMusic() {
	p_music->play();
}