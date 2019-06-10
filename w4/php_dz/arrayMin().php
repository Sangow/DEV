<?php
    function arrayMin(&$array, $size) {
    //     return min($array);
        $min = $array[0];

        // foreach ($array as $value) {
        //     if ( $min > $value ) {
        //         $min = $value;
        //     }
        // }

        for ( $i = 1; $i < $size; $i++ ) {
            if ( $min > $array[$i] ) {
                $min = $array[$i];
            }
        }
        return $min;
    }

    $array = array( '0' => 1,
                    '1' => 2,
                    '2' => 100,
                    '3' => -10,
                    '4' => 0,
                    '5' => 9);

    echo arrayMin($array, 6) . PHP_EOL;
?>