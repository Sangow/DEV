<?php
    function arrayMax(&$array, $size) {
        // return max($array);
        $max = $array[0];
        
        // foreach ($array as $value) {
        //     if ( $max < $value ) {
        //         $max = $value;
        //     }
        // }

        for ( $i = 1; $i < $size; $i++ ) {
            if ( $max < $array[$i] ) {
                $max = $array[$i];
            }
        }
        return $max;
    }

    $array = array( '0' => 1,
                    '1' => 2,
                    '2' => 100,
                    '3' => -10,
                    '4' => 0,
                    '5' => 9);

    echo arrayMax($array, 6) . PHP_EOL;
?>