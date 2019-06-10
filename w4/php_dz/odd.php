<?php
    $last = rtrim(fgets(STDIN));
    $out = "";
    
    if ( $last % 2 == 0 ) {
        $last -= 1;
    }

    for ( $i = 1; $i < $last; $i += 2 ) {
        $out .= $i . " ";
    }

    echo $out . $last . PHP_EOL;
?>