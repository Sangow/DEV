<?php
    function arrayShiftRight(&$array, $size) {
        $last = $size - 1;
        $temp = $array[$last];

        for ( $i = $last; $i > 0; $i-- ) {
            $array[$i] = $array[$i-1];
        }
        $array[0] = $temp;
    }

    $array = array( '0' => 1,
                    '1' => 2,
                    '2' => 3,
                    '3' => 4,
                    '4' => 5,
                    '5' => 6,
                    '6' => 7);

    arrayShiftRight($array, 7);

    var_dump($array);
?>