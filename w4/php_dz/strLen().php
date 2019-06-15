<?php
    if (!function_exists('strLen')) {
        function strLen($str) {
            $len = 0;

            for ( ; $str[$len] != ""; $len++);
            return $len;
        }
    }

    $string = "ololo";

    echo strLen($string) . PHP_EOL;
?>