#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../state/MagicState.h"

TEST_CASE( "Tests for MagicState" ) {
    float mana = 100.0;

    MagicState* ms = new MagicState(mana);

    REQUIRE( ms->getMana() == mana);
    REQUIRE( ms->getManaLimit() == mana);

    SECTION( "=== MagicState spendMana() test" ) {
        REQUIRE( ms->getMana() == mana);

        float tmp = mana;
        float cost = 9.0;
        int iterations = mana / cost;

        for ( int i = 0; i < iterations; i++ ) {
            REQUIRE( ms->getMana() == tmp );
            ms->spendMana(cost);
            tmp -= cost;
        }
        REQUIRE( ms->getMana() == 1.0 );

        try {
            ms->spendMana(cost);
        } catch (OutOfManaException) {
            REQUIRE( ms->getMana() == 1.0 );
        }
        REQUIRE( ms->getMana() == 1.0 );
    }

    SECTION( "" ) {
        
    }
}