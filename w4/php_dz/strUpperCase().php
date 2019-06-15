<?php
    function strUpperCase(&$str) {
        // $str = strtoupper($str);
        $cache = $str[0];

        var_dump($cache);

        for ( $i = 0; $i < strlen($str); $i++ ) {
            echo $i;
        //     if ( $cache > 96 && $cache < 123 ) {
        //         $str[$i] = $cache - 32;
        //     }
        }
    }

    $string = "qwer";

    strUpperCase($string);
    // echo $string . PHP_EOL;
?>