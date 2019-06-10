<?php
    $a = rtrim(fgets(STDIN));
    $b = rtrim(fgets(STDIN));
    $c = rtrim(fgets(STDIN));
    $max = $a;

    if ( $max < $b ) {
        $max = $b;
    } 
    if ( $max < $c ) {
        $max = $c;
    }

    echo $max . PHP_EOL;
?>