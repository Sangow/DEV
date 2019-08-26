#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../state/State.h"

TEST_CASE( "Tests for State class" ) {
    float hp = 200.0;

    State* state = new State(hp);

    REQUIRE( state->getHP() == hp );
    REQUIRE( state->getHPLimit() == hp );

    SECTION( "State takePhysDamage() tests" ) {
        float dmg = 10.0;
        float tmpHP = state->getHP();
        int iterations = tmpHP / dmg;
    
        REQUIRE( state->getHP() == tmpHP );
    
        for ( int i = 0; i < iterations; i++ ) {
            REQUIRE( state->getHP() == tmpHP );
            state->takePhysDamage(dmg);
            tmpHP -= dmg;
        }

        REQUIRE( state->getHP() == 0 );

        try {
            state->takePhysDamage(dmg);
        } catch (OutOfHPException) {
            REQUIRE( state->getHP() == 0 );
        }
            REQUIRE( state->getHP() == 0 );
    }

    SECTION( "State takeMagicDamage() test" ) {
        float tmpHP = state->getHP();
        float dmg = 10.0;
        int iterations = tmpHP / dmg;

        REQUIRE( state->getHP() == 200.0 );

        for ( int i = 0; i < iterations; i++ ) {
            REQUIRE( state->getHP() == tmpHP );
            state->takeMagicDamage(dmg);
            tmpHP -= dmg;
        }

        REQUIRE( state->getHP() == 0 );

        try {
            state->takeMagicDamage(dmg);
        } catch (OutOfHPException) {
            REQUIRE( state->getHP() == 0 );
        }
        REQUIRE( state->getHP() == 0 );
    }

    SECTION( "State increaseHP() test" ) {
        float hp = state->getHP();
        REQUIRE( state->getHP() == hp );

        state->takePhysDamage(50.0);
        REQUIRE( state->getHP() == (hp-50.0) );

        state->increaseHP(60.0);
        REQUIRE( state->getHP() == hp );

        state->takePhysDamage(100.0);
        REQUIRE( state->getHP() == (hp-100.0) );

        state->increaseHP(30.0);
        REQUIRE( state->getHP() == (hp-70.0) );

        state->takePhysDamage(130.0);
        REQUIRE( state->getHP() == 0 );

        try {
            state->increaseHP(hp);
        } catch (OutOfHPException) {
            REQUIRE( state->getHP() == 0 );
        }
        REQUIRE( state->getHP() == 0 );
    }
    // TEST_CASE( "State increaseHP tests" ) {
    // /   /         float hp = 200.0;
    // /   /         float dmg = 20.0;
    
    //         State* state = new State(hp, dmg, "Unit");
            
    //         REQUIRE( state->getHP() == hp );
    //         state->takeDamage(50);
    //         REQUIRE( state->getHP() == (hp-50) );
    //         state->increaseHP(100);
    //         REQUIRE( state->getHP() == hp );
    //         state->takeDamage(50);
    //         REQUIRE( state->getHP() == (hp-50));
    //         state->increaseHP(30);
    //         REQUIRE( state->getHP() == (hp-20));
//         state->increaseHP(20);
//     REQUIRE( state->getHP() == hp);
// }
}