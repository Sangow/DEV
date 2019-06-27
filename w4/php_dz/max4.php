<?php
    $a = rtrim(fgets(STDIN));
    $b = rtrim(fgets(STDIN));
    $c = rtrim(fgets(STDIN));
    $d = rtrim(fgets(STDIN));

    $max = $a;

    if ( $max < $b ) {
        $max = $b;
    }
    if ( $max < $c ) {
        $max = $c;
    }
    if ( $max < $d ) {
        $max = $d;
    }
    
    echo $max . PHP_EOL;
?>