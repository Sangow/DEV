#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../state/State.h"

TEST_CASE( "Tests for State class" ) {
    float hp = 200.0;
    float dmg = 20.0;

    State* state = new State(hp, dmg, "Unit");

    REQUIRE( state->getHP() == hp );
    REQUIRE( state->getHPLimit() == hp );
    REQUIRE( state->getDMG() == dmg );
    REQUIRE( state->getTitle() == "Unit" );
}

TEST_CASE( "State getDamage tests" ) {
    float hp = 200.0;
    float dmg = 20.0;

    State* state = new State(hp, dmg, "Unit");
    float tmp = hp;
    float damage = dmg;
    int iterations = tmp / damage;
    REQUIRE( state->getHP() == tmp );
    for ( int i = 0; i < iterations; i++ ) {
        REQUIRE( state->getHP() == tmp );
        state->takeDamage(damage);
        tmp -= damage;
    }
    REQUIRE( state->getHP() == 0 );
    try {
        state->takeDamage(damage);
    } catch (OutOfHPException) {
        REQUIRE( state->getHP() == 0 );
    }
    REQUIRE( state->getHP() == 0 );
}
TEST_CASE( "State increaseHP tests" ) {
    float hp = 200.0;
    float dmg = 20.0;

    State* state = new State(hp, dmg, "Unit");
    
    REQUIRE( state->getHP() == hp );
    state->takeDamage(50);
    REQUIRE( state->getHP() == (hp-50) );
    state->increaseHP(100);
    REQUIRE( state->getHP() == hp );
    state->takeDamage(50);
    REQUIRE( state->getHP() == (hp-50));
    state->increaseHP(30);
    REQUIRE( state->getHP() == (hp-20));
    state->increaseHP(20);
    REQUIRE( state->getHP() == hp);
}