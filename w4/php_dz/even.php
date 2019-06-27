<?php
    $last = rtrim(fgets(STDIN));
    $out = "";
    
    $last -= $last % 2;
    
    for ( $i = 0; $i < $last; $i += 2 ) {
        $out .= $i . " ";
    }

    echo $out . $last . PHP_EOL;
?>