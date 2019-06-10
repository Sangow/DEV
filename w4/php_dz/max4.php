<?php
    $a = trim(fgets(STDIN));
    $b = trim(fgets(STDIN));
    $c = trim(fgets(STDIN));
    $d = trim(fgets(STDIN));

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