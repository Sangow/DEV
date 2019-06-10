<?php
    function arraySearch(&$array, $size, $needle) {
        for ( $i = 0; $i < $size; $i++ ) {
            if ( $array[$i]  == $needle ) {
                return $i;
            }
        }
        return -1;
    }

    $array = array( '0' => 1,
                    '1' => 2,
                    '2' => 100,
                    '3' => -10,
                    '4' => 0,
                    '5' => 9);

    echo arraySearch($array, 6, 99) . PHP_EOL;
?>