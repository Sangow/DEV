<?php
    function arrayExchange(&$array, $len) {
        for ( $i = 0, $size = $len - $len / 2; $i < $size; $i += 2 ) {
            $tmp = $array[$i];

            $array[$i] = $array[$i+1];
            $array[$i+1] = $tmp;
        }
    }

    $array = array( '0' => 1,
                    '1' => 2,
                    '2' => 100,
                    '3' => -10,
                    '4' => 0,
                    '5' => 9,
                    '6' => 55);

    arrayExchange($array, 6);

    var_dump($array);
?>