<?php
    function arrayShiftLeft(&$array, $size) {
        $tmp = $array[0];

        for ( $i = 1; $i < $size; $i++ ) {
            $array[$i-1] = $array[$i];
        }
        $array[$size-1] = $tmp;
    }
?>