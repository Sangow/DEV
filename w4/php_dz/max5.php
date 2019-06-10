<?php 
    $a = trim(fgets(STDIN));
    $b = trim(fgets(STDIN));
    $c = trim(fgets(STDIN));
    $d = trim(fgets(STDIN));
    $e = trim(fgets(STDIN));

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
    if ( $max < $e ) {
        $max = $e;
    }

    echo $max . PHP_EOL;

?>