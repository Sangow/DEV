<?php
    function arrayShiftLeft(&$array, $size) {
        $tmp = $array[0];

        for ( $i = 1; $i < $size; $i++ ) {
            $array[$i-1] = $array[$i];
        }
        $array[$size-1] = $tmp;
    }

    $array = array( '0' => 1,
                    '1' => 2,
                    '2' => 3,
                    '3' => 4,
                    '4' => 5,
                    '5' => 6,
                    '6' => 7);

    arrayShiftLeft($array, 7);

    var_dump($array);
?>