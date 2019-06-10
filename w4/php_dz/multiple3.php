<?php
    $STEP = 3;
    $max = rtrim(fgets(STDIN));
    $out = "";

    $max -= $max % $STEP;

    for ( $i = 0; $i < $max; $i += $STEP ) {
        $out .= $i . " ";
    }

    echo $out . $max . PHP_EOL;
?>