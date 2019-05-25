<?php
    $str = rtrim(fgets(STDIN));

    if ( strcmp($str, strrev($str)) == 0 ) {
        echo "Yes!". PHP_EOL;
    } else {
        echo "No!" . PHP_EOL;
    }
?>