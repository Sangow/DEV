<?php
    function strRot13(&$str) {
        // $str = str_rot13($str);
        $cache = "balk";
        $out = "";

        for ( $i = 0; $i < 4; $i++ ) {
            $out .=  $cache[$i];
        }

        echo $out . PHP_EOL;
        // for ( $i = 0; isset($str[$i]); $i++, $cache = $str[$i] ) {
        //     if ( $cache > chr(64) && $cache < chr(91) ) {
        //         if ( $cache <= chr(77) ) {
        //             $str[$i] = $cache + 13;
        //         } else {
        //             $str[$i] = $cache - 13;
        //         }
        //     } else if ( $cache > chr(96) && $cache < chr(123) ) {
        //         if ( $cache <= chr(109) ) {
        //             $str[$i] = $cache + 13;
        //         } else {
        //             $str[$i] = $cache - 13;
        //         }
        //     }
        // }
    }

    $string = "balk.11.onyx..!!!.BAlk>OnyX.StyX";

    strRot13($string);

    echo $string . PHP_EOL;

    // echo chr(65);
?>