<?php
    function arrayReverse(&$array, $size) {
        // array_reverse($array);
        for ( $lo = 0, $hi = $size - 1; $lo < $hi; $lo++, $hi-- ) {
            $buffer = $array[$lo];

            $array[$lo] = $array[$hi];
            $array[$hi] = $buffer;
        }
    }

    $array = array( '0' => 1,
                    '1' => 2,
                    '2' => 3,
                    '3' => 4,
                    '4' => 5,
                    '5' => 6,
                    '6' => 7);

    arrayReverse($array, 7);

    var_dump($array);
?>