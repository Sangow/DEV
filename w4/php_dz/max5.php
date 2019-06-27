<?php 
    $b = rtrim(fgets(STDIN));
    $c = rtrim(fgets(STDIN));
    $d = rtrim(fgets(STDIN));
    $a = rtrim(fgets(STDIN));
    $e = rtrim(fgets(STDIN));

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