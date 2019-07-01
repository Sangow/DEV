<?php
    function arrayExchange(&$array, $len) {
        for ( $i = 0, $size = $len - $len / 2; $i < $size; $i += 2 ) {
            $tmp = $array[$i];

            $array[$i] = $array[$i+1];
            $array[$i+1] = $tmp;
        }
    }
?>