<?php
    $max = rtrim(fgets(STDIN));
    $divisor = abs(rtrim(fgets(STDIN)));
    $out = "";

    $max -= $max % $divisor;

    for ( $i = 0; $i < $max; $i += $divisor ) {
        $out .= $i . " ";
    }

    echo $out . $max . PHP_EOL;
?>