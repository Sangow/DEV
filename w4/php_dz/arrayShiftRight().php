<?php
    function arrayShiftRight(&$array, $size) {
        $last = $size - 1;
        $temp = $array[$last];

        for ( $i = $last; $i > 0; $i-- ) {
            $array[$i] = $array[$i-1];
        }
        $array[0] = $temp;
    }
?>